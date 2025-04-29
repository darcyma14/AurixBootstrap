/*
 * SC900719.h
 *
 *  Created on: 2021. 7. 1.
 *  Author: TSMART
 */

#ifndef SC900719_H_
#define SC900719_H_

#include "reuse.h"
#include "Spi.h"

#define SC900719_OK     0
#define SC900719_ERR    1
#define XOR_MAGIC       0x84

typedef union {
        struct {
            uint8_t crc8 ;
            uint8_t dataL ;
            uint8_t dataH ;
            uint8_t addr : 7 ;
            uint8_t rw : 1 ;    
        } K;
        uint8_t msg[4];
        uint32_t pkt;
} PMIC_CTRL ;

typedef union {
        struct {
            uint8_t crc8 ;
            uint8_t dataL ;
            uint8_t dataH ;
            uint8_t addr : 7 ;
            uint8_t err : 1 ;
        } K;
        uint8_t msg[4];
        uint32_t pkt;
} PMIC_RESP ;

typedef union {
    struct {
        uint16_t HSD_OPEN_L     : 1;
        uint16_t HSD_OPEN_R     : 1;
        uint16_t HSD_OV         : 1;
        uint16_t HSD_OC_OP      : 1;
        uint16_t HSD_OT         : 1;
        uint16_t HSD_LEAK       : 1;
        uint16_t HSD_DISC       : 1;
        uint16_t AVD_FLT        : 1;
        uint16_t PMD_OC_OP      : 1;
        uint16_t PMD_OT         : 1;
        uint16_t PMD_PDD_DISC   : 1;
        uint16_t PMD_LD         : 1;
        uint16_t V2V_STAT       : 1;
        uint16_t NC             : 3;
    } S;
    uint16_t    state;
} PMIC_PMDF ;

typedef union {
    struct {
        uint16_t DIE_TEMP_WARN  : 1;
        uint16_t FGND           : 1;
        uint16_t IREF_FAIL      : 1;
        uint16_t CP_FAIL        : 1;
        uint16_t VPWR1_LV       : 1;
        uint16_t VPWR1_OV       : 1;
        uint16_t VPWR1_UV       : 1;
        uint16_t VPWR2_LV       : 1;
        uint16_t VPWR2_OV       : 1;
        uint16_t CLK_FAIL       : 1;
        uint16_t FMSG           : 1;
        uint16_t EXT_RST        : 1;
        uint16_t NC             : 1;
        uint16_t ALU_OVRFLW     : 1;
        uint16_t LBIST_FAIL     : 1;
        uint16_t ABIST_FAIL     : 1;
    } S;
    uint16_t    state;
} PMIC_SVFLT ;

typedef union {
    struct {
        uint16_t VCC3P3_OV      : 1;
        uint16_t VCC3P3_UV      : 1;
        uint16_t VCC5_VCC3_OT   : 1;
        uint16_t VCC5_OV        : 1;
        uint16_t VCC5_UV        : 1;
        uint16_t VCCA_OV        : 1;
        uint16_t VCCA_UV        : 1;
        uint16_t VCCA_VPRE_OT   : 1;
        uint16_t VPRE_OV        : 1;
        uint16_t VPRE_UV        : 1;
        uint16_t VPRE_SUP_DISC  : 1;
        uint16_t VPRE_ILIM      : 1;
        uint16_t VCC5EXT_OT     : 1;
        uint16_t VCC5EXT_OV     : 1;
        uint16_t VCC5EXT_UV     : 1;
        uint16_t NC             : 1;
    } S;
    uint16_t    state;
} PMIC_VREG ;

typedef union {
    struct {
        uint16_t IGN_WU         : 1;
        uint16_t CAN_WU         : 1;
        uint16_t SPRVSN_F       : 1;
        uint16_t VREG_F         : 1;
        uint16_t ISOKVSO_F      : 1;
        uint16_t WLD12_F        : 1;
        uint16_t WS12_F         : 1;
        uint16_t WS34_F         : 1;
        uint16_t LSD16712_F     : 1;
        uint16_t LSD34910_F     : 1;
        uint16_t LSD25822_F     : 1;
        uint16_t PMD_F          : 1;
        uint16_t CAN12_F        : 1;
        uint16_t WDFLT          : 1;
        uint16_t VLVFLG_F       : 1;
        uint16_t NC             : 1;
    } S;
    uint16_t    state;
} PMIC_INT1 ;

