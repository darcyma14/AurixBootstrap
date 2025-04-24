#include "Incl.h"

#define FLASH_SIZE                  (0x100000) /* 1 MByte */
#define FLASH_IMAGE_SIZE            (uint32_t)(FLASH_SIZE-(ApplicationAddress-0x08000000))

static uint8_t s_grgucFileName[FILE_NAME_LENGTH];
static uint32_t s_gxFlashDestination = ApplicationAddress; /* Flash user program offset */
static const struct
{
        uint32_t ulPFlashSectorOffset;
        uint8_t ucIsEoB;
} s_srgxPFlashStruct[FLSLOADER_NUM_OF_PF0_SECTORS] =
{
    { FLSLOADER_PF_S0, FALSE },
    { FLSLOADER_PF_S1, FALSE },
    { FLSLOADER_PF_S2, FALSE },
    { FLSLOADER_PF_S3, FALSE },
    { FLSLOADER_PF_S4, FALSE },
    { FLSLOADER_PF_S5, FALSE },
    { FLSLOADER_PF_S6, FALSE },
    { FLSLOADER_PF_S7, TRUE },
    { FLSLOADER_PF_S8, FALSE },
    { FLSLOADER_PF_S9, FALSE },
    { FLSLOADER_PF_S10, FALSE },
    { FLSLOADER_PF_S11, FALSE },
    { FLSLOADER_PF_S12, FALSE },
    { FLSLOADER_PF_S13, FALSE },
    { FLSLOADER_PF_S14, FALSE },
    { FLSLOADER_PF_S15, TRUE },
    { FLSLOADER_PF_S16, FALSE },
    { FLSLOADER_PF_S17, TRUE },
    { FLSLOADER_PF_S18, FALSE },
    { FLSLOADER_PF_S19, TRUE },
    { FLSLOADER_PF_S20, FALSE },
    { FLSLOADER_PF_S21, FALSE },
    { FLSLOADER_PF_S22, TRUE },
    { FLSLOADER_PF_S23, FALSE },
    { FLSLOADER_PF_S24, TRUE },
    { FLSLOADER_PF_S25, FALSE },
    { FLSLOADER_PF_S26, TRUE }
};

static BaseType_t prvReceiveByte(uint8_t *pChar, BaseType_t xTimeout);
static BaseType_t prvSendByte(uint8_t cChar);
static BaseType_t prvReceivePacket(uint8_t *pData, BaseType_t *pxLength, BaseType_t xTimeout);
static uint16_t prvUpdateCRC16(uint16_t unCrcIn, uint8_t ucByte);
static uint16_t prvCalCrc16(const uint8_t *pucData, uint32_t ulSize);
static uint8_t prvCalChecksum(const uint8_t *pucData, uint32_t ulSize);
static uint32_t prvFlashPageMask(uint32_t ulTargetAddr, BaseType_t xSize, BaseType_t *pxNoOfSectors);

static BaseType_t prvGetByte(uint8_t *pucChar)
{
#define ASCLIN1_BASE    (0xF0000700U)

    static volatile Ifx_ASCLIN *psASCLIN0;
    psASCLIN0 = (volatile Ifx_ASCLIN *)ASCLIN1_BASE;

    if (psASCLIN0->RXFIFOCON.B.FILL != 0) {
        *pucChar = (char)psASCLIN0->RXDATA.U;
        psASCLIN0->FLAGSCLEAR.U = (0xFFFFFffFU);
        return 0;
    }
    else
        return -1;
}
/*-----------------------------------------------------------*/

static BaseType_t prvReceiveByte(uint8_t *pChar, BaseType_t xTimeout)
{
    while (xTimeout-- > 0) {
        if (prvGetByte(pChar) != -1)
            return 0;
    }
    return -1;
}
/*-----------------------------------------------------------*/

