#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "tasks_sensor.h"
#include "task.h"
#include "event_groups.h"
#include "globals.h"

void vTaskSensor(void *pvParameters) {
    SensorData data;
    srand(time(NULL));

    for (;;) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        data.temperature = (rand() % 15) + 20; // 20..35
        data.humidity    = (rand() % 50) + 30; // 30..80

        xQueueSend(xSensorQueue, &data, 0);
        xEventGroupSetBits(xSystemHealth, BIT_SENSOR);
    }
}
