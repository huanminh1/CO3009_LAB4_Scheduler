# MICROCONTROLLER - MICROPROCESSOR  
## LABORATORY 4: LAB4_SCHEDULER
## 1. Introduction
Hi everyone, this is the ReadMe file for the Laboratory 4: Scheduler. This project implements a **cooperative scheduler** on the STM32F103C6 microcontroller. The scheduler manages multiple periodic and one-shot tasks using a timer interrupt (tick = 10ms), and demonstrates basic embedded system design principles such as function pointers, task management, and modular programming. The project is designed for educational purposes and is simulated using Proteus.

## 2. Video Demonstration:
- link:

<<<<<<< HEAD
**Scheduler simulation**
=======
>>>>>>> ce375fd17ae30064d4105801184edbc33920a207
![Scheduler](Image/Scheduler%20demo.png)

## 3. Schematic
The hardware setup is simulated in **Proteus 8.10** using the STM32F103C6 microcontroller.  
![Proteus Simulation](Image/Proteus%20Schematic.png)

**Explanation:**
- **7-Segment Display:** Connected to GPIO pins to show the time (using timer interrupt). I use this to check that if scheduler works right timly.
- **LEDs:** Five LEDs are connected to GPIO pins, each controlled by a separate task in the scheduler.
- ULN2003A is used as a driver for the 7-segment display to handle the current requirements.

## 4. Configuration in STM32CubeIDE
- **Timer:** Configured with prescaler = 7999, counter = 9 (TICK = 10 ms)
- **Clock:** Default system clock configuration
- **Peripherals:** GPIO for 7-segment display, 5 LED tasks and other I/O as required

### .ioc File Configuration
<p align="center">
  <img src="Image/.ioc%20file.png" alt="STM32CubeIDE Configuration">
</p>

## 5. Implementation Details
The scheduler is implemented as a cooperative (non-preemptive) system. Tasks are managed in a sorted array (delta list) based on their delay, ensuring efficient and deterministic execution order.

**Core functions:**
- `SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)`: Add a new task with a specific delay and period.
- `SCH_Update(void)`: Called every timer interrupt (10ms), updates the delay of the first task and marks it ready when delay reaches zero.
- `SCH_Dispatch_Tasks(void)`: Called in the main loop, executes ready tasks and reschedules periodic ones.
- `SCH_Delete_Task(uint32_t taskID)`: Removes a task from the scheduler by its ID.

**Task structure:**
```c
typedef struct {
    void (*pTask)(void);   // Pointer to the task function
    uint32_t Delay;        // Delay (ticks) until next run
    uint32_t Period;       // Interval (ticks) between runs
    uint8_t RunMe;         // Incremented when task is due to execute
    uint32_t TaskID;       // Task identifier (not used in this implementation)
} sTask;
```
**Highlights:**
- Only the first task's delay is decremented each tick ( O(1)searches in the `SCH_Update` function).
- Tasks are always executed in chronological order.
- Periodic tasks are automatically rescheduled.
- The scheduler is simple, predictable, and suitable for small embedded systems.

---

## 6. Code Structure

```
Core/
├── Inc/                # Header files
│   ├── main.h
│   ├── scheduler.h
│   ├── software_timer.h
│   └── 7SEG_display.h
├── Src/                # Source files
│   ├── main.c              # Application entry point
│   ├── scheduler.c         # Scheduler implementation
│   ├── software_timer.c    # Software timer utilities
│   ├── 7SEG_display.c      # 7-segment display driver
│   ├── common.c            # Common helper functions
│   ├── stm32f1xx_hal_msp.c # HAL MSP init
│   ├── stm32f1xx_it.c      # Interrupt handlers
│   ├── syscalls.c          # Syscall stubs
│   ├── sysmem.c            # Memory allocation stubs
│   └── system_stm32f1xx.c  # System clock setup
```