static BaseType_t prvSendByte(uint8_t cChar)
{
    BaseType_t xTimeout = 0xFFFFF;

    Uart_Write(0, (Uart_MemPtrType)&cChar, (Uart_SizeType)1);
    while ((Uart_GetStatus(0) == UART_BUSY) && xTimeout--);

    return 0;
}
/*-----------------------------------------------------------*/

static BaseType_t prvReceivePacket(uint8_t *pData, BaseType_t *pxLength, BaseType_t xTimeout)
{
    register int i;
    BaseType_t xPacketSize;
    uint8_t cChar;

    *pxLength = 0;
    if (prvReceiveByte(&cChar, xTimeout) != 0)
        return -1;

    switch (cChar)
    {
    case SOH:
        xPacketSize = PACKET_SIZE;
        break;
    case STX:
        xPacketSize = PACKET_1K_SIZE;
        break;
    case EOT:
        return 0;
    case CA:
        if ((prvReceiveByte(&cChar, xTimeout) == 0) && (cChar == CA)) {
            *pxLength = -1;
            return 0;
        }
        return -1;
    case ABORT1:
    case ABORT2:
        return 1;
    default:
        return -1;
    }
    *pData = cChar;

    for (i=1; i<(xPacketSize+PACKET_OVERHEAD); i++) {
        if (prvReceiveByte(pData+i, xTimeout) != 0)
            return -1;
    }

    if (pData[PACKET_SEQNO_INDEX] != ((pData[PACKET_SEQNO_COMP_INDEX] ^ 0xFF) & 0xFF))
        return -1;
    *pxLength = xPacketSize;

    return 0;
}
/*-----------------------------------------------------------*/

static uint16_t prvUpdateCRC16(uint16_t unCrcIn, uint8_t ucByte)
{
    uint32_t ulCrc = unCrcIn;
    uint32_t ulIn = ucByte | 0x100;
    do {
        ulCrc <<= 1;
        ulIn <<= 1;

        if (ulIn & 0x100)
            ++ulCrc;

        if (ulCrc & 0x10000)
            ulCrc ^= 0x1021;
    } while(!(ulIn & 0x10000));

    return (ulCrc & 0xFFFF);
}
/*-----------------------------------------------------------*/

static uint16_t prvCalCrc16(const uint8_t *pucData, uint32_t ulSize)
{
    uint32_t ulCrc = 0;
    const uint8_t *pucDatEend = pucData + ulSize;

    while (pucData < pucDatEend)
        ulCrc = (uint32_t)prvUpdateCRC16((uint16_t)ulCrc, *pucData++);

    ulCrc = (uint32_t)prvUpdateCRC16((uint16_t)ulCrc, 0);
    ulCrc = (uint32_t)prvUpdateCRC16((uint16_t)ulCrc, 0);
    return (ulCrc&0xFFFF);
}
/*-----------------------------------------------------------*/

static uint8_t prvCalChecksum(const uint8_t *pucData, uint32_t ulSize)
{
    uint32_t ulSum = 0;
    const uint8_t *pucDataEnd = pucData + ulSize;
    while (pucData < pucDataEnd)
        ulSum += *pucData++;
    return (ulSum & 0xFF);
}
/*-----------------------------------------------------------*/

