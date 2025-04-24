################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../MCAL/cfg/src/Adc_PBCfg.c" \
"../MCAL/cfg/src/Can_17_MCanP_PBCfg.c" \
"../MCAL/cfg/src/Dio_PBCfg.c" \
"../MCAL/cfg/src/EcuM_LCfg.c" \
"../MCAL/cfg/src/EcuM_PBCfg.c" \
"../MCAL/cfg/src/Gpt_PBCfg.c" \
"../MCAL/cfg/src/Gtm_LCfg.c" \
"../MCAL/cfg/src/Gtm_PBCfg.c" \
"../MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.c" \
"../MCAL/cfg/src/Lin_17_AscLin_PBCfg.c" \
"../MCAL/cfg/src/Mcu_PBCfg.c" \
"../MCAL/cfg/src/Port_PBCfg.c" \
"../MCAL/cfg/src/Pwm_17_Gtm_PBCfg.c" \
"../MCAL/cfg/src/Spi_PBCfg.c" \
"../MCAL/cfg/src/Uart_PBCfg.c" 

COMPILED_SRCS += \
"MCAL/cfg/src/Adc_PBCfg.src" \
"MCAL/cfg/src/Can_17_MCanP_PBCfg.src" \
"MCAL/cfg/src/Dio_PBCfg.src" \
"MCAL/cfg/src/EcuM_LCfg.src" \
"MCAL/cfg/src/EcuM_PBCfg.src" \
"MCAL/cfg/src/Gpt_PBCfg.src" \
"MCAL/cfg/src/Gtm_LCfg.src" \
"MCAL/cfg/src/Gtm_PBCfg.src" \
"MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.src" \
"MCAL/cfg/src/Lin_17_AscLin_PBCfg.src" \
"MCAL/cfg/src/Mcu_PBCfg.src" \
"MCAL/cfg/src/Port_PBCfg.src" \
"MCAL/cfg/src/Pwm_17_Gtm_PBCfg.src" \
"MCAL/cfg/src/Spi_PBCfg.src" \
"MCAL/cfg/src/Uart_PBCfg.src" 

C_DEPS += \
"./MCAL/cfg/src/Adc_PBCfg.d" \
"./MCAL/cfg/src/Can_17_MCanP_PBCfg.d" \
"./MCAL/cfg/src/Dio_PBCfg.d" \
"./MCAL/cfg/src/EcuM_LCfg.d" \
"./MCAL/cfg/src/EcuM_PBCfg.d" \
"./MCAL/cfg/src/Gpt_PBCfg.d" \
"./MCAL/cfg/src/Gtm_LCfg.d" \
"./MCAL/cfg/src/Gtm_PBCfg.d" \
"./MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.d" \
"./MCAL/cfg/src/Lin_17_AscLin_PBCfg.d" \
"./MCAL/cfg/src/Mcu_PBCfg.d" \
"./MCAL/cfg/src/Port_PBCfg.d" \
"./MCAL/cfg/src/Pwm_17_Gtm_PBCfg.d" \
"./MCAL/cfg/src/Spi_PBCfg.d" \
"./MCAL/cfg/src/Uart_PBCfg.d" 

OBJS += \
"MCAL/cfg/src/Adc_PBCfg.o" \
"MCAL/cfg/src/Can_17_MCanP_PBCfg.o" \
"MCAL/cfg/src/Dio_PBCfg.o" \
"MCAL/cfg/src/EcuM_LCfg.o" \
"MCAL/cfg/src/EcuM_PBCfg.o" \
"MCAL/cfg/src/Gpt_PBCfg.o" \
"MCAL/cfg/src/Gtm_LCfg.o" \
"MCAL/cfg/src/Gtm_PBCfg.o" \
"MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.o" \
"MCAL/cfg/src/Lin_17_AscLin_PBCfg.o" \
"MCAL/cfg/src/Mcu_PBCfg.o" \
"MCAL/cfg/src/Port_PBCfg.o" \
"MCAL/cfg/src/Pwm_17_Gtm_PBCfg.o" \
"MCAL/cfg/src/Spi_PBCfg.o" \
"MCAL/cfg/src/Uart_PBCfg.o" 


