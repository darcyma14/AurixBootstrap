/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Dio_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\37 $                                                 **
**                                                                            **
**   DATE, TIME  : 2021-12-28, 13:38:10                                       **
**                                                                            **
**   GENERATOR   : Build b141014-0350                                         **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : DIO configuration generated out of ECU configuration       **
**                  file                                                      **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H
/*
 Notes:
 - The runtime configuration is handled by the Port Driver Module.
 - The configuration and usage of the DIO Driver Module is adapted to 
   the microcontroller and ECU.

*/

/*Version check macros */
#define DIO_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_AR_RELEASE_REVISION_VERSION  (3U)

#define DIO_SW_MAJOR_VERSION  (3U)
#define DIO_SW_MINOR_VERSION  (0U)
#define DIO_SW_PATCH_VERSION  (4U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*                          Container: DioSafety                             */
/*
Configuration: DIO_SAFETY_ENABLE
- if STD_ON, Safety feature is available  
- if STD_OFF, Safety feature is not available 
*/
#define DIO_SAFETY_ENABLE                   (STD_OFF)

/*
Configuration: DIO_INITCHECK_API
- if STD_ON, Dio_InitCheck API is available  
- if STD_OFF, Dio_InitCheck API is not available 
*/
#define DIO_INITCHECK_API                   (STD_OFF)

/*                          Container: DioGeneral                            */
/*
Configuration: PORT_PB_FIXED_ADDRESS
- if STD_ON, PortPBFixedAddress feature is available  
- if STD_OFF, PortPBFixedAddress feature is not available 
*/
#define DIO_PB_FIXED_ADDRESS                (STD_OFF)

/*
  Pre-processor switch to enable/disable detection of Development errors.
  - if defined ON, Development error detection is enabled
  - if defined OFF, Development error detection is disabled
*/
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/*
  Pre-Compiler switch to include the API Dio_GetVersionInfo()
  - if defined ON, Dio_GetVersionInfo API available
  - if defined OFF, Dio_GetVersionInfo API not available
*/
#define DIO_VERSION_INFO_API                (STD_OFF)

/*
  Pre-Compiler switch to include the API Dio_FlipChannel()
  - if defined ON, Dio_FlipChannel API available
  - if defined OFF, Dio_FlipChannel API not available
*/
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* No. of Configuration Sets */
#define DIO_CONFIG_COUNT                     (1U)

#define DIO_CH_GRP_SET_U                    (0U)

/* To specify if Loadable or Selectable configuration is used */
#define DIO_LOADABLE_USED      (STD_OFF)
 
/* The following macros are available only if development error detection
   or safety is on is enabled */

/* Definition to specify the ports available on the microcontroller 
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
#define DIO_PORTS_AVAILABLE_00_31           (0x00f0ec05U)

/* Definition to specify the ports available on the microcontroller 
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 */
#define DIO_PORTS_AVAILABLE_32_40           (0x00000306U)

/* Definition to specify the ports that are read only ports on the 
   microcontroller 
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
#define DIO_PORTS_READONLY_00_31             (0x00000000U)

/* Definition to specify the ports that are read only ports on the 
   microcontroller 
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 */
#define DIO_PORTS_READONLY_32_40             (0x00000300U)

/* Macro to define the maximum port available */
#define MAX_AVAILABLE_PORTS                  (41U)

/* Value of the most significant pin on the port
   Note: In case of no pins on a port, the value is kept 0 */
