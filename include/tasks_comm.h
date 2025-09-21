#ifndef TASKS_COMM_H
#define TASKS_COMM_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"

/* Prototypes */
void vTaskComm(void *pvParameters);

#endif