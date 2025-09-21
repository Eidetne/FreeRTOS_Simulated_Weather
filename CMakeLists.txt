cmake_minimum_required(VERSION 3.15)
project(FreeRTOS_Simulated_Weather C)

set(CMAKE_C_STANDARD 99)

# Ajouter les dossiers d'include
include_directories(
    include
    config
    ../FreeRTOS-Kernel/include
    ../FreeRTOS-Kernel/portable/MSVC-MingW
    ../FreeRTOS-Kernel/portable/MemMang
)

# Fichiers sources du projet
set(SOURCES
    src/main.c
    src/tasks_sensor.c
    src/tasks_processing.c
    src/tasks_comm.c
    src/tasks_watchdog.c
    src/isr_simulated.c

    # FreeRTOS Kernel
    ../FreeRTOS-Kernel/queue.c
    ../FreeRTOS-Kernel/tasks.c
    ../FreeRTOS-Kernel/event_groups.c
    ../FreeRTOS-Kernel/list.c
    ../FreeRTOS-Kernel/timers.c 
    ../FreeRTOS-Kernel/portable/MSVC-MingW/port.c
    ../FreeRTOS-Kernel/portable/MemMang/heap_4.c  # <- pour pvPortMalloc / vPortFree
)

# Créer l'exécutable
add_executable(FreeRTOS_Simulated_Weather ${SOURCES})

# Linker avec Threads et winmm (pour timeBeginPeriod etc.)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(FreeRTOS_Simulated_Weather Threads::Threads winmm)




