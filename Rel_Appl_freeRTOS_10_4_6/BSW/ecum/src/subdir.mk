################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/ecum/src/EcuM.c" \
"../BSW/ecum/src/EcuM_Callout_Stubs.c" 

COMPILED_SRCS += \
"BSW/ecum/src/EcuM.src" \
"BSW/ecum/src/EcuM_Callout_Stubs.src" 

C_DEPS += \
"./BSW/ecum/src/EcuM.d" \
"./BSW/ecum/src/EcuM_Callout_Stubs.d" 

OBJS += \
"BSW/ecum/src/EcuM.o" \
"BSW/ecum/src/EcuM_Callout_Stubs.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/ecum/src/EcuM.src":"../BSW/ecum/src/EcuM.c" "BSW/ecum/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ecum/src/EcuM.o":"BSW/ecum/src/EcuM.src" "BSW/ecum/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/ecum/src/EcuM_Callout_Stubs.src":"../BSW/ecum/src/EcuM_Callout_Stubs.c" "BSW/ecum/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/ecum/src/EcuM_Callout_Stubs.o":"BSW/ecum/src/EcuM_Callout_Stubs.src" "BSW/ecum/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-ecum-2f-src

clean-BSW-2f-ecum-2f-src:
	-$(RM) ./BSW/ecum/src/EcuM.d ./BSW/ecum/src/EcuM.o ./BSW/ecum/src/EcuM.src ./BSW/ecum/src/EcuM_Callout_Stubs.d ./BSW/ecum/src/EcuM_Callout_Stubs.o ./BSW/ecum/src/EcuM_Callout_Stubs.src

.PHONY: clean-BSW-2f-ecum-2f-src