# Each subdirectory must supply rules for building sources it contributes
"MCAL/cfg/src/Adc_PBCfg.src":"../MCAL/cfg/src/Adc_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Adc_PBCfg.o":"MCAL/cfg/src/Adc_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Can_17_MCanP_PBCfg.src":"../MCAL/cfg/src/Can_17_MCanP_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Can_17_MCanP_PBCfg.o":"MCAL/cfg/src/Can_17_MCanP_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Dio_PBCfg.src":"../MCAL/cfg/src/Dio_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Dio_PBCfg.o":"MCAL/cfg/src/Dio_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/EcuM_LCfg.src":"../MCAL/cfg/src/EcuM_LCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/EcuM_LCfg.o":"MCAL/cfg/src/EcuM_LCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/EcuM_PBCfg.src":"../MCAL/cfg/src/EcuM_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/EcuM_PBCfg.o":"MCAL/cfg/src/EcuM_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Gpt_PBCfg.src":"../MCAL/cfg/src/Gpt_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Gpt_PBCfg.o":"MCAL/cfg/src/Gpt_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Gtm_LCfg.src":"../MCAL/cfg/src/Gtm_LCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Gtm_LCfg.o":"MCAL/cfg/src/Gtm_LCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Gtm_PBCfg.src":"../MCAL/cfg/src/Gtm_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Gtm_PBCfg.o":"MCAL/cfg/src/Gtm_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.src":"../MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.o":"MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Lin_17_AscLin_PBCfg.src":"../MCAL/cfg/src/Lin_17_AscLin_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Lin_17_AscLin_PBCfg.o":"MCAL/cfg/src/Lin_17_AscLin_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Mcu_PBCfg.src":"../MCAL/cfg/src/Mcu_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Mcu_PBCfg.o":"MCAL/cfg/src/Mcu_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Port_PBCfg.src":"../MCAL/cfg/src/Port_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Port_PBCfg.o":"MCAL/cfg/src/Port_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Pwm_17_Gtm_PBCfg.src":"../MCAL/cfg/src/Pwm_17_Gtm_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Pwm_17_Gtm_PBCfg.o":"MCAL/cfg/src/Pwm_17_Gtm_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Spi_PBCfg.src":"../MCAL/cfg/src/Spi_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Spi_PBCfg.o":"MCAL/cfg/src/Spi_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/cfg/src/Uart_PBCfg.src":"../MCAL/cfg/src/Uart_PBCfg.c" "MCAL/cfg/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/cfg/src/Uart_PBCfg.o":"MCAL/cfg/src/Uart_PBCfg.src" "MCAL/cfg/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MCAL-2f-cfg-2f-src

clean-MCAL-2f-cfg-2f-src:
	-$(RM) ./MCAL/cfg/src/Adc_PBCfg.d ./MCAL/cfg/src/Adc_PBCfg.o ./MCAL/cfg/src/Adc_PBCfg.src ./MCAL/cfg/src/Can_17_MCanP_PBCfg.d ./MCAL/cfg/src/Can_17_MCanP_PBCfg.o ./MCAL/cfg/src/Can_17_MCanP_PBCfg.src ./MCAL/cfg/src/Dio_PBCfg.d ./MCAL/cfg/src/Dio_PBCfg.o ./MCAL/cfg/src/Dio_PBCfg.src ./MCAL/cfg/src/EcuM_LCfg.d ./MCAL/cfg/src/EcuM_LCfg.o ./MCAL/cfg/src/EcuM_LCfg.src ./MCAL/cfg/src/EcuM_PBCfg.d ./MCAL/cfg/src/EcuM_PBCfg.o ./MCAL/cfg/src/EcuM_PBCfg.src ./MCAL/cfg/src/Gpt_PBCfg.d ./MCAL/cfg/src/Gpt_PBCfg.o ./MCAL/cfg/src/Gpt_PBCfg.src ./MCAL/cfg/src/Gtm_LCfg.d ./MCAL/cfg/src/Gtm_LCfg.o ./MCAL/cfg/src/Gtm_LCfg.src ./MCAL/cfg/src/Gtm_PBCfg.d ./MCAL/cfg/src/Gtm_PBCfg.o ./MCAL/cfg/src/Gtm_PBCfg.src ./MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.d ./MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.o ./MCAL/cfg/src/Icu_17_GtmCcu6_PBCfg.src ./MCAL/cfg/src/Lin_17_AscLin_PBCfg.d ./MCAL/cfg/src/Lin_17_AscLin_PBCfg.o ./MCAL/cfg/src/Lin_17_AscLin_PBCfg.src ./MCAL/cfg/src/Mcu_PBCfg.d ./MCAL/cfg/src/Mcu_PBCfg.o ./MCAL/cfg/src/Mcu_PBCfg.src ./MCAL/cfg/src/Port_PBCfg.d ./MCAL/cfg/src/Port_PBCfg.o ./MCAL/cfg/src/Port_PBCfg.src ./MCAL/cfg/src/Pwm_17_Gtm_PBCfg.d ./MCAL/cfg/src/Pwm_17_Gtm_PBCfg.o ./MCAL/cfg/src/Pwm_17_Gtm_PBCfg.src ./MCAL/cfg/src/Spi_PBCfg.d ./MCAL/cfg/src/Spi_PBCfg.o ./MCAL/cfg/src/Spi_PBCfg.src ./MCAL/cfg/src/Uart_PBCfg.d ./MCAL/cfg/src/Uart_PBCfg.o ./MCAL/cfg/src/Uart_PBCfg.src

.PHONY: clean-MCAL-2f-cfg-2f-src