#define DIO_PORT_0_MSPIN                     (12U)
#define DIO_PORT_1_MSPIN                     (0U)
#define DIO_PORT_2_MSPIN                     (8U)
#define DIO_PORT_3_MSPIN                     (0U)
#define DIO_PORT_4_MSPIN                     (0U)
#define DIO_PORT_5_MSPIN                     (0U)
#define DIO_PORT_6_MSPIN                     (0U)
#define DIO_PORT_7_MSPIN                     (0U)
#define DIO_PORT_8_MSPIN                     (0U)
#define DIO_PORT_9_MSPIN                     (0U)
#define DIO_PORT_10_MSPIN                     (6U)
#define DIO_PORT_11_MSPIN                     (12U)
#define DIO_PORT_12_MSPIN                     (0U)
#define DIO_PORT_13_MSPIN                     (3U)
#define DIO_PORT_14_MSPIN                     (8U)
#define DIO_PORT_15_MSPIN                     (8U)
#define DIO_PORT_16_MSPIN                     (0U)
#define DIO_PORT_17_MSPIN                     (0U)
#define DIO_PORT_18_MSPIN                     (0U)
#define DIO_PORT_19_MSPIN                     (0U)
#define DIO_PORT_20_MSPIN                     (14U)
#define DIO_PORT_21_MSPIN                     (7U)
#define DIO_PORT_22_MSPIN                     (4U)
#define DIO_PORT_23_MSPIN                     (1U)
#define DIO_PORT_24_MSPIN                     (0U)
#define DIO_PORT_25_MSPIN                     (0U)
#define DIO_PORT_26_MSPIN                     (0U)
#define DIO_PORT_27_MSPIN                     (0U)
#define DIO_PORT_28_MSPIN                     (0U)
#define DIO_PORT_29_MSPIN                     (0U)
#define DIO_PORT_30_MSPIN                     (0U)
#define DIO_PORT_31_MSPIN                     (0U)
#define DIO_PORT_32_MSPIN                     (0U)
#define DIO_PORT_33_MSPIN                     (12U)
#define DIO_PORT_34_MSPIN                     (3U)
#define DIO_PORT_35_MSPIN                     (0U)
#define DIO_PORT_36_MSPIN                     (0U)
#define DIO_PORT_37_MSPIN                     (0U)
#define DIO_PORT_38_MSPIN                     (0U)
#define DIO_PORT_39_MSPIN                     (0U)
#define DIO_PORT_40_MSPIN                     (11U)
#define DIO_PORT_41_MSPIN                     (11U)


/* Values to mask the undefined port pins within a port */
#define DIO_MASK_UNDEF_PINS_PORT0             (0x13ffU)
#define DIO_MASK_UNDEF_PINS_PORT1             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT2             (0x01ffU)
#define DIO_MASK_UNDEF_PINS_PORT3             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT4             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT5             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT6             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT7             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT8             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT9             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT10             (0x006eU)
#define DIO_MASK_UNDEF_PINS_PORT11             (0x1f4cU)
#define DIO_MASK_UNDEF_PINS_PORT12             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT13             (0x000fU)
#define DIO_MASK_UNDEF_PINS_PORT14             (0x01ffU)
#define DIO_MASK_UNDEF_PINS_PORT15             (0x01ffU)
#define DIO_MASK_UNDEF_PINS_PORT16             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT17             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT18             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT19             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT20             (0x7fcdU)
#define DIO_MASK_UNDEF_PINS_PORT21             (0x00fcU)
#define DIO_MASK_UNDEF_PINS_PORT22             (0x001fU)
#define DIO_MASK_UNDEF_PINS_PORT23             (0x0002U)
#define DIO_MASK_UNDEF_PINS_PORT24             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT25             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT26             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT27             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT28             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT29             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT30             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT31             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT32             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT33             (0x1fffU)
#define DIO_MASK_UNDEF_PINS_PORT34             (0x000fU)
#define DIO_MASK_UNDEF_PINS_PORT35             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT36             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT37             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT38             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT39             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT40             (0x0fffU)
#define DIO_MASK_UNDEF_PINS_PORT41             (0x0fffU)

/*******************************************************************************
**                           Global Symbols                                   **
*******************************************************************************/