static uint32_t prvFlashPageMask(uint32_t ulTargetAddr, BaseType_t xSize, BaseType_t *pxNoOfSectors)
{
    register int i;
    uint32_t ulOffSet;
    uint32_t ulOffSet1;
    uint32_t ulSectorNumber;
    uint32_t ulSectorNumber1;
    uint32_t ulNoOfSectors;

    ulOffSet = ulTargetAddr - FLSLOADER_PFLASH0_START_ADDRESS;
    for (ulSectorNumber = 0U; ulSectorNumber < FLSLOADER_NUM_OF_PF0_SECTORS; ulSectorNumber++) {
        if (ulOffSet < s_srgxPFlashStruct[ulSectorNumber].ulPFlashSectorOffset)
            break;
    }
    ulSectorNumber--;
    ulOffSet1 = (ulTargetAddr + xSize) - FLSLOADER_PFLASH0_START_ADDRESS;
    for (ulSectorNumber1 = 0U; ulSectorNumber1 < FLSLOADER_NUM_OF_PF0_SECTORS; ulSectorNumber1++) {
        if (ulOffSet1 < s_srgxPFlashStruct[ulSectorNumber1].ulPFlashSectorOffset)
            break;
    }

    ulNoOfSectors = ulSectorNumber1 - ulSectorNumber;

    for (i=0; i<ulNoOfSectors; i++) {
        if (s_srgxPFlashStruct[(i + ulSectorNumber)].ucIsEoB == TRUE) {
            i++;
            break;
        }
    }

    *pxNoOfSectors = i;

    if (i == ulNoOfSectors)
        return 0;
    return (xSize - (s_srgxPFlashStruct[(ulSectorNumber + i)].ulPFlashSectorOffset - (ulTargetAddr - FLSLOADER_PFLASH0_START_ADDRESS)));
}
/*-----------------------------------------------------------*/

uint8_t* pYmodemGetFileName(void)
{
    return s_grgucFileName;
}
/*-----------------------------------------------------------*/

BaseType_t xYmodemReceive(uint8_t *pBuf)
{
    uint8_t rgucPacketData[PACKET_1K_SIZE + PACKET_OVERHEAD];
    uint8_t rgucFileSize[FILE_SIZE_LENGTH];
    uint8_t *pxFilePtr;
    uint8_t *pBufPtr;
    register int i;
    BaseType_t xPacketLength;
    BaseType_t xSessionDone;
    BaseType_t xFileDone;
    BaseType_t xPacketsReceived;
    BaseType_t xErrors;
    BaseType_t xSeesionBegin;
    BaseType_t xSize = 0;
    BaseType_t xNbrOfPage;

    BaseType_t xRemain;
    BaseType_t xNewAddress = ApplicationAddress;

    /* Initialize FlashDestination variable */
    s_gxFlashDestination = ApplicationAddress;

    for (xSessionDone = 0, xErrors = 0, xSeesionBegin = 0; ;) {
        for (xPacketsReceived = 0, xFileDone = 0, pBufPtr = pBuf; ;) {
            switch (prvReceivePacket(rgucPacketData, &xPacketLength, NAK_TIMEOUT)) {
            case 0:
                xErrors = 0;
                switch (xPacketLength) {
                /* Abort by sender */
                case -1:
                    prvSendByte(ACK);
                    return 0;
                /* End of transmission */
                case 0:
                    prvSendByte(ACK);
                    xFileDone = 1;
                    break;
                /* Normal packet */
                default:
                    if ((rgucPacketData[PACKET_SEQNO_INDEX] & 0xFF) != (xPacketsReceived & 0xFF))
                        prvSendByte(NAK);
                    else {
                        if (xPacketsReceived == 0) {
                            /* Filename packet */
                            if (rgucPacketData[PACKET_HEADER] != 0) {
                                /* Filename packet has valid data */
                                for (i=0, pxFilePtr=rgucPacketData+PACKET_HEADER; (*pxFilePtr != 0) && (i < FILE_NAME_LENGTH); )
                                    s_grgucFileName[i++] = *pxFilePtr++;

                                s_grgucFileName[i++] = '\0';

                                for (i=0, pxFilePtr++; (*pxFilePtr != ' ') && (i < FILE_SIZE_LENGTH); )
                                    rgucFileSize[i++] = *pxFilePtr++;

                                rgucFileSize[i++] = '\0';

                                Str2Int(rgucFileSize, (int *)&xSize);

                                /* Test the size of the image to be sent */
                                /* Image size is greater than Flash size */
                                if (xSize > (FLASH_SIZE - 1))
                                {
                                    /* End session */
                                    prvSendByte(CA);
                                    prvSendByte(CA);
                                    return -1;
                                }

                                xNewAddress = s_gxFlashDestination;
                                do {
                                    xRemain = prvFlashPageMask(xNewAddress, xSize, &xNbrOfPage);

                                    if ((xErrors = FlsLoader_Erase((uint32)xNewAddress, xNbrOfPage)) != 0)
                                        break;

                                    xNewAddress += (xSize - xRemain);
                                    xSize = xRemain;

                                } while(xRemain > 0);

                                if (xErrors != FLSLOADER_E_OK) {
                                    /* End session */
                                    prvSendByte(CA);
                                    prvSendByte(CA);
                                    return -2;
                                }
                                prvSendByte(ACK);
                                prvSendByte(CRC16);
                            } /* if( rgucPacketData[ PACKET_HEADER ] != 0 ) */
                            /* Filename packet is empty, end session */
                            else {
                                prvSendByte(ACK);
                                xFileDone = 1;
                                xSessionDone = 1;
                                break;
                            }
                        } /* if( xPacketsReceived == 0 ) */
                        /* Data packet */
                        else {
                            memcpy(pBufPtr, rgucPacketData + PACKET_HEADER, xPacketLength);
                            xErrors = FlsLoader_Write(s_gxFlashDestination, (uint32_t) xPacketLength, (uint8_t *)pBufPtr);
                            if (xErrors != FLSLOADER_E_OK) {
                                /* End session */
                                prvSendByte(CA);
                                prvSendByte(CA);
                                return -2;
                            }

                            s_gxFlashDestination += xPacketLength;
                            prvSendByte(ACK);
                        }
                        xPacketsReceived++;
                        xSeesionBegin = 1;
                    }
                }
                break;
            case 1:
                prvSendByte(CA);
                prvSendByte(CA);
                return -3;
            default:
                if (xSeesionBegin > 0)
                    xErrors++;

                if (xErrors > MAX_ERRORS) {
                    prvSendByte(CA);
                    prvSendByte(CA);
                    return 0;
                }
                prvSendByte(CRC16);
                break;
            }

            if (xFileDone != 0)
                break;
        }

        if (xSessionDone != 0)
            break;
    }

    return xSize;
}
/*-----------------------------------------------------------*/

