################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../MCAL/ssc/can/src/Can_17_MCanP.c" 

COMPILED_SRCS += \
"MCAL/ssc/can/src/Can_17_MCanP.src" 

C_DEPS += \
"./MCAL/ssc/can/src/Can_17_MCanP.d" 

OBJS += \
"MCAL/ssc/can/src/Can_17_MCanP.o" 


# Each subdirectory must supply rules for building sources it contributes
"MCAL/ssc/can/src/Can_17_MCanP.src":"../MCAL/ssc/can/src/Can_17_MCanP.c" "MCAL/ssc/can/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/can/src/Can_17_MCanP.o":"MCAL/ssc/can/src/Can_17_MCanP.src" "MCAL/ssc/can/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MCAL-2f-ssc-2f-can-2f-src

clean-MCAL-2f-ssc-2f-can-2f-src:
	-$(RM) ./MCAL/ssc/can/src/Can_17_MCanP.d ./MCAL/ssc/can/src/Can_17_MCanP.o ./MCAL/ssc/can/src/Can_17_MCanP.src

.PHONY: clean-MCAL-2f-ssc-2f-can-2f-src

