/**
 * PWM Stuff
 */

#ifndef _PWM_H_
#define _PWM_H_

#include "arm_cm4.h"
#include "MK20D7.h"

/* These map the PWM pins on the teensy with their relative PCR registers */
#define TEENSY_PWM_PIN_3	3
#define TEENSY_PWM_PIN_4 	4
#define TEENSY_PWM_PIN_5	5
#define TEENSY_PWM_PIN_6	6
#define TEENSY_PWM_PIN_9	9
#define TEENSY_PWM_PIN_10	10
#define TEENSY_PWM_PIN_20	20
#define TEENSY_PWM_PIN_21	21
#define TEENSY_PWM_PIN_22	22
#define TEENSY_PWM_PIN_23	23
#define TEENSY_PWM_PIN_25	25
#define TEENSY_PWM_PIN_32	32
#define TEENSY_PWM_NUM	        12
#define PWM_CnSC (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK)

struct teensy_pwm_pin_setup
{
	uint32_t pin;
	uint32_t port;
	uint32_t mux;
	uint32_t pcr;
	uint32_t channel_en;
};

struct teensy_pwm_clk_setup
{
	uint32_t pulse_width;
	uint32_t duty_cycle;
	uint32_t ftm;
        uint32_t sim_ftm_cs_mask;
        uint32_t clock_source;
        uint32_t pre_scalar;
};

struct teensy_pwm_setup
{
	struct teensy_pwm_clk_setup clk_setup;
	struct teensy_pwm_pin_setup pin_setup;
};

uint32_t set_pwm(struct teensy_pwm_setup *pwm_setup);
uint32_t init_pwm_clk(struct teensy_pwm_setup *pwm_setup);
uint32_t init_pwm_ports(uint32_t teensy_pin, struct teensy_pwm_setup *teensy_setup);


#endif // _PWM_H_
