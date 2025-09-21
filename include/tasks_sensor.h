#ifndef TASKS_SENSOR_H
#define TASKS_SENSOR_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"

/* Structure capteur */
typedef struct {
    int temperature;
    int humidity;
} SensorData;

/* Prototypes */
void vTaskSensor(void *pvParameters);
void vSimulatedButtonISR(void);  // Prototype

#endif
