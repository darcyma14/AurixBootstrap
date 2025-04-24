################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../MCAL/ssc/icu/src/Icu_17_GtmCcu6.c" \
"../MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.c" \
"../MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.c" 

COMPILED_SRCS += \
"MCAL/ssc/icu/src/Icu_17_GtmCcu6.src" \
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.src" \
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.src" 

C_DEPS += \
"./MCAL/ssc/icu/src/Icu_17_GtmCcu6.d" \
"./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.d" \
"./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.d" 

OBJS += \
"MCAL/ssc/icu/src/Icu_17_GtmCcu6.o" \
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.o" \
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.o" 


# Each subdirectory must supply rules for building sources it contributes
"MCAL/ssc/icu/src/Icu_17_GtmCcu6.src":"../MCAL/ssc/icu/src/Icu_17_GtmCcu6.c" "MCAL/ssc/icu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/icu/src/Icu_17_GtmCcu6.o":"MCAL/ssc/icu/src/Icu_17_GtmCcu6.src" "MCAL/ssc/icu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.src":"../MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.c" "MCAL/ssc/icu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.o":"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.src" "MCAL/ssc/icu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.src":"../MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.c" "MCAL/ssc/icu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.o":"MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.src" "MCAL/ssc/icu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MCAL-2f-ssc-2f-icu-2f-src

clean-MCAL-2f-ssc-2f-icu-2f-src:
	-$(RM) ./MCAL/ssc/icu/src/Icu_17_GtmCcu6.d ./MCAL/ssc/icu/src/Icu_17_GtmCcu6.o ./MCAL/ssc/icu/src/Icu_17_GtmCcu6.src ./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.d ./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.o ./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Safe.src ./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.d ./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.o ./MCAL/ssc/icu/src/Icu_17_GtmCcu6_Ver.src

.PHONY: clean-MCAL-2f-ssc-2f-icu-2f-src

