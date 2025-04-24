################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/integration_general/src/CanIf_Cbk.c" \
"../BSW/integration_general/src/Det.c" \
"../BSW/integration_general/src/SchM.c" \
"../BSW/integration_general/src/Test_Print.c" \
"../BSW/integration_general/src/Test_Time.c" 

COMPILED_SRCS += \
"BSW/integration_general/src/CanIf_Cbk.src" \
"BSW/integration_general/src/Det.src" \
"BSW/integration_general/src/SchM.src" \
"BSW/integration_general/src/Test_Print.src" \
"BSW/integration_general/src/Test_Time.src" 

C_DEPS += \
"./BSW/integration_general/src/CanIf_Cbk.d" \
"./BSW/integration_general/src/Det.d" \
"./BSW/integration_general/src/SchM.d" \
"./BSW/integration_general/src/Test_Print.d" \
"./BSW/integration_general/src/Test_Time.d" 

OBJS += \
"BSW/integration_general/src/CanIf_Cbk.o" \
"BSW/integration_general/src/Det.o" \
"BSW/integration_general/src/SchM.o" \
"BSW/integration_general/src/Test_Print.o" \
"BSW/integration_general/src/Test_Time.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/integration_general/src/CanIf_Cbk.src":"../BSW/integration_general/src/CanIf_Cbk.c" "BSW/integration_general/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/integration_general/src/CanIf_Cbk.o":"BSW/integration_general/src/CanIf_Cbk.src" "BSW/integration_general/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/integration_general/src/Det.src":"../BSW/integration_general/src/Det.c" "BSW/integration_general/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/integration_general/src/Det.o":"BSW/integration_general/src/Det.src" "BSW/integration_general/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/integration_general/src/SchM.src":"../BSW/integration_general/src/SchM.c" "BSW/integration_general/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/integration_general/src/SchM.o":"BSW/integration_general/src/SchM.src" "BSW/integration_general/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/integration_general/src/Test_Print.src":"../BSW/integration_general/src/Test_Print.c" "BSW/integration_general/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/integration_general/src/Test_Print.o":"BSW/integration_general/src/Test_Print.src" "BSW/integration_general/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/integration_general/src/Test_Time.src":"../BSW/integration_general/src/Test_Time.c" "BSW/integration_general/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/integration_general/src/Test_Time.o":"BSW/integration_general/src/Test_Time.src" "BSW/integration_general/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-integration_general-2f-src

clean-BSW-2f-integration_general-2f-src:
	-$(RM) ./BSW/integration_general/src/CanIf_Cbk.d ./BSW/integration_general/src/CanIf_Cbk.o ./BSW/integration_general/src/CanIf_Cbk.src ./BSW/integration_general/src/Det.d ./BSW/integration_general/src/Det.o ./BSW/integration_general/src/Det.src ./BSW/integration_general/src/SchM.d ./BSW/integration_general/src/SchM.o ./BSW/integration_general/src/SchM.src ./BSW/integration_general/src/Test_Print.d ./BSW/integration_general/src/Test_Print.o ./BSW/integration_general/src/Test_Print.src ./BSW/integration_general/src/Test_Time.d ./BSW/integration_general/src/Test_Time.o ./BSW/integration_general/src/Test_Time.src

.PHONY: clean-BSW-2f-integration_general-2f-src

