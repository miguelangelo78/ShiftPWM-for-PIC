/*
 * File:   main.c
 * Author: Miguel
 *
 * Created on 8 October 2015, 19:29
 */

#define _XTAL_FREQ 20000000

#include <xc.h>
#include "shiftpwm_pic.h"

void init() {
	shiftpwm_init();
}

void main(void) {
	init();
	int i = 0;
	while(1) {
		pwm(1, 1, i++);
		if(i>=3) i = 0;
	}
}
