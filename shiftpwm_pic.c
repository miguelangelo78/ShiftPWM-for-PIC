
#define _XTAL_FREQ 20000000

#include <xc.h>
#include <pic16f877a.h>
#include <string.h>
#include "shiftpwm_pic.h"

void shiftpwm_init() {
	TRISD = PORTD = 0;
	memset(regs, 0, REGS_BIT_SIZE);
}

void write_regs(char * regs) {
	bit_write(0, PORTD, STCP_PIN);
	for(int i = REGS_BIT_SIZE - 1; i >= 0; i--) {
		bit_write(0, PORTD, SHCP_PIN);
		bit_write((regs[i] ? 1 : 0), PORTD, DS_PIN);
		bit_write(1, PORTD, SHCP_PIN);
	}
	bit_write(1, PORTD, STCP_PIN);
}

void pwm_m(float period, int * channels, int channel_count) {
	for(int i = 0;i<channel_count;i++)
		regs[channels[i]] = HIGH;
	write_regs(regs);
	for(float i=0; i < period * 1000.f;i++)
		__delay_ms(1);
	
	for(int i = 0;i<channel_count;i++)
		regs[channels[i]] = LOW;
	write_regs(regs);
	for(float i=0; i < period * 1000.f;i++)
		__delay_ms(1);	
}

void pwm(float period, int channel) {
	int single_channel[1];
	single_channel[0] = channel;
	pwm_m(period, single_channel, 1);
}