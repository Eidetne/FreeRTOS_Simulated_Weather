#include <stdio.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "event_groups.h"
#include "FreeRTOSConfig.h"
#include "isr_simulated.h"
#include "globals.h"

// Déclarer que la variable existe ailleurs
// extern BaseType_t xInsideInterrupt;

// Déclarer la queue comme externe
//extern QueueHandle_t xAlertQueue;

void vSimulatedButtonISR(void) {
    char msg[50];
    snprintf(msg, sizeof(msg), "Button pressed! Manual sample request.\n");
    xQueueSendFromISR(xAlertQueue, msg, NULL);
}
