/* 
 * File:   shiftpwm_pic.h
 * Author: Miguel
 *
 * Created on 10 de Outubro de 2015, 2:56
 */

#ifndef SHIFTPWM_PIC_H
#define	SHIFTPWM_PIC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "bithandler.h"
    
#define SHCP_PIN 0
#define DS_PIN 1
#define STCP_PIN 2
#define SHIFT_REG_COUNT 3
#define REGS_BIT_SIZE SHIFT_REG_COUNT * 8
    
#define pwm_f(hz, channel) pwm(1.f/hz, channel);

char regs[REGS_BIT_SIZE];

void shiftpwm_init();
void pwm_m(float period, int * channels, int channel_count);
void pwm(float period, int channel);

#ifdef	__cplusplus
}
#endif

#endif	/* SHIFTPWM_PIC_H */

