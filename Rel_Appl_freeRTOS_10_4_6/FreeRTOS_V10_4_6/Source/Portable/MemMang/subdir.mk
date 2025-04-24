################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.c" 

COMPILED_SRCS += \
"FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.src" 

C_DEPS += \
"./FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.d" 

OBJS += \
"FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.o" 


# Each subdirectory must supply rules for building sources it contributes
"FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.src":"../FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.c" "FreeRTOS_V10_4_6/Source/Portable/MemMang/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.o":"FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.src" "FreeRTOS_V10_4_6/Source/Portable/MemMang/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-FreeRTOS_V10_4_6-2f-Source-2f-Portable-2f-MemMang

clean-FreeRTOS_V10_4_6-2f-Source-2f-Portable-2f-MemMang:
	-$(RM) ./FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.d ./FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.o ./FreeRTOS_V10_4_6/Source/Portable/MemMang/heap_1.src

.PHONY: clean-FreeRTOS_V10_4_6-2f-Source-2f-Portable-2f-MemMang