BaseType_t xYmodemCheckResponse(uint8_t ucChar)
{
    return 0;
}
/*-----------------------------------------------------------*/

void vYmodemPrepareInitialPacket(uint8_t *pucData, const uint8_t *pucFileName, BaseType_t *pxLength)
{
    register int i;
    register int j;
    uint8_t rgucFilePtr[10];

    pucData[0] = SOH;
    pucData[1] = 0x00;
    pucData[2] = 0xFF;

    /* Filename packet has valid data */
    for (i=0; (pucFileName[i] != '\0') && (i<FILE_NAME_LENGTH); i++)
        pucData[i + PACKET_HEADER] = pucFileName[i];

    pucData[i + PACKET_HEADER] = 0x00;

    Int2Str(rgucFilePtr, (int)*pxLength);
    for (j =0, i = i + PACKET_HEADER + 1; rgucFilePtr[j] != '\0' ; )
        pucData[i++] = rgucFilePtr[j++];

    for (j=i; j<PACKET_SIZE + PACKET_HEADER; j++)
        pucData[j] = 0;
}
/*-----------------------------------------------------------*/

void vYmodemPreparePacket(uint8_t *pucSourceBuf, uint8_t *pudData, uint8_t ucPktNo, uint32_t ulSizeBlk)
{
    register int i;
    BaseType_t xSize;
    BaseType_t xPacketSize;
    uint8_t *pucFileptr;

    /* Make first three packet */
    xPacketSize = ulSizeBlk >= PACKET_1K_SIZE ? PACKET_1K_SIZE : PACKET_SIZE;
    xSize = ulSizeBlk < xPacketSize ? ulSizeBlk : xPacketSize;

    if (xPacketSize == PACKET_1K_SIZE)
        pudData[0] = STX;
    else
        pudData[0] = SOH;

    pudData[1] = ucPktNo;
    pudData[2] = ~ucPktNo;
    pucFileptr = pucSourceBuf;

    /* Filename packet has valid data */
    for (i=PACKET_HEADER; i<xSize + PACKET_HEADER; i++)
        pudData[i] = *pucFileptr++;

    if (xSize  <= xPacketSize) {
        for (i=xSize + PACKET_HEADER; i<xPacketSize + PACKET_HEADER; i++)
            pudData[i] = 0x1A; /* EOF (0x1A) or 0x00 */
    }
}
/*-----------------------------------------------------------*/

