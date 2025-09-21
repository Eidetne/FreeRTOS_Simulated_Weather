#ifndef TASKS_WATCHDOG_H
#define TASKS_WATCHDOG_H

#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "FreeRTOSConfig.h"

/* Prototypes */
void vTaskWatchdog(void *pvParameters);

#endif