/*
 * scheduler.c
 *
 *  Created on: Oct 29, 2025
 *      Author: admin
 */

#include "scheduler.h"
#include "stm32f1xx_hal.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
int Error_code_G;
int quantity = 0;

void SCH_Init(void){
	unsigned char i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}

	// Reset the global error variable
	// - SCH_Delete_Task() will generate an error code,
	// (because the task array is empty)
	Error_code_G = 0;

//	Timer_init();
//	Watchdog_init();
}

unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	uint32_t delay_t = DELAY / TIMER_TICK;
	uint32_t period_t = PERIOD / TIMER_TICK;
	uint8_t index = 0;

	if (quantity >= SCH_MAX_TASKS) {
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return SCH_MAX_TASKS;
	}

	// Find the correct position to insert
	for(index = 0; index < quantity; index++){
		if(SCH_tasks_G[index].pTask == 0 || delay_t < SCH_tasks_G[index].Delay){
			break;
		}

		delay_t -= SCH_tasks_G[index].Delay;
	}

	// Shift the array down to make room for the new task
	for (int i = quantity; i > index; i--) {
		SCH_tasks_G[i] = SCH_tasks_G[i - 1];
	}

	// Update the delay of the next task
	if (index < quantity){
		SCH_tasks_G[index + 1].Delay -= delay_t;
	}

	// Add the new task
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = delay_t;
	SCH_tasks_G[index].Period = period_t;
	SCH_tasks_G[index].RunMe = 0;
	SCH_tasks_G[index].TaskID = index;

	quantity++;
	return index;
}

void SCH_Dispatch_Task(void){
	if (quantity == 0) return;

	// Dispatch (run) the next ready task
	if(SCH_tasks_G[0].RunMe > 0){
		(*SCH_tasks_G[0].pTask)();
		SCH_tasks_G[0].RunMe--;

		sTask temp = SCH_tasks_G[0];

		// Delete the first task
		SCH_Delete_Task(0);

		// If the task is periodic, reinsert it
		if (temp.Period > 0){
			temp.Delay = temp.Period;
			SCH_Add_Task(temp.pTask, temp.Delay * TIMER_TICK, temp.Period * TIMER_TICK);
		}
	}
}

void SCH_Update(void){
	// NOTE: calculations are in TICKS (not milliseconds)
	// Check if there is any task
	if (quantity == 0) return;

	if (SCH_tasks_G[0].Delay == 0){
		SCH_tasks_G[0].RunMe += 1;
	} else {
		SCH_tasks_G[0].Delay--;
	}
}

uint8_t SCH_Delete_Task(uint8_t index){
	if (index >= SCH_MAX_TASKS) return -1;  // validate index

	// Shift all following elements up
	for (uint8_t i = index; i < quantity - 1; i++) {
		SCH_tasks_G[i] = SCH_tasks_G[i + 1];
	}

	// Clear the last task
	SCH_tasks_G[quantity - 1].pTask = 0;
	SCH_tasks_G[quantity - 1].Delay = 0;
	SCH_tasks_G[quantity - 1].Period = 0;
	SCH_tasks_G[quantity - 1].RunMe = 0;

	quantity--;
	return index;
}

void SCH_Go_To_Sleep(void){
	__WFI();
}

