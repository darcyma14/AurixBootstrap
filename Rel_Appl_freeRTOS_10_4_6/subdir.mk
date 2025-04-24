################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Debug.c" 

COMPILED_SRCS += \
"Debug.src" 

C_DEPS += \
"./Debug.d" 

OBJS += \
"Debug.o" 


# Each subdirectory must supply rules for building sources it contributes
"Debug.src":"../Debug.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"Debug.o":"Debug.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) ./Debug.d ./Debug.o ./Debug.src

.PHONY: clean--2e-

