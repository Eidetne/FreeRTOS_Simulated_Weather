#ifndef ISR_SIMULATED_H
#define ISR_SIMULATED_H

#include "FreeRTOS.h"
#include "queue.h"
#include "event_groups.h"
#include "FreeRTOSConfig.h"

/* Déclaration de la fonction ISR simulée */
void vSimulatedButtonISR(void);

#endif /* ISR_SIMULATED_H */
