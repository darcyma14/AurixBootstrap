################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../APP/src/AppAdc.c" \
"../APP/src/AppCan.c" \
"../APP/src/AppDio.c" \
"../APP/src/AppIcu.c" \
"../APP/src/AppUart.c" \
"../APP/src/Debug.c" \
"../APP/src/Helper.c" \
"../APP/src/LSD_TLE8110ED.c" \
"../APP/src/Main.c" \
"../APP/src/PMIC_TLF35584.c" \
"../APP/src/SC900719.c" \
"../APP/src/TLT9255.c" \
"../APP/src/Ymodem.c" 

COMPILED_SRCS += \
"APP/src/AppAdc.src" \
"APP/src/AppCan.src" \
"APP/src/AppDio.src" \
"APP/src/AppIcu.src" \
"APP/src/AppUart.src" \
"APP/src/Debug.src" \
"APP/src/Helper.src" \
"APP/src/LSD_TLE8110ED.src" \
"APP/src/Main.src" \
"APP/src/PMIC_TLF35584.src" \
"APP/src/SC900719.src" \
"APP/src/TLT9255.src" \
"APP/src/Ymodem.src" 

C_DEPS += \
"./APP/src/AppAdc.d" \
"./APP/src/AppCan.d" \
"./APP/src/AppDio.d" \
"./APP/src/AppIcu.d" \
"./APP/src/AppUart.d" \
"./APP/src/Debug.d" \
"./APP/src/Helper.d" \
"./APP/src/LSD_TLE8110ED.d" \
"./APP/src/Main.d" \
"./APP/src/PMIC_TLF35584.d" \
"./APP/src/SC900719.d" \
"./APP/src/TLT9255.d" \
"./APP/src/Ymodem.d" 

OBJS += \
"APP/src/AppAdc.o" \
"APP/src/AppCan.o" \
"APP/src/AppDio.o" \
"APP/src/AppIcu.o" \
"APP/src/AppUart.o" \
"APP/src/Debug.o" \
"APP/src/Helper.o" \
"APP/src/LSD_TLE8110ED.o" \
"APP/src/Main.o" \
"APP/src/PMIC_TLF35584.o" \
"APP/src/SC900719.o" \
"APP/src/TLT9255.o" \
"APP/src/Ymodem.o" 


# Each subdirectory must supply rules for building sources it contributes
"APP/src/AppAdc.src":"../APP/src/AppAdc.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/AppAdc.o":"APP/src/AppAdc.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/AppCan.src":"../APP/src/AppCan.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/AppCan.o":"APP/src/AppCan.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/AppDio.src":"../APP/src/AppDio.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/AppDio.o":"APP/src/AppDio.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/AppIcu.src":"../APP/src/AppIcu.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/AppIcu.o":"APP/src/AppIcu.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/AppUart.src":"../APP/src/AppUart.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/AppUart.o":"APP/src/AppUart.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/Debug.src":"../APP/src/Debug.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/Debug.o":"APP/src/Debug.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/Helper.src":"../APP/src/Helper.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/Helper.o":"APP/src/Helper.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/LSD_TLE8110ED.src":"../APP/src/LSD_TLE8110ED.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/LSD_TLE8110ED.o":"APP/src/LSD_TLE8110ED.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/Main.src":"../APP/src/Main.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/Main.o":"APP/src/Main.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/PMIC_TLF35584.src":"../APP/src/PMIC_TLF35584.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/PMIC_TLF35584.o":"APP/src/PMIC_TLF35584.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/SC900719.src":"../APP/src/SC900719.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/SC900719.o":"APP/src/SC900719.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/TLT9255.src":"../APP/src/TLT9255.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/TLT9255.o":"APP/src/TLT9255.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"APP/src/Ymodem.src":"../APP/src/Ymodem.c" "APP/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/src/Ymodem.o":"APP/src/Ymodem.src" "APP/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-APP-2f-src

clean-APP-2f-src:
	-$(RM) ./APP/src/AppAdc.d ./APP/src/AppAdc.o ./APP/src/AppAdc.src ./APP/src/AppCan.d ./APP/src/AppCan.o ./APP/src/AppCan.src ./APP/src/AppDio.d ./APP/src/AppDio.o ./APP/src/AppDio.src ./APP/src/AppIcu.d ./APP/src/AppIcu.o ./APP/src/AppIcu.src ./APP/src/AppUart.d ./APP/src/AppUart.o ./APP/src/AppUart.src ./APP/src/Debug.d ./APP/src/Debug.o ./APP/src/Debug.src ./APP/src/Helper.d ./APP/src/Helper.o ./APP/src/Helper.src ./APP/src/LSD_TLE8110ED.d ./APP/src/LSD_TLE8110ED.o ./APP/src/LSD_TLE8110ED.src ./APP/src/Main.d ./APP/src/Main.o ./APP/src/Main.src ./APP/src/PMIC_TLF35584.d ./APP/src/PMIC_TLF35584.o ./APP/src/PMIC_TLF35584.src ./APP/src/SC900719.d ./APP/src/SC900719.o ./APP/src/SC900719.src ./APP/src/TLT9255.d ./APP/src/TLT9255.o ./APP/src/TLT9255.src ./APP/src/Ymodem.d ./APP/src/Ymodem.o ./APP/src/Ymodem.src

.PHONY: clean-APP-2f-src

