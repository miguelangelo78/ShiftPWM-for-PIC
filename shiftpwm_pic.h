/* 
 * File:   shiftpwm_pic.h
 *
 * Created on 10 October 2015, 2:56
 */

#ifndef SHIFTPWM_PIC_H
#define	SHIFTPWM_PIC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "bithandler.h"
    
#define SHIFT_REG_COUNT 12
#define REGS_BIT_SIZE SHIFT_REG_COUNT * 8
#define RGB_COUNT 32
    
#define pwm_f(pulse_width, hz, channel) pwm((1.f/hz), (1.f/pulse_width), channel);

void shiftpwm_init();
void pwm(char pulse_width, char period, char channel);

#ifdef	__cplusplus
}
#endif

#endif	/* SHIFTPWM_PIC_H */