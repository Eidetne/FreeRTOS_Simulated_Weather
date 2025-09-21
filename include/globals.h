#ifndef GLOBALS_H
#define GLOBALS_H

#include "FreeRTOS.h"
#include "queue.h"
#include "event_groups.h"

/* Déclaration externe des handles globaux */
extern QueueHandle_t xSensorQueue;
extern QueueHandle_t xAlertQueue;
extern EventGroupHandle_t xSystemHealth;

#endif /* GLOBALS_H */