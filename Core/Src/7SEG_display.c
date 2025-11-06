/*
 * 7SEG_display.c
 *
 *  Created on: Nov 5, 2025
 *      Author: admin
 */


#include "7SEG_display.h"

void set_on_2digits()
{
	status_2digits[0] = LED_ON;
	status_2digits[1] = LED_ON;
}

void unable_2digit()
{
	HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE_SEG);
	HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE_SEG);
}

void display_2digits()
{
	if (status_2digits[led_7seg_index] == LED_ON)
	{
		display_a_digit(led_7seg_index, led_7seg_buffer[led_7seg_index]);
	}
	++led_7seg_index;
	if (led_7seg_index > 1)
	{
		led_7seg_index = 0;
	}
}

void update_led_7seg_buffer()
{
	led_7seg_buffer[0] = counter / 10;
	led_7seg_buffer[1] = counter % 10;
}

void display_a_digit(int digit, int num)
{
	unable_2digit();
	display_number(num);
	enable_digit(digit);
}

void display_number(int num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_ON);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	default:
		HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, LED_OFF);
		HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, LED_OFF);
		break;
	}
}

void enable_digit(int digit)
{
	switch (digit)
	{
	case 0:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, ENABLE_SEG);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, DISABLE_SEG);
		break;
	case 1:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, DISABLE_SEG);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, ENABLE_SEG);
		break;
	default:
		break;
	}
}

void init7SEG(){
	set_on_2digits();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_1SEC, TIME_1SEC);
	counter = 0;
	update_led_7seg_buffer();
}

void display7SEG(){
	if (isFlag(TIMER_7SEG)){
		display_2digits();
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_1SEC)){
		counter++;
		if(counter > MAX_COUNTER_7SEG){
			counter = MIN_COUNTER_7SEG;
		}
		update_led_7seg_buffer();
		setTimer(TIMER_1SEC, TIME_1SEC);
	}
}