/*   
 Symbolic names for DIO Channels, Port & Channel groups
*/
/* 
                       Symbolic names for Channels
*/
#define DIO_CHANNEL_0_0                    ((Dio_ChannelType)0x000)
#define DIO_CHANNEL_0_1                    ((Dio_ChannelType)0x001)
#define DIO_CHANNEL_0_2                    ((Dio_ChannelType)0x002)
#define DIO_CHANNEL_0_3                    ((Dio_ChannelType)0x003)
#define DIO_CHANNEL_0_4                    ((Dio_ChannelType)0x004)
#define DIO_CHANNEL_0_5                    ((Dio_ChannelType)0x005)
#define DIO_CHANNEL_0_6                    ((Dio_ChannelType)0x006)
#define DIO_CHANNEL_0_7                    ((Dio_ChannelType)0x007)
#define DIO_CHANNEL_0_8                    ((Dio_ChannelType)0x008)
#define DIO_CHANNEL_0_9                    ((Dio_ChannelType)0x009)
#define DIO_CHANNEL_0_12                    ((Dio_ChannelType)0x00c)
#define DIO_CHANNEL_2_0                    ((Dio_ChannelType)0x020)
#define DIO_CHANNEL_2_1                    ((Dio_ChannelType)0x021)
#define DIO_CHANNEL_2_2                    ((Dio_ChannelType)0x022)
#define DIO_CHANNEL_2_3                    ((Dio_ChannelType)0x023)
#define DIO_CHANNEL_2_4                    ((Dio_ChannelType)0x024)
#define DIO_CHANNEL_2_5                    ((Dio_ChannelType)0x025)
#define DIO_CHANNEL_2_6                    ((Dio_ChannelType)0x026)
#define DIO_CHANNEL_2_7                    ((Dio_ChannelType)0x027)
#define DIO_CHANNEL_2_8                    ((Dio_ChannelType)0x028)
#define DIO_CHANNEL_10_1                    ((Dio_ChannelType)0x0a1)
#define DIO_CHANNEL_10_2                    ((Dio_ChannelType)0x0a2)
#define DIO_CHANNEL_10_3                    ((Dio_ChannelType)0x0a3)
#define DIO_CHANNEL_10_5                    ((Dio_ChannelType)0x0a5)
#define DIO_CHANNEL_10_6                    ((Dio_ChannelType)0x0a6)
#define DIO_CHANNEL_11_2                    ((Dio_ChannelType)0x0b2)
#define DIO_CHANNEL_11_3                    ((Dio_ChannelType)0x0b3)
#define DIO_CHANNEL_11_6                    ((Dio_ChannelType)0x0b6)
#define DIO_CHANNEL_11_8                    ((Dio_ChannelType)0x0b8)
#define DIO_CHANNEL_11_9                    ((Dio_ChannelType)0x0b9)
#define DIO_CHANNEL_11_10                    ((Dio_ChannelType)0x0ba)
#define DIO_CHANNEL_11_11                    ((Dio_ChannelType)0x0bb)
#define DIO_CHANNEL_11_12                    ((Dio_ChannelType)0x0bc)
#define DIO_CHANNEL_13_0                    ((Dio_ChannelType)0x0d0)
#define DIO_CHANNEL_13_1                    ((Dio_ChannelType)0x0d1)
#define DIO_CHANNEL_13_2                    ((Dio_ChannelType)0x0d2)
#define DIO_CHANNEL_13_3                    ((Dio_ChannelType)0x0d3)
#define DIO_CHANNEL_14_0                    ((Dio_ChannelType)0x0e0)
#define DIO_CHANNEL_14_1                    ((Dio_ChannelType)0x0e1)
#define DIO_CHANNEL_14_2                    ((Dio_ChannelType)0x0e2)
#define DIO_CHANNEL_14_3                    ((Dio_ChannelType)0x0e3)
#define DIO_CHANNEL_14_4                    ((Dio_ChannelType)0x0e4)
#define DIO_CHANNEL_14_5                    ((Dio_ChannelType)0x0e5)
#define DIO_CHANNEL_14_6                    ((Dio_ChannelType)0x0e6)
#define DIO_CHANNEL_14_7                    ((Dio_ChannelType)0x0e7)
#define DIO_CHANNEL_14_8                    ((Dio_ChannelType)0x0e8)
#define DIO_CHANNEL_15_0                    ((Dio_ChannelType)0x0f0)
#define DIO_CHANNEL_15_1                    ((Dio_ChannelType)0x0f1)
#define DIO_CHANNEL_15_2                    ((Dio_ChannelType)0x0f2)
#define DIO_CHANNEL_15_3                    ((Dio_ChannelType)0x0f3)
#define DIO_CHANNEL_15_4                    ((Dio_ChannelType)0x0f4)
#define DIO_CHANNEL_15_5                    ((Dio_ChannelType)0x0f5)
#define DIO_CHANNEL_15_6                    ((Dio_ChannelType)0x0f6)
#define DIO_CHANNEL_15_7                    ((Dio_ChannelType)0x0f7)
#define DIO_CHANNEL_15_8                    ((Dio_ChannelType)0x0f8)
#define DIO_CHANNEL_20_0                    ((Dio_ChannelType)0x140)
#define DIO_CHANNEL_20_2                    ((Dio_ChannelType)0x142)
#define DIO_CHANNEL_20_3                    ((Dio_ChannelType)0x143)
#define DIO_CHANNEL_20_6                    ((Dio_ChannelType)0x146)
#define DIO_CHANNEL_20_7                    ((Dio_ChannelType)0x147)
#define DIO_CHANNEL_20_8                    ((Dio_ChannelType)0x148)
#define DIO_CHANNEL_20_9                    ((Dio_ChannelType)0x149)
#define DIO_CHANNEL_20_10                    ((Dio_ChannelType)0x14a)
#define DIO_CHANNEL_20_11                    ((Dio_ChannelType)0x14b)
#define DIO_CHANNEL_20_12                    ((Dio_ChannelType)0x14c)
#define DIO_CHANNEL_20_13                    ((Dio_ChannelType)0x14d)
#define DIO_CHANNEL_20_14                    ((Dio_ChannelType)0x14e)
#define DIO_CHANNEL_21_2                    ((Dio_ChannelType)0x152)
#define DIO_CHANNEL_21_3                    ((Dio_ChannelType)0x153)
#define DIO_CHANNEL_21_4                    ((Dio_ChannelType)0x154)
#define DIO_CHANNEL_21_5                    ((Dio_ChannelType)0x155)
#define DIO_CHANNEL_21_6                    ((Dio_ChannelType)0x156)
#define DIO_CHANNEL_21_7                    ((Dio_ChannelType)0x157)
#define DIO_CHANNEL_22_0                    ((Dio_ChannelType)0x160)
#define DIO_CHANNEL_22_1                    ((Dio_ChannelType)0x161)
#define DIO_CHANNEL_22_2                    ((Dio_ChannelType)0x162)
#define DIO_CHANNEL_22_3                    ((Dio_ChannelType)0x163)
#define DIO_CHANNEL_22_4                    ((Dio_ChannelType)0x164)
#define DIO_CHANNEL_23_1                    ((Dio_ChannelType)0x171)
#define DIO_CHANNEL_33_0                    ((Dio_ChannelType)0x210)
#define DIO_CHANNEL_33_1                    ((Dio_ChannelType)0x211)
#define DIO_CHANNEL_33_2                    ((Dio_ChannelType)0x212)
#define DIO_CHANNEL_33_3                    ((Dio_ChannelType)0x213)
#define DIO_CHANNEL_33_4                    ((Dio_ChannelType)0x214)
#define DIO_CHANNEL_33_5                    ((Dio_ChannelType)0x215)
#define DIO_CHANNEL_33_6                    ((Dio_ChannelType)0x216)
#define DIO_CHANNEL_33_7                    ((Dio_ChannelType)0x217)
#define DIO_CHANNEL_33_8                    ((Dio_ChannelType)0x218)
#define DIO_CHANNEL_33_9                    ((Dio_ChannelType)0x219)
#define DIO_CHANNEL_33_10                    ((Dio_ChannelType)0x21a)
#define DIO_CHANNEL_33_11                    ((Dio_ChannelType)0x21b)
#define DIO_CHANNEL_33_12                    ((Dio_ChannelType)0x21c)
#define DIO_CHANNEL_34_0                    ((Dio_ChannelType)0x220)
#define DIO_CHANNEL_34_1                    ((Dio_ChannelType)0x221)
#define DIO_CHANNEL_34_2                    ((Dio_ChannelType)0x222)
#define DIO_CHANNEL_34_3                    ((Dio_ChannelType)0x223)
#define DIO_CHANNEL_40_0                    ((Dio_ChannelType)0x280)
#define DIO_CHANNEL_40_1                    ((Dio_ChannelType)0x281)
#define DIO_CHANNEL_40_2                    ((Dio_ChannelType)0x282)
#define DIO_CHANNEL_40_3                    ((Dio_ChannelType)0x283)
#define DIO_CHANNEL_40_4                    ((Dio_ChannelType)0x284)
#define DIO_CHANNEL_40_5                    ((Dio_ChannelType)0x285)
#define DIO_CHANNEL_40_6                    ((Dio_ChannelType)0x286)
#define DIO_CHANNEL_40_7                    ((Dio_ChannelType)0x287)
#define DIO_CHANNEL_40_8                    ((Dio_ChannelType)0x288)
#define DIO_CHANNEL_40_9                    ((Dio_ChannelType)0x289)
#define DIO_CHANNEL_40_10                    ((Dio_ChannelType)0x28a)
#define DIO_CHANNEL_40_11                    ((Dio_ChannelType)0x28b)
#define DIO_CHANNEL_41_0                    ((Dio_ChannelType)0x290)
#define DIO_CHANNEL_41_1                    ((Dio_ChannelType)0x291)
#define DIO_CHANNEL_41_2                    ((Dio_ChannelType)0x292)
#define DIO_CHANNEL_41_3                    ((Dio_ChannelType)0x293)
#define DIO_CHANNEL_41_4                    ((Dio_ChannelType)0x294)
#define DIO_CHANNEL_41_5                    ((Dio_ChannelType)0x295)
#define DIO_CHANNEL_41_6                    ((Dio_ChannelType)0x296)
#define DIO_CHANNEL_41_7                    ((Dio_ChannelType)0x297)
#define DIO_CHANNEL_41_8                    ((Dio_ChannelType)0x298)
#define DIO_CHANNEL_41_9                    ((Dio_ChannelType)0x299)
#define DIO_CHANNEL_41_10                    ((Dio_ChannelType)0x29a)
#define DIO_CHANNEL_41_11                    ((Dio_ChannelType)0x29b)


