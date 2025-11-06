/*
 * common.h
 *
 *  Created on: Nov 5, 2025
 *      Author: admin
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include "main.h"
#include "software_timer.h"

#define MIN_COUNTER_7SEG 0
#define MAX_COUNTER_7SEG 99

// 7SEG
#define LED_ON 0
#define LED_OFF 1
#define ENABLE_SEG 0
#define DISABLE_SEG	1

//TIMER
#define TIMER_1SEC 2
#define TIME_1SEC 1000

#define TIMER_7SEG	3
#define TIME_7SEG	10

extern int counter;
extern int led_7seg_index;
extern int led_7seg_buffer[2];
extern int status_2digits[2];


#endif /* INC_COMMON_H_ */
