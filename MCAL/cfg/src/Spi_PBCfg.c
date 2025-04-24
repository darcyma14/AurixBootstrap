/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\84 $                                                 **
**                                                                            **
**  DATE, TIME: 2022-10-01, 16:07:46                                         **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SPI configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include SPI Module File */
/* [cover parentID=DS_NAS_SPI_PR699,DS_NAS_SPI_PR709] */

#include "Spi.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't
   be avoided as it is required for mapping global variables, constants
   and code
*/
/* Violates MISRA Required Rule 16.9,
            function identifier used without '&' or parenthisized parameter list
           when using function pointer in configurations
*/

/*
                     Container: SpiChannelConfiguration
*/
#define SPI_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
/*
Configuration : Channel Configuration Constant Structure.
The IB Channels are configured first followed by EB.
*/
static const Spi_ChannelConfigType Spi_kChannelConfig0[] =
{
/* EB Channel: SpiChannel_HSD Configuration */
    {
        /* Default Data, SPI_DEFAULT_DATA */
        ( uint32 )0x00000000U,
        /* Data Configuration */
        Spi_DataConfig( 8U, /* Data Width */
                        SPI_DATA_MSB_FIRST ), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
        ( Spi_NumberOfDataType ) 511U,
        /* Buffer Type, SPI_CHANNEL_TYPE */
        ( uint8 ) SPI_EB_BUFFER,
    },
};

/*
                    Container: SpiJobConfiguration
*/
/* Notification Function of SpiJob_HSD is NULL_PTR */
/* Notification Function of SpiJob_LSD1 is NULL_PTR */
/* Notification Function of SpiJob_LSD2 is NULL_PTR */
/* Notification Function of SpiJob_CAN1 is NULL_PTR */
/* Notification Function of SpiJob_CAN2 is NULL_PTR */
/* Notification Function of SpiJob_PMIC is NULL_PTR */


/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_HSD*/
static const Spi_ChannelType SpiJob_HSD_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_LSD1*/
static const Spi_ChannelType SpiJob_LSD1_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_LSD2*/
static const Spi_ChannelType SpiJob_LSD2_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_CAN1*/
static const Spi_ChannelType SpiJob_CAN1_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_CAN2*/
static const Spi_ChannelType SpiJob_CAN2_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJob_PMIC*/
static const Spi_ChannelType SpiJob_PMIC_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};

#ifdef TC234_KIT_BOARD
static const Spi_ChannelType SpiJob_E2PROM_ChannelLinkPtr[] =
{
    SpiConf_SpiChannel_SpiChannel_HSD,
    SPI_CHANNEL_LINK_DELIMITER
};
#endif

