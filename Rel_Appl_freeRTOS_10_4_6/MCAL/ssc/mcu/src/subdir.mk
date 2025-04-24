################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../MCAL/ssc/mcu/src/Gtm.c" \
"../MCAL/ssc/mcu/src/Gtm_Platform.c" \
"../MCAL/ssc/mcu/src/Mcu.c" \
"../MCAL/ssc/mcu/src/Mcu_Dma.c" \
"../MCAL/ssc/mcu/src/Mcu_Platform.c" 

COMPILED_SRCS += \
"MCAL/ssc/mcu/src/Gtm.src" \
"MCAL/ssc/mcu/src/Gtm_Platform.src" \
"MCAL/ssc/mcu/src/Mcu.src" \
"MCAL/ssc/mcu/src/Mcu_Dma.src" \
"MCAL/ssc/mcu/src/Mcu_Platform.src" 

C_DEPS += \
"./MCAL/ssc/mcu/src/Gtm.d" \
"./MCAL/ssc/mcu/src/Gtm_Platform.d" \
"./MCAL/ssc/mcu/src/Mcu.d" \
"./MCAL/ssc/mcu/src/Mcu_Dma.d" \
"./MCAL/ssc/mcu/src/Mcu_Platform.d" 

OBJS += \
"MCAL/ssc/mcu/src/Gtm.o" \
"MCAL/ssc/mcu/src/Gtm_Platform.o" \
"MCAL/ssc/mcu/src/Mcu.o" \
"MCAL/ssc/mcu/src/Mcu_Dma.o" \
"MCAL/ssc/mcu/src/Mcu_Platform.o" 


# Each subdirectory must supply rules for building sources it contributes
"MCAL/ssc/mcu/src/Gtm.src":"../MCAL/ssc/mcu/src/Gtm.c" "MCAL/ssc/mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/mcu/src/Gtm.o":"MCAL/ssc/mcu/src/Gtm.src" "MCAL/ssc/mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/mcu/src/Gtm_Platform.src":"../MCAL/ssc/mcu/src/Gtm_Platform.c" "MCAL/ssc/mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/mcu/src/Gtm_Platform.o":"MCAL/ssc/mcu/src/Gtm_Platform.src" "MCAL/ssc/mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/mcu/src/Mcu.src":"../MCAL/ssc/mcu/src/Mcu.c" "MCAL/ssc/mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/mcu/src/Mcu.o":"MCAL/ssc/mcu/src/Mcu.src" "MCAL/ssc/mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/mcu/src/Mcu_Dma.src":"../MCAL/ssc/mcu/src/Mcu_Dma.c" "MCAL/ssc/mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/mcu/src/Mcu_Dma.o":"MCAL/ssc/mcu/src/Mcu_Dma.src" "MCAL/ssc/mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/mcu/src/Mcu_Platform.src":"../MCAL/ssc/mcu/src/Mcu_Platform.c" "MCAL/ssc/mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/mcu/src/Mcu_Platform.o":"MCAL/ssc/mcu/src/Mcu_Platform.src" "MCAL/ssc/mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MCAL-2f-ssc-2f-mcu-2f-src

clean-MCAL-2f-ssc-2f-mcu-2f-src:
	-$(RM) ./MCAL/ssc/mcu/src/Gtm.d ./MCAL/ssc/mcu/src/Gtm.o ./MCAL/ssc/mcu/src/Gtm.src ./MCAL/ssc/mcu/src/Gtm_Platform.d ./MCAL/ssc/mcu/src/Gtm_Platform.o ./MCAL/ssc/mcu/src/Gtm_Platform.src ./MCAL/ssc/mcu/src/Mcu.d ./MCAL/ssc/mcu/src/Mcu.o ./MCAL/ssc/mcu/src/Mcu.src ./MCAL/ssc/mcu/src/Mcu_Dma.d ./MCAL/ssc/mcu/src/Mcu_Dma.o ./MCAL/ssc/mcu/src/Mcu_Dma.src ./MCAL/ssc/mcu/src/Mcu_Platform.d ./MCAL/ssc/mcu/src/Mcu_Platform.o ./MCAL/ssc/mcu/src/Mcu_Platform.src

.PHONY: clean-MCAL-2f-ssc-2f-mcu-2f-src