void vYmodemSendPacket(uint8_t *pucData, uint16_t uLength)
{
    register int i;

    i = 0;
    while (i < uLength) {
        prvSendByte(pucData[i]);
        i++;
    }
}
/*-----------------------------------------------------------*/

uint8_t ucYmodemTransmit(uint8_t *pucBuf, const uint8_t *pucSendFileName, uint32_t ulSizeFile)
{
    register int i;
    uint8_t rgucPacketData[PACKET_1K_SIZE + PACKET_OVERHEAD];
    uint8_t rgucFileName[FILE_NAME_LENGTH];
    uint8_t *pucBufPtr;
    uint8_t ucTempCheckSum;
    uint16_t unTempCrc;
    uint16_t unBlkNumber;
    uint8_t rgucReceivedC[2];
    uint8_t ucCRC16_F = 0;
    uint32_t ulErrors;
    uint32_t ulAckReceived;
    uint32_t ulSize= 0;
    uint32_t ulPktSize;

    ulErrors = 0;
    ulAckReceived = 0;

    for (i=0; i<(FILE_NAME_LENGTH - 1); i++)
        rgucFileName[i] = pucSendFileName[i];
    ucCRC16_F = 1;

    /* Prepare first block */
    vYmodemPrepareInitialPacket(&rgucPacketData[0], rgucFileName, (BaseType_t *)&ulSizeFile);

    do {
        /* Send Packet */
        vYmodemSendPacket(rgucPacketData, PACKET_SIZE + PACKET_HEADER);
        /* Send CRC or Check Sum based on CRC16_F */
        if (ucCRC16_F) {
            unTempCrc = prvCalCrc16(&rgucPacketData[3], PACKET_SIZE);
            prvSendByte(unTempCrc >> 8);
            prvSendByte(unTempCrc & 0xFF);
        }
        else {
            ucTempCheckSum = prvCalChecksum(&rgucPacketData[3], PACKET_SIZE);
            prvSendByte(ucTempCheckSum);
        }

        /* Wait for Ack and 'C' */
        if (prvReceiveByte(&rgucReceivedC[0], 10000) == 0) {
            if (rgucReceivedC[0] == ACK)
                /* Packet transfered correctly */
                ulAckReceived = 1;
        }
        else
            ulErrors++;
    } while(!ulAckReceived && (ulErrors < 0x0A));

    if (ulErrors >=  0x0A)
        return (uint8_t)ulErrors;

    pucBufPtr = pucBuf;
    ulSize = ulSizeFile;
    unBlkNumber = 0x01;
    /* Here 1024 bytes package is used to send the packets */


    /* Resend packet if NAK  for a count of 10 else end of commuincation */
    while (ulSize) {
        /* Prepare next packet */
        vYmodemPreparePacket(pucBufPtr, &rgucPacketData[0], (uint8_t)unBlkNumber, ulSize);
        ulAckReceived = 0;
        rgucReceivedC[0]= 0;
        ulErrors = 0;
        do {
            /* Send next packet */
            if (ulSize >= PACKET_1K_SIZE)
                ulPktSize = PACKET_1K_SIZE;
            else
                ulPktSize = PACKET_SIZE;

            vYmodemSendPacket(rgucPacketData, ulPktSize + PACKET_HEADER);
            /* Send CRC or Check Sum based on CRC16_F */
            /* Send CRC or Check Sum based on CRC16_F */
            if (ucCRC16_F) {
                unTempCrc = prvCalCrc16(&rgucPacketData[3], ulPktSize);
                prvSendByte(unTempCrc >> 8);
                prvSendByte(unTempCrc & 0xFF);
            }
            else {
                ucTempCheckSum = prvCalChecksum (&rgucPacketData[3], ulPktSize);
                prvSendByte(ucTempCheckSum);
            }

            /* Wait for Ack */
            if ((prvReceiveByte(&rgucReceivedC[0], 100000) == 0)  && (rgucReceivedC[0] == ACK)) {
                ulAckReceived = 1;
                if (ulSize > ulPktSize) {
                    pucBufPtr += ulPktSize;
                    ulSize -= ulPktSize;
                    if (unBlkNumber == (FLASH_IMAGE_SIZE / 1024))
                        return 0xFF; /*  error */
                    else
                        unBlkNumber++;
                }
                else {
                    pucBufPtr += ulPktSize;
                    ulSize = 0;
                }
            }
            else
                ulErrors++;
        } while(!ulAckReceived && (ulErrors < 0x0A));
        /* Resend packet if NAK  for a count of 10 else end of commuincation */

        if (ulErrors >=  0x0A)
            return (uint8_t)ulErrors;
    }

    ulAckReceived = 0;
    rgucReceivedC[0] = 0x00;
    ulErrors = 0;
    do {
        prvSendByte(EOT);
        /* Send (EOT); */
        /* Wait for Ack */
        if ((prvReceiveByte(&rgucReceivedC[0], 10000) == 0)  && rgucReceivedC[0] == ACK)
            ulAckReceived = 1;
        else
            ulErrors++;
    } while(!ulAckReceived && (ulErrors < 0x0A));

    if (ulErrors >=  0x0A)
        return (uint8_t)ulErrors;

    /* Last packet preparation */
    ulAckReceived = 0;
    rgucReceivedC[0] = 0x00;
    ulErrors = 0;

    rgucPacketData[0] = SOH;
    rgucPacketData[1] = 0;
    rgucPacketData[2] = 0xFF;

    for (i=PACKET_HEADER; i<(PACKET_SIZE + PACKET_HEADER); i++)
        rgucPacketData[i] = 0x00;

    do {
    /* Send Packet */
        vYmodemSendPacket(rgucPacketData, PACKET_SIZE + PACKET_HEADER);
        /* Send CRC or Check Sum based on CRC16_F */
        unTempCrc = prvCalCrc16(&rgucPacketData[3], PACKET_SIZE);
        prvSendByte(unTempCrc >> 8);
        prvSendByte(unTempCrc & 0xFF);

        /* Wait for Ack and 'C' */
        if (prvReceiveByte(&rgucReceivedC[0], 10000) == 0) {
            if (rgucReceivedC[0] == ACK) {
                /* Packet transfered correctly */
                ulAckReceived = 1;
            }
        }
        else
            ulErrors++;

    } while(!ulAckReceived && (ulErrors < 0x0A));

    /* Resend packet if NAK  for a count of 10  else end of commuincation */
    if (ulErrors >=  0x0A)
        return (uint8_t)ulErrors;

    do {
        prvSendByte(EOT);
        /* Send (EOT); */
        /* Wait for Ack */
        if ((prvReceiveByte(&rgucReceivedC[0], 10000) == 0)  && rgucReceivedC[0] == ACK)
            ulAckReceived = 1;
        else
            ulErrors++;
    } while(!ulAckReceived && (ulErrors < 0x0A));

    if (ulErrors >=  0x0A)
        return (uint8_t)ulErrors;

    return 0; /* file transmitted successfully */
}
/*-----------------------------------------------------------*/