/*
Configuration: Job Configuration Constant Structure.
*/
static const Spi_JobConfigType Spi_kJobConfig0[] =
{

    /* Job: SpiJob_HSD Configuration */
    {   /* VN9D30Q100F */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
        SpiJob_HSD_ChannelLinkPtr,
        /* Baud Rate (4000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x0U ), /*Q*/( 0x4U ), /*A*/( 0x0U ), /*B*/( 0x1U ), /*C*/( 0x3U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U, /*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        SPI_CS_HW, /* Hw CS Pin is Selected */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_TRAIL ),
        /* Job Priority escalated to Maximum as it is mapped to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 )( ( uint8 ) SPI_QSPI_CHANNEL2 << 4U ) | ( SPI_QSPI0_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        (uint8) SPI_QSPI_PARITY_UNUSED,
    
    },
    /* Job: SpiJob_LSD1 Configuration */
    {   /* TLE8110ED U11 */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
        SpiJob_LSD1_ChannelLinkPtr,
        /* Baud Rate (4000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x0U ), /*Q*/( 0x4U ), /*A*/( 0x0U ), /*B*/( 0x1U ), /*C*/( 0x3U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U, /*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        SPI_CS_HW, /* Hw CS Pin is Selected */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_LEAD ),
        /* Job Priority escalated to Maximum as it is mapped
        to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL13 << 4U ) | ( SPI_QSPI0_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        ( uint8 ) SPI_QSPI_PARITY_UNUSED,
    },
    /* Job: SpiJob_LSD2 Configuration */
    {   /* TLE8110ED U12 */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
        SpiJob_LSD2_ChannelLinkPtr,
        /* Baud Rate (4000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x0U ), /*Q*/( 0x4U ), /*A*/( 0x0U ), /*B*/( 0x1U ), /*C*/( 0x3U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U,/*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        ( uint16 ) Spi_CsGpioPortPin( 11U, 2U ), /* Gpio CS Port/Pin  */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_LEAD ),
        /* Job Priority escalated to Maximum as it is mapped
            to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL0 << 4U ) | ( SPI_QSPI0_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        ( uint8 ) SPI_QSPI_PARITY_UNUSED,
    },
    /* Job: SpiJob_CAN1 Configuration */
    {   /* TLT9255WLC U2 */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
        SpiJob_CAN1_ChannelLinkPtr,
        /* Baud Rate (2000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x0U ), /*Q*/( 0x4U ), /*A*/( 0x3U ), /*B*/( 0x3U ), /*C*/( 0x3U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U,/*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        SPI_CS_HW, /* Hw CS Pin is Selected */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_LEAD ),
        /* Job Priority escalated to Maximum as it is mapped
            to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 )( ( uint8 ) SPI_QSPI_CHANNEL3 << 4U ) | ( SPI_QSPI1_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        ( uint8 ) SPI_QSPI_PARITY_UNUSED,
    },
    /* Job: SpiJob_CAN2 Configuration */
    {   /* TLT9255WLC U3 */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
        SpiJob_CAN2_ChannelLinkPtr,
        /* Baud Rate (2000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x0U ), /*Q*/( 0x4U ), /*A*/( 0x3U ), /*B*/( 0x3U ), /*C*/( 0x3U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U,/*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        SPI_CS_HW, /* Hw CS Pin is Selected */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_LEAD ),
        /* Job Priority escalated to Maximum as it is mapped
            to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 )( ( uint8 ) SPI_QSPI_CHANNEL10 << 4U ) | ( SPI_QSPI1_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        ( uint8 )SPI_QSPI_PARITY_UNUSED,
    },
    /* Job: SpiJob_PMIC Configuration */
    {   /* TLF35584QVVS2 */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
        SpiJob_PMIC_ChannelLinkPtr,
        /* Baud Rate (4000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x0U ), /*Q*/( 0x4U ), /*A*/( 0x0U ), /*B*/( 0x1U ), /*C*/( 0x3U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U,/*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        SPI_CS_HW, /* Hw CS Pin is Selected */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_TRAIL ),
        /* Job Priority escalated to Maximum as it is mapped to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL4 << 4U ) | ( SPI_QSPI1_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        ( uint8 ) SPI_QSPI_PARITY_UNUSED,
    }
#ifdef TC234_KIT_BOARD
    /* Job: SpiJob_E2PROM Configuration */
    ,{   /* AT25128N-10SI2.7 */
        /* Job End Notification: Spi_JobEndNotification, SPI118 */
        NULL_PTR,
        /* User given name outside the naming convention */
        /* Spi_ChannelLinkPtr */
		SpiJob_E2PROM_ChannelLinkPtr,
        /* Baud Rate (4000000 Hz) Hw configuration Parameters */
        Spi_BaudRateParams( /*TQ*/( 0x2U ), /*Q*/( 0x4U ), /*A*/( 0x1U ), /*B*/( 0x1U ), /*C*/( 0x2U ) ),
        /* Time Delay Configuration */
        ( uint32 ) Spi_DelayParams( /*IPRE*/0x00U,/*IDLE*/ 0x00U, /*LPRE*/0x01U, /*LEAD*/0x04U, /*TPRE*/0x01U, /*TRAIL*/0x04U ),
        SPI_CS_HW, /* Hw CS Pin is Selected */
        /*CS Active level Polarity*/
        SPI_CS_POLARITY_LOW,
        /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL, Clock Phase: SPI_DATA_SHIFT_EDGE */
        Spi_ShiftClkConfig( SPI_CLK_IDLE_LOW, SPI_DATA_SHIFT_TRAIL ),
        /* Job Priority escalated to Maximum as it is mapped to one or more non-interruptible sequence */
        SPI_JOB_PRIORITY_3,
        /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL7 << 4U ) | ( SPI_QSPI0_INDEX ),
        /* Channel Based Chip Select */
        ( uint8 ) 0U,
        /* Spi Parity Selection */
        ( uint8 ) SPI_QSPI_PARITY_UNUSED,
    }
#endif   
};

/*
                     Container: Spi_SequenceConfiguration
*/
/* Notification Function of Sequence: SpiSequence_HSD */
extern void HSD_EndOfCmdSeqNotification(void);
/* Notification Function of Sequence: SpiSequence_LSD1 */
extern void LSD1_EndOfCmdSeqNotification(void);
/* Notification Function of Sequence: SpiSequence_LSD2 */
extern void LSD2_EndOfCmdSeqNotification(void);
/* Notification Function of Sequence: SpiSequence_CAN1 */
extern void CAN1_EndOfCmdSeqNotification(void);
/* Notification Function of Sequence: SpiSequence_CAN2 */
extern void CAN2_EndOfCmdSeqNotification(void);
/* Notification Function of Sequence: SpiSequence_PMIC */
extern void PMIC_EndOfCmdSeqNotification(void);
#ifdef TC234_KIT_BOARD
extern void vAT25EndOfCmdSeqNotification( void );
#endif

/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_HSD */
static const Spi_JobType SpiSequence_HSD_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_HSD,
    SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_LSD1 */
static const Spi_JobType SpiSequence_LSD1_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_LSD1,
    SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_LSD2 */
static const Spi_JobType SpiSequence_LSD2_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_LSD2,
    SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_CAN1 */
static const Spi_JobType SpiSequence_CAN1_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_CAN1,
    SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_CAN2 */
static const Spi_JobType SpiSequence_CAN2_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_CAN2,
    SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequence_PMIC */
static const Spi_JobType SpiSequence_PMIC_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_PMIC,
    SPI_JOB_LINK_DELIMITER
};

#ifdef TC234_KIT_BOARD
static const Spi_JobType SpiSequence_E2PROM_JobLinkPtr[] =
{
    SpiConf_SpiJob_SpiJob_E2PROM,
    SPI_JOB_LINK_DELIMITER
};
#endif

/*
Configuration: Sequence Configuration Constant Structure.
*/
static const Spi_SequenceConfigType Spi_kSequenceConfig0[] =
{   
    /* Sequence: SpiSequence_HSD Configuration */
    {
        /* Spi_SeqEndNotification */
        &HSD_EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_HSD_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,
    },
    /* Sequence: SpiSequence_LSD1 Configuration */
    {
        /* Spi_SeqEndNotification */
        &LSD1_EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_LSD1_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,
    },
    /* Sequence: SpiSequence_LSD2 Configuration */
    {
        /* Spi_SeqEndNotification */
        &LSD2_EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_LSD2_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,
    },
    /* Sequence: SpiSequence_CAN1 Configuration */
    {
        /* Spi_SeqEndNotification */
        &CAN1_EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_CAN1_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,
    },
    /* Sequence: SpiSequence_CAN2 Configuration */
    {
        /* Spi_SeqEndNotification */
        &CAN2_EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_CAN2_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,
    },
    /* Sequence: SpiSequence_PMIC Configuration */
    {
        /* Spi_SeqEndNotification */
        &PMIC_EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_PMIC_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,
    }
#ifdef TC234_KIT_BOARD
    /* Sequence: SpiSequence_E2PROM Configuration */
    ,{
         /* Spi_SeqEndNotification */
        &vAT25EndOfCmdSeqNotification,
        /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
        SpiSequence_E2PROM_JobLinkPtr,
        /* User given name outside the naming convention */
        /* Sequences that share jobs with this sequence */
        NULL_PTR,
        /* This holds the total number of jobs linked to this sequence */
        1U,       
    }
#endif    
};

static const Spi_DmaConfigType Spi_kDmaConfig0[]=
{
    {   
        /* QSPI0 Module Hw Dma Config */
        DMA_CHANNEL2,  /* Tx */    
        DMA_CHANNEL1   /* Rx */  
    },
    { 
        /* QSPI1 Module Hw Dma Config */
        DMA_CHANNEL4,  /* Tx */    
        DMA_CHANNEL3   /* Rx */  
    },
    { 
        /* QSPI2 Module Hw Dma Config */
        DMA_CHANNEL_INVALID,  /* Tx */    
        DMA_CHANNEL_INVALID   /* Rx */  
    },
    { 
        /* QSPI3 Module Hw Dma Config */
        DMA_CHANNEL_INVALID,  /* Tx */    
        DMA_CHANNEL_INVALID   /* Rx */  
    },
};

static const Spi_HWModuleConfigType Spi_kModuleConfig0[]=
{
    /* QSPI0 Module */
    {
        /*Clock Settings:Sleep Control Disabled*/
        SPI_CLK_SLEEP_DISABLE,
        SPI_QSPI0_MRIS_SEL,
        &Spi_kDmaConfig0[ 0U ],
    },
    /* QSPI1 Module */
    {
        /*Clock Settings:Sleep Control Disabled*/
        SPI_CLK_SLEEP_DISABLE,
        SPI_QSPI1_MRIS_SEL,
        &Spi_kDmaConfig0[ 1U ],
    },
    /* QSPI2 Module */
    {
        SPI_2_NOT_CONFIGURED,
        SPI_2_NOT_CONFIGURED,
        NULL_PTR,
    },
    /* QSPI3 Module */
    {
        SPI_3_NOT_CONFIGURED,
        SPI_3_NOT_CONFIGURED,
        NULL_PTR,
    },
};


static const Spi_BaudrateEconType Spi_kBaudrateEcon0[]=
{
    {
        Spi_BaudRateECON( 0x4U, 0x0U, 0x1U, 0x3U,
                         SPI_DATA_SHIFT_TRAIL,
                         SPI_CLK_IDLE_LOW,
                         SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL2 << 4U ) | ( SPI_QSPI0_INDEX )
    },
    {
        Spi_BaudRateECON( 0x4U, 0x0U, 0x1U, 0x3U,
                          SPI_DATA_SHIFT_LEAD,
                          SPI_CLK_IDLE_LOW,
                          SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL13 << 4U ) | ( SPI_QSPI0_INDEX )
    },
    {
        Spi_BaudRateECON( 0x4U, 0x0U, 0x1U, 0x3U,
                          SPI_DATA_SHIFT_LEAD,
                          SPI_CLK_IDLE_LOW,
                          SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL0 << 4U ) | ( SPI_QSPI0_INDEX )
    },
    {
        Spi_BaudRateECON( 0x4U, 0x3U, 0x3U, 0x3U,
                          SPI_DATA_SHIFT_LEAD,
                          SPI_CLK_IDLE_LOW,
                          SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL3 << 4U ) | ( SPI_QSPI1_INDEX )
    },
    {
        Spi_BaudRateECON( 0x4U, 0x3U, 0x3U, 0x3U,
                          SPI_DATA_SHIFT_LEAD,
                          SPI_CLK_IDLE_LOW,
                          SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL10 << 4U ) | ( SPI_QSPI1_INDEX )
    },
    {
        Spi_BaudRateECON( 0x4U, 0x0U, 0x1U, 0x3U,
                          SPI_DATA_SHIFT_TRAIL,
                          SPI_CLK_IDLE_LOW,
                          SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL4 << 4U ) | ( SPI_QSPI1_INDEX )
    }
#ifdef TC234_KIT_BOARD
    ,{
        Spi_BaudRateECON( 0x4U, 0x1U, 0x1U, 0x2U,
                          SPI_DATA_SHIFT_TRAIL,
                          SPI_CLK_IDLE_LOW,
                          SPI_QSPI_PARITY_DISABLE ),
        ( uint8 ) ( ( uint8 ) SPI_QSPI_CHANNEL7 << 4U ) | ( SPI_QSPI0_INDEX )
    }
#endif    
};

const Spi_ConfigType Spi_ConfigRoot[ 1U ] =
{
    {
        Spi_kChannelConfig0,
        Spi_kJobConfig0,
        Spi_kSequenceConfig0,
        {
            &Spi_kModuleConfig0[ 0U ],
            &Spi_kModuleConfig0[ 1U ],
            &Spi_kModuleConfig0[ 2U ],
            &Spi_kModuleConfig0[ 3U ],
        },
        Spi_kBaudrateEcon0,
        ( Spi_JobType ) ( sizeof( Spi_kJobConfig0 ) / sizeof( Spi_JobConfigType ) ),
        ( Spi_ChannelType ) ( sizeof( Spi_kChannelConfig0 ) / sizeof( Spi_ChannelConfigType ) ),
        ( Spi_SequenceType ) ( sizeof( Spi_kSequenceConfig0 ) / sizeof( Spi_SequenceConfigType ) ),
        ( uint8 ) ( sizeof( Spi_kBaudrateEcon0 ) / sizeof( Spi_BaudrateEconType ) ),
    }
};


#define SPI_STOP_SEC_POSTBUILDCFG
/* Allows to map variables, constants and code of modules to individual
  memory sections.*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/  
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/* General Notes */
/*
SPI095: The code file structure shall not be defined within this specification
completely. At this point it shall be pointed out that the code-file structure
shall include the following file named:
- Spi_Lcfg.c ?for link time and for post-build configurable parameters and
- Spi_PBcfg.c ?for post build time configurable parameters.
These files shall contain all link time and post-build time configurable
parameters.
This file shall contain all link time and post-build time configurable
parameters.
For the implementation of VariantPC, the implementation stores the
pre compile time parameters that have to be defined as constants in this file.

SPI123: In this configuration, all Sequences declared are considered as Non
Interruptible Sequences. That means, their dedicated parameter
SPI_INTERRUPTIBLE_SEQUENCE (see SPI064 & SPI106) could be omitted or the
FALSE value should be used as default.

*/


