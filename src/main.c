#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "event_groups.h"
#include "queue.h"

/* Inclusions des modules */
#include "tasks_sensor.h"
#include "tasks_processing.h"
#include "tasks_comm.h"
#include "tasks_watchdog.h"
#include "isr_simulated.h"
#include "FreeRTOSConfig.h"
#include "globals.h"

/* Handles globaux */
QueueHandle_t xSensorQueue;
QueueHandle_t xAlertQueue;
EventGroupHandle_t xSystemHealth;

/* Timers */
TimerHandle_t xSensorTimer;
TimerHandle_t xButtonTimer;

/* Prototypes */
void vSensorTimerCallback(TimerHandle_t xTimer);
void vButtonTimerCallback(TimerHandle_t xTimer);

int main(void) {
    printf("=== FreeRTOS Simulation (Weather Node) ===\n");

    /* Files & EventGroup */
    xSensorQueue = xQueueCreate(5, sizeof(SensorData));
    xAlertQueue  = xQueueCreate(5, sizeof(char[50]));
    xSystemHealth = xEventGroupCreate();

    /* Tâches */
    TaskHandle_t xSensorTaskHandle = NULL;
    xTaskCreate(vTaskSensor, "Sensor", configMINIMAL_STACK_SIZE + 100, NULL, 3, &xSensorTaskHandle);
    xTaskCreate(vTaskProcessing, "Processing", configMINIMAL_STACK_SIZE + 100, NULL, 2, NULL);
    xTaskCreate(vTaskComm, "Comm", configMINIMAL_STACK_SIZE + 100, NULL, 1, NULL);
    // xTaskCreate(vTaskWatchdog, "Watchdog", configMINIMAL_STACK_SIZE + 100, NULL, 1, NULL);
    xTaskCreate(vTaskWatchdog, "Watchdog", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    /* Timers */
    xSensorTimer = xTimerCreate("SensorTimer",
                                pdMS_TO_TICKS(SENSOR_PERIOD_MS),
                                pdTRUE,
                                (void *) xSensorTaskHandle,
                                vSensorTimerCallback);

    xButtonTimer = xTimerCreate("ButtonTimer",
                                pdMS_TO_TICKS(7000),
                                pdTRUE,
                                NULL,
                                vButtonTimerCallback);

    xTimerStart(xSensorTimer, 0);
    xTimerStart(xButtonTimer, 0);

    vTaskStartScheduler();
    for (;;);
    return 0;
}

/* Callbacks */
void vSensorTimerCallback(TimerHandle_t xTimer) {
    TaskHandle_t xSensorTask = (TaskHandle_t) pvTimerGetTimerID(xTimer);
    xTaskNotifyGive(xSensorTask);
}

void vButtonTimerCallback(TimerHandle_t xTimer) {
    vSimulatedButtonISR();
}
