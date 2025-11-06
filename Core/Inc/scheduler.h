/*
 * scheduler.h
 *
 *  Created on: Oct 29, 2025
 *      Author: admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "software_timer.h"
typedef unsigned char  tByte;

typedef struct{
	// Pointer to the task (must be a 'void (void)' function)
	void(* pTask)(void);
	//Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent run
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//This is a hint to solve the question below.
	uint32_t TaskID;
} sTask;

#define SCH_MAX_TASKS	10
#define NO_TASK_ID		0
#define ERROR_SCH_TOO_MANY_TASKS	1
#define ERROR_SCH_CANNOT_DELETE_TASK	2
#define RETURN_ERROR	0
#define RETURN_NORMAL	1

void SCH_Init(void);

unsigned char SCH_Add_Task(	void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Task(void);

uint8_t SCH_Delete_Task(uint8_t index);

void SCH_Go_To_Sleep(void);

extern int quantity;
#endif /* INC_SCHEDULER_H_ */