/*
                      Symbolic names for DIO ports
*/
#define DIO_PORT_0                          ((Dio_PortType)0)
#define DIO_PORT_2                          ((Dio_PortType)2)
#define DIO_PORT_10                          ((Dio_PortType)10)
#define DIO_PORT_11                          ((Dio_PortType)11)
#define DIO_PORT_13                          ((Dio_PortType)13)
#define DIO_PORT_14                          ((Dio_PortType)14)
#define DIO_PORT_15                          ((Dio_PortType)15)
#define DIO_PORT_20                          ((Dio_PortType)20)
#define DIO_PORT_21                          ((Dio_PortType)21)
#define DIO_PORT_22                          ((Dio_PortType)22)
#define DIO_PORT_23                          ((Dio_PortType)23)
#define DIO_PORT_33                          ((Dio_PortType)33)
#define DIO_PORT_34                          ((Dio_PortType)34)
#define DIO_PORT_40                          ((Dio_PortType)40)
#define DIO_PORT_41                          ((Dio_PortType)41)


/* Number of Channel groups configured for the DioConfig1 */
#define DIO_CHANNELGROUPCOUNT_0   (0U)
/*
      User Defined Symbolic Names for the DIO Ports, Channels & Channel Groups
      DioConfig 1
*/


/*
  DIO PORT : (DioConf_DioPort_DioPort_0)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_0
#define DioConf_DioPort_DioPort_0 (DIO_PORT_33)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_I0) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_I0
#define DioConf_DioChannel_HSD_I0 (DIO_CHANNEL_33_0)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_I1) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_I1
#define DioConf_DioChannel_HSD_I1 (DIO_CHANNEL_33_1)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_I2) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_I2
#define DioConf_DioChannel_HSD_I2 (DIO_CHANNEL_33_2)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_I3) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_I3
#define DioConf_DioChannel_HSD_I3 (DIO_CHANNEL_33_3)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_SEL0) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_SEL0
#define DioConf_DioChannel_HSD_SEL0 (DIO_CHANNEL_33_4)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_SEL1) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_SEL1
#define DioConf_DioChannel_HSD_SEL1 (DIO_CHANNEL_33_5)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_SEL2) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_SEL2
#define DioConf_DioChannel_HSD_SEL2 (DIO_CHANNEL_33_6)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_SEn) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_SEn
#define DioConf_DioChannel_HSD_SEn (DIO_CHANNEL_33_7)
#endif


/* DIO Channel : (DioConf_DioChannel_HSD_FAULT) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_HSD_FAULT
#define DioConf_DioChannel_HSD_FAULT (DIO_CHANNEL_33_8)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_1)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_1
#define DioConf_DioPort_DioPort_1 (DIO_PORT_2)
#endif


/* DIO Channel : (DioConf_DioChannel_LED1) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_LED1
#define DioConf_DioChannel_LED1 (DIO_CHANNEL_2_1)
#endif


/* DIO Channel : (DioConf_DioChannel_LED2) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_LED2
#define DioConf_DioChannel_LED2 (DIO_CHANNEL_2_2)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_2)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_2
#define DioConf_DioPort_DioPort_2 (DIO_PORT_10)
#endif


/* DIO Channel : (DioConf_DioChannel_POS_SEN_R) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_POS_SEN_R
#define DioConf_DioChannel_POS_SEN_R (DIO_CHANNEL_10_2)
#endif


/* DIO Channel : (DioConf_DioChannel_POS_SEN_L) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_POS_SEN_L
#define DioConf_DioChannel_POS_SEN_L (DIO_CHANNEL_10_3)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_3)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_3
#define DioConf_DioPort_DioPort_3 (DIO_PORT_20)
#endif


/* DIO Channel : (DioConf_DioChannel_PMIC_BIST) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_PMIC_BIST
#define DioConf_DioChannel_PMIC_BIST (DIO_CHANNEL_20_10)
#endif


/* DIO Channel : (DioConf_DioChannel_PMIC_DBG) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_PMIC_DBG
#define DioConf_DioChannel_PMIC_DBG (DIO_CHANNEL_20_13)
#endif



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Type                                      **
*******************************************************************************/

/* End of DIO_CFG_H */
#endif