typedef union {
    struct {
        uint16_t LSD2_OP        : 1;
        uint16_t LSD2_OC        : 1;
        uint16_t LSD2_OT        : 1;
        uint16_t LSD2_CRER      : 1;
        uint16_t NC             : 8;
        uint16_t LSD8_OP        : 1;
        uint16_t LSD8_OC        : 1;
        uint16_t LSD8_OT        : 1;
        uint16_t LSD8_CRER      : 1;
    } S;
    uint16_t    state;
} PMIC_28F ;

typedef union {
    struct {
        uint16_t LSD3_OP        : 1;
        uint16_t LSD3_OC        : 1;
        uint16_t LSD3_OT        : 1;
        uint16_t LSD3_CRER      : 1;
        uint16_t NC1            : 4;
        uint16_t LSD9_OP        : 1;
        uint16_t LSD9_OC        : 1;
        uint16_t LSD9_OT        : 1;
        uint16_t LSD9_CRER      : 1;
        uint16_t NC2            : 4;
    } S;
    uint16_t    state;
} PMIC_39F ;

typedef union {
    struct {
        uint16_t VPWR1LVFAIL    : 1;
        uint16_t VPWR2LVFAIL    : 1;
        uint16_t VPWR1UVFAIL    : 1;
        uint16_t VPWR1OVFAIL    : 1;
        uint16_t VPWR2OVFAIL    : 1;
        uint16_t HD_DOVFAIL     : 1;
        uint16_t PD_DOVFAIL     : 1;
        uint16_t VCC3UVFAIL     : 1;
        uint16_t VCC5UVFAIL     : 1;
        uint16_t VCC5EXUVFAIL   : 1;
        uint16_t VCCAUVFAIL     : 1;
        uint16_t CPUVFAIL       : 1;
        uint16_t RSTBFAIL       : 1;
        uint16_t VCCAVPREOTFAIL : 1;
        uint16_t VCC5VCC3OTFAIL : 1;
        uint16_t VCC5EXOTFAIL   : 1;
    } S;
    uint16_t    state;
} PMIC_ABISTFAIL ;

typedef enum
{
    PMIC_ADDR_CHIPID = 0x00u,
    PMIC_ADDR_SVCFG_BIST,
    PMIC_ADDR_WSCFG1 = 0x03u,
    PMIC_ADDR_VLVCLK = 0x05u,

    PMIC_ADDR_LSD3K,
    PMIC_ADDR_LSD9K,
    PMIC_ADDR_LSD2K,
    PMIC_ADDR_LSD8K,

    PMIC_ADDR_HSDCFG = 0x0au,
    PMIC_ADDR_CAN_CFG = 0x0cu,
    PMIC_ADDR_ABISTFAIL,
    PMIC_ADDR_ABIST_DIS = 0x0fu,
    PMIC_ADDR_VLVEN = 0x12u,
    PMIC_ADDR_LSD1DC,
    PMIC_ADDR_LSD6DC,
    PMIC_ADDR_LSD7DC,
    PMIC_ADDR_LSD12DC,
    PMIC_ADDR_LSD3I,
    PMIC_ADDR_LSD4I,
    PMIC_ADDR_LSD9I,
    PMIC_ADDR_LSD10I,
    PMIC_ADDR_LSD2I,
    PMIC_ADDR_LSD11I,
    PMIC_ADDR_LSD5I,
    PMIC_ADDR_LSD8I,
    PMIC_ADDR_PMDCFG,
    
    PMIC_ADDR_INT1 = 0x35u,
    PMIC_ADDR_LSD39F = 0x37u,
    PMIC_ADDR_LSD28F,
    PMIC_ADDR_PMDF,
    PMIC_ADDR_SVFLT = 0x3au,
    PMIC_ADDR_VREG_FLG, 
    PMIC_ADDR_CAN_FLG = 0x46u,
    PMIC_ADDR_WLD12,
    PMIC_ADDR_ISOKVSO12
} PMIC_NORMAL_ADDR ;

typedef enum
{
    G_SOL1 = PMIC_ADDR_LSD2I,
    G_SOL2 = PMIC_ADDR_LSD3I,
    TOQ_VEC_R_SOL = PMIC_ADDR_LSD9I,
    TOQ_VEC_L_SOL = PMIC_ADDR_LSD8I,
} SOL_VALVE ;

extern uint8_t Spi_CompleteFlag;

extern uint16_t SC900719_Read(PMIC_NORMAL_ADDR addr) ;
extern uint8_t SC900719_Write(PMIC_NORMAL_ADDR addr, uint16_t senddata) ;
extern uint16_t SC900719_Init(void);
extern uint8_t Ctr_SolValve(SOL_VALVE select, float Ivalue);
extern void PwSBC_GotoLPOFF(void);
extern void delay(uint32_t dly);
extern uint16_t SC900719_State(void);

#endif /* SC900719_H_ */
