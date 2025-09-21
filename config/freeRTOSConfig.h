#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION            1
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configCPU_CLOCK_HZ              ( 1000000 )
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES            5
#define configMINIMAL_STACK_SIZE        128
#define configTOTAL_HEAP_SIZE           ( 20 * 1024 )
#define configMAX_TASK_NAME_LEN         16
#define configUSE_16_BIT_TICKS          0
#define configIDLE_SHOULD_YIELD         1

// Périodes des tâches
#define SENSOR_PERIOD_MS 1000
#define WATCHDOG_PERIOD_MS 500
#define PROCESSING_PERIOD_MS 200

// Event bits
#define BIT_SENSOR   (1 << 0)
#define BIT_PROCESS  (1 << 1)
#define BIT_COMM     (1 << 2)
#define BIT_WATCHDOG (1 << 3)

// Allocation dynamique
#define configSUPPORT_DYNAMIC_ALLOCATION 1

// Event groups
#define configUSE_EVENT_GROUPS          1

// Timers
#define configUSE_TIMERS                1           // <- IMPORTANT pour activer les timers
#define configTIMER_TASK_PRIORITY       (tskIDLE_PRIORITY + 1)
#define configTIMER_QUEUE_LENGTH        10
#define configTIMER_TASK_STACK_DEPTH    (configMINIMAL_STACK_SIZE * 2)

// Fonctions incluses
#define INCLUDE_vTaskDelay              1
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle 1
#define INCLUDE_xTimerPendFunctionCall        1
#define INCLUDE_xTimerGetTimerID              1
#define INCLUDE_xTimerIsTimerActive           1
#define INCLUDE_xTimerStart                   1
#define INCLUDE_xTimerStop                    1
#define INCLUDE_xTimerReset                   1
#define INCLUDE_xTimerChangePeriod            1

#endif /* FREERTOS_CONFIG_H */