################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../MCAL/ssc/irq/src/Adc_Irq.c" \
"../MCAL/ssc/irq/src/AscLin_Irq.c" \
"../MCAL/ssc/irq/src/Can_Irq.c" \
"../MCAL/ssc/irq/src/Ccu6_Irq.c" \
"../MCAL/ssc/irq/src/Dma_Irq.c" \
"../MCAL/ssc/irq/src/Eru_Irq.c" \
"../MCAL/ssc/irq/src/Gtm_Irq.c" \
"../MCAL/ssc/irq/src/Spi_Irq.c" \
"../MCAL/ssc/irq/src/Stm_Irq.c" \
"../MCAL/ssc/irq/src/irq.c" 

COMPILED_SRCS += \
"MCAL/ssc/irq/src/Adc_Irq.src" \
"MCAL/ssc/irq/src/AscLin_Irq.src" \
"MCAL/ssc/irq/src/Can_Irq.src" \
"MCAL/ssc/irq/src/Ccu6_Irq.src" \
"MCAL/ssc/irq/src/Dma_Irq.src" \
"MCAL/ssc/irq/src/Eru_Irq.src" \
"MCAL/ssc/irq/src/Gtm_Irq.src" \
"MCAL/ssc/irq/src/Spi_Irq.src" \
"MCAL/ssc/irq/src/Stm_Irq.src" \
"MCAL/ssc/irq/src/irq.src" 

C_DEPS += \
"./MCAL/ssc/irq/src/Adc_Irq.d" \
"./MCAL/ssc/irq/src/AscLin_Irq.d" \
"./MCAL/ssc/irq/src/Can_Irq.d" \
"./MCAL/ssc/irq/src/Ccu6_Irq.d" \
"./MCAL/ssc/irq/src/Dma_Irq.d" \
"./MCAL/ssc/irq/src/Eru_Irq.d" \
"./MCAL/ssc/irq/src/Gtm_Irq.d" \
"./MCAL/ssc/irq/src/Spi_Irq.d" \
"./MCAL/ssc/irq/src/Stm_Irq.d" \
"./MCAL/ssc/irq/src/irq.d" 

OBJS += \
"MCAL/ssc/irq/src/Adc_Irq.o" \
"MCAL/ssc/irq/src/AscLin_Irq.o" \
"MCAL/ssc/irq/src/Can_Irq.o" \
"MCAL/ssc/irq/src/Ccu6_Irq.o" \
"MCAL/ssc/irq/src/Dma_Irq.o" \
"MCAL/ssc/irq/src/Eru_Irq.o" \
"MCAL/ssc/irq/src/Gtm_Irq.o" \
"MCAL/ssc/irq/src/Spi_Irq.o" \
"MCAL/ssc/irq/src/Stm_Irq.o" \
"MCAL/ssc/irq/src/irq.o" 


# Each subdirectory must supply rules for building sources it contributes
"MCAL/ssc/irq/src/Adc_Irq.src":"../MCAL/ssc/irq/src/Adc_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Adc_Irq.o":"MCAL/ssc/irq/src/Adc_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/AscLin_Irq.src":"../MCAL/ssc/irq/src/AscLin_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/AscLin_Irq.o":"MCAL/ssc/irq/src/AscLin_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Can_Irq.src":"../MCAL/ssc/irq/src/Can_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Can_Irq.o":"MCAL/ssc/irq/src/Can_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Ccu6_Irq.src":"../MCAL/ssc/irq/src/Ccu6_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Ccu6_Irq.o":"MCAL/ssc/irq/src/Ccu6_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Dma_Irq.src":"../MCAL/ssc/irq/src/Dma_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Dma_Irq.o":"MCAL/ssc/irq/src/Dma_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Eru_Irq.src":"../MCAL/ssc/irq/src/Eru_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Eru_Irq.o":"MCAL/ssc/irq/src/Eru_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Gtm_Irq.src":"../MCAL/ssc/irq/src/Gtm_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Gtm_Irq.o":"MCAL/ssc/irq/src/Gtm_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Spi_Irq.src":"../MCAL/ssc/irq/src/Spi_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Spi_Irq.o":"MCAL/ssc/irq/src/Spi_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/Stm_Irq.src":"../MCAL/ssc/irq/src/Stm_Irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/Stm_Irq.o":"MCAL/ssc/irq/src/Stm_Irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/irq/src/irq.src":"../MCAL/ssc/irq/src/irq.c" "MCAL/ssc/irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/irq/src/irq.o":"MCAL/ssc/irq/src/irq.src" "MCAL/ssc/irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MCAL-2f-ssc-2f-irq-2f-src

clean-MCAL-2f-ssc-2f-irq-2f-src:
	-$(RM) ./MCAL/ssc/irq/src/Adc_Irq.d ./MCAL/ssc/irq/src/Adc_Irq.o ./MCAL/ssc/irq/src/Adc_Irq.src ./MCAL/ssc/irq/src/AscLin_Irq.d ./MCAL/ssc/irq/src/AscLin_Irq.o ./MCAL/ssc/irq/src/AscLin_Irq.src ./MCAL/ssc/irq/src/Can_Irq.d ./MCAL/ssc/irq/src/Can_Irq.o ./MCAL/ssc/irq/src/Can_Irq.src ./MCAL/ssc/irq/src/Ccu6_Irq.d ./MCAL/ssc/irq/src/Ccu6_Irq.o ./MCAL/ssc/irq/src/Ccu6_Irq.src ./MCAL/ssc/irq/src/Dma_Irq.d ./MCAL/ssc/irq/src/Dma_Irq.o ./MCAL/ssc/irq/src/Dma_Irq.src ./MCAL/ssc/irq/src/Eru_Irq.d ./MCAL/ssc/irq/src/Eru_Irq.o ./MCAL/ssc/irq/src/Eru_Irq.src ./MCAL/ssc/irq/src/Gtm_Irq.d ./MCAL/ssc/irq/src/Gtm_Irq.o ./MCAL/ssc/irq/src/Gtm_Irq.src ./MCAL/ssc/irq/src/Spi_Irq.d ./MCAL/ssc/irq/src/Spi_Irq.o ./MCAL/ssc/irq/src/Spi_Irq.src ./MCAL/ssc/irq/src/Stm_Irq.d ./MCAL/ssc/irq/src/Stm_Irq.o ./MCAL/ssc/irq/src/Stm_Irq.src ./MCAL/ssc/irq/src/irq.d ./MCAL/ssc/irq/src/irq.o ./MCAL/ssc/irq/src/irq.src

.PHONY: clean-MCAL-2f-ssc-2f-irq-2f-src

