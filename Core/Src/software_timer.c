/*
 * software_timer.c
 *
 *  Created on: Sep 15, 2025
 *      Author: admin
 */

#include "software_timer.h"


struct TimerStruct timer[MAX_COUNTER];


void setTimer(int index, int counter){
	timer[index].counter = counter / TIMER_TICK; // ngắt mỗi 10 ms
	timer[index].flag = 0;
}

void timerRun(){
	for(int i =0; i < MAX_COUNTER; i++){
		if(timer[i].counter > 0){
			--timer[i].counter;
			if(timer[i].counter <= 0){
				timer[i].flag = 1;
			}
		}
	}
}

int isFlag(int index){
	if(timer[index].flag){
		return 1;
	}
	return 0;
}
