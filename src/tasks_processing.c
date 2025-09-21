#include <stdio.h>
#include "tasks_processing.h"
#include "FreeRTOSConfig.h"
#include "globals.h"

void vTaskProcessing(void *pvParameters) {
    SensorData data;
    for (;;) {
        if (xQueueReceive(xSensorQueue, &data, portMAX_DELAY) == pdPASS) {
            if (data.temperature > 30) {
                char msg[50];
                snprintf(msg, sizeof(msg), "ALERT: Temp=%d°C\n", data.temperature);
                xQueueSend(xAlertQueue, msg, 0);
            }
            xEventGroupSetBits(xSystemHealth, BIT_PROCESS);
        }
    }
}
