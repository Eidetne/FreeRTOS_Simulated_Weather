#include <stdio.h>
#include "tasks_comm.h"
#include "FreeRTOSConfig.h"
#include "globals.h"

void vTaskComm(void *pvParameters) {
    char msg[50];
    for (;;) {
        if (xQueueReceive(xAlertQueue, &msg, portMAX_DELAY) == pdPASS) {
            printf("[Comm] %s", msg);
        }
        xEventGroupSetBits(xSystemHealth, BIT_COMM);
    }
}

// QueueHandle_t xAlertQueue;

void setupQueues() {
    xAlertQueue = xQueueCreate(10, sizeof(int)); // ou le type de message utilisé
}
