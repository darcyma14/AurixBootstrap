################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../FreeRTOS_V10_4_6/Source/croutine.c" \
"../FreeRTOS_V10_4_6/Source/event_groups.c" \
"../FreeRTOS_V10_4_6/Source/list.c" \
"../FreeRTOS_V10_4_6/Source/queue.c" \
"../FreeRTOS_V10_4_6/Source/stream_buffer.c" \
"../FreeRTOS_V10_4_6/Source/tasks.c" \
"../FreeRTOS_V10_4_6/Source/timers.c" 

COMPILED_SRCS += \
"FreeRTOS_V10_4_6/Source/croutine.src" \
"FreeRTOS_V10_4_6/Source/event_groups.src" \
"FreeRTOS_V10_4_6/Source/list.src" \
"FreeRTOS_V10_4_6/Source/queue.src" \
"FreeRTOS_V10_4_6/Source/stream_buffer.src" \
"FreeRTOS_V10_4_6/Source/tasks.src" \
"FreeRTOS_V10_4_6/Source/timers.src" 

C_DEPS += \
"./FreeRTOS_V10_4_6/Source/croutine.d" \
"./FreeRTOS_V10_4_6/Source/event_groups.d" \
"./FreeRTOS_V10_4_6/Source/list.d" \
"./FreeRTOS_V10_4_6/Source/queue.d" \
"./FreeRTOS_V10_4_6/Source/stream_buffer.d" \
"./FreeRTOS_V10_4_6/Source/tasks.d" \
"./FreeRTOS_V10_4_6/Source/timers.d" 

OBJS += \
"FreeRTOS_V10_4_6/Source/croutine.o" \
"FreeRTOS_V10_4_6/Source/event_groups.o" \
"FreeRTOS_V10_4_6/Source/list.o" \
"FreeRTOS_V10_4_6/Source/queue.o" \
"FreeRTOS_V10_4_6/Source/stream_buffer.o" \
"FreeRTOS_V10_4_6/Source/tasks.o" \
"FreeRTOS_V10_4_6/Source/timers.o" 


# Each subdirectory must supply rules for building sources it contributes
"FreeRTOS_V10_4_6/Source/croutine.src":"../FreeRTOS_V10_4_6/Source/croutine.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/croutine.o":"FreeRTOS_V10_4_6/Source/croutine.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"FreeRTOS_V10_4_6/Source/event_groups.src":"../FreeRTOS_V10_4_6/Source/event_groups.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/event_groups.o":"FreeRTOS_V10_4_6/Source/event_groups.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"FreeRTOS_V10_4_6/Source/list.src":"../FreeRTOS_V10_4_6/Source/list.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/list.o":"FreeRTOS_V10_4_6/Source/list.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"FreeRTOS_V10_4_6/Source/queue.src":"../FreeRTOS_V10_4_6/Source/queue.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/queue.o":"FreeRTOS_V10_4_6/Source/queue.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"FreeRTOS_V10_4_6/Source/stream_buffer.src":"../FreeRTOS_V10_4_6/Source/stream_buffer.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/stream_buffer.o":"FreeRTOS_V10_4_6/Source/stream_buffer.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"FreeRTOS_V10_4_6/Source/tasks.src":"../FreeRTOS_V10_4_6/Source/tasks.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/tasks.o":"FreeRTOS_V10_4_6/Source/tasks.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"FreeRTOS_V10_4_6/Source/timers.src":"../FreeRTOS_V10_4_6/Source/timers.c" "FreeRTOS_V10_4_6/Source/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc23x -D_APP_KIT_BOARD_ -D_FREE_TASKING_C_COMPILER_=1 -D_TASKING_C_TRICORE_=1 -D_McalModified_ "-fC:/Havana/workspace/AURIX/CliDemo/Rel_Appl_freeRTOS_10_4_6/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc23x -Y0 -N0 -Z0 -o "$@" "$<"
"FreeRTOS_V10_4_6/Source/timers.o":"FreeRTOS_V10_4_6/Source/timers.src" "FreeRTOS_V10_4_6/Source/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-FreeRTOS_V10_4_6-2f-Source

clean-FreeRTOS_V10_4_6-2f-Source:
	-$(RM) ./FreeRTOS_V10_4_6/Source/croutine.d ./FreeRTOS_V10_4_6/Source/croutine.o ./FreeRTOS_V10_4_6/Source/croutine.src ./FreeRTOS_V10_4_6/Source/event_groups.d ./FreeRTOS_V10_4_6/Source/event_groups.o ./FreeRTOS_V10_4_6/Source/event_groups.src ./FreeRTOS_V10_4_6/Source/list.d ./FreeRTOS_V10_4_6/Source/list.o ./FreeRTOS_V10_4_6/Source/list.src ./FreeRTOS_V10_4_6/Source/queue.d ./FreeRTOS_V10_4_6/Source/queue.o ./FreeRTOS_V10_4_6/Source/queue.src ./FreeRTOS_V10_4_6/Source/stream_buffer.d ./FreeRTOS_V10_4_6/Source/stream_buffer.o ./FreeRTOS_V10_4_6/Source/stream_buffer.src ./FreeRTOS_V10_4_6/Source/tasks.d ./FreeRTOS_V10_4_6/Source/tasks.o ./FreeRTOS_V10_4_6/Source/tasks.src ./FreeRTOS_V10_4_6/Source/timers.d ./FreeRTOS_V10_4_6/Source/timers.o ./FreeRTOS_V10_4_6/Source/timers.src

.PHONY: clean-FreeRTOS_V10_4_6-2f-Source

