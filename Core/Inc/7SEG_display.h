/*
 * 7SEG_display.h
 *
 *  Created on: Nov 5, 2025
 *      Author: admin
 */

#ifndef INC_7SEG_DISPLAY_H_
#define INC_7SEG_DISPLAY_H_

#include "main.h"
#include "common.h"

void set_on_4digits();
void unable_4digit();
void display_4digits();
void update_led_7seg_buffer();
void display_a_digit(int digit, int num);
void display_number(int num);
void enable_digit(int digit);

void display7SEG();
void init7SEG();

#endif /* INC_7SEG_DISPLAY_H_ */
