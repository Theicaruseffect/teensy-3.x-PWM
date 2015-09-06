/**
 * PWM Stuff
 */

#ifndef _PWM_H_
#define _PWM_H_

#include "arm_cm4.h"
#include "MK20D7.h"

/* These map the PWM pins on the teensy with their relative PCR registers */
#define TEENSY_PWM_PIN_3	PORTA_PCR12
#define TEENSY_PWM_PIN_4 	PORTA_PCR13
#define TEENSY_PWM_PIN_5	PORTD_PCR7
#define TEENSY_PWM_PIN_6	PORTD_PCR4
#define TEENSY_PWM_PIN_9	PORTC_PCR3
#define TEENSY_PWM_PIN_10	PORTC_PCR4
#define TEENSY_PWM_PIN_20	PORTD_PCR5
#define TEENSY_PWM_PIN_21	PORTD_PCR6
#define TEENSY_PWM_PIN_22	PORTC_PCR1
#define TEENSY_PWM_PIN_23	PORTC_PCR2
#define TEENSY_PWM_PIN_25	PORTB_PCR19
#define TEENSY_PWM_PIN_32	PORTB_PCR18


void pwm_init(uint16_t mod);
void pwm_set(uint8_t chan, uint16_t value);

#endif // _PWM_H_
