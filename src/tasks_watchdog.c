#include <stdio.h>
#include "tasks_watchdog.h"
#include "FreeRTOSConfig.h"
#include "globals.h"


void vTaskWatchdog(void *pvParameters) {
    const EventBits_t allTasks = BIT_SENSOR | BIT_PROCESS | BIT_COMM;
    const TickType_t initialDelay = pdMS_TO_TICKS(2000); // délai initial
    EventBits_t uxBits;
    TickType_t tickCount;
    int cycle = 0;

    printf("[Watchdog] Starting monitoring...\n");
    vTaskDelay(initialDelay);  // laisser le système démarrer

    for (;;) {
        vTaskDelay(pdMS_TO_TICKS(WATCHDOG_PERIOD_MS));
        tickCount = xTaskGetTickCount();  // compteur de ticks depuis le démarrage
        cycle++;

        uxBits = xEventGroupGetBits(xSystemHealth);

        if ((uxBits & allTasks) == allTasks) {
            printf("[Watchdog] Tick %lu | Cycle %d | System healthy\n", tickCount, cycle);
        } else {
            printf("[Watchdog] Tick %lu | Cycle %d | SYSTEM FAILURE detected!\n", tickCount, cycle);
        }

        xEventGroupClearBits(xSystemHealth, allTasks);
    }
}



