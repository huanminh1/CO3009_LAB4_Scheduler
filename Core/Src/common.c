/*
 * common.c
 *
 *  Created on: Nov 5, 2025
 *      Author: admin
 */

#include "common.h"

int led_7seg_index = 0;
int led_7seg_buffer[2] = {0,0};
int status_2digits[2] = {LED_ON, LED_ON};

int counter = 0;
