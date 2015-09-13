/**
 * PWM Stuff
 */


#include "pwm.h"

uint32_t set_pwm(struct teensy_pwm_setup *pwm_setup)
{
	switch (pwm_setup->pin_setup.pin) {
	case TEENSY_PWM_PIN_3:
		FTM1_C0SC = PWM_CnSC;
		FTM1_C0V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_4:
		FTM1_C1SC = PWM_CnSC;
		FTM1_C1V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_5:
		FTM0_C7SC = PWM_CnSC;
		FTM0_C7V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_6:
		FTM0_C4SC = PWM_CnSC;
		FTM0_C4V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_9:
		FTM0_C2SC = PWM_CnSC;
		FTM0_C2V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_10:
		FTM0_C3SC = PWM_CnSC;
		FTM0_C3V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_20:
		FTM0_C5SC = PWM_CnSC;
		FTM0_C5V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_21:
		FTM0_C6SC = PWM_CnSC;
		FTM0_C6V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_22:
		FTM0_C0SC = PWM_CnSC;
		FTM0_C0V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_23:
		FTM0_C1SC = PWM_CnSC;
		FTM0_C1V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_25:
		FTM2_C1SC = PWM_CnSC;
		FTM2_C1V = pwm_setup->clk_setup.duty_cycle;
		break;
	case TEENSY_PWM_PIN_32:
		FTM2_C0SC = PWM_CnSC;
		FTM2_C0V = pwm_setup->clk_setup.duty_cycle;
		break;
	default:
		return -1;
	}

	return 1;
}

uint32_t init_pwm_clk(struct teensy_pwm_setup *pwm_setup)
{
	switch (pwm_setup->pin_setup.pin) {
	case TEENSY_PWM_PIN_3:
	case TEENSY_PWM_PIN_4:
		pwm_setup->clk_setup.sim_ftm_cs_mask = SIM_SCGC6_FTM1_MASK;
		SIM_SCGC6 |= pwm_setup->clk_setup.sim_ftm_cs_mask;
		FTM1_QDCTRL = 0;
		FTM1_SC = 0;
	    	FTM1_CNTIN = 0;
	    	FTM1_CNT = 0;
		FTM1_MOD = pwm_setup->clk_setup.pulse_width;
	    	FTM1_SC = FTM_SC_CLKS(pwm_setup->clk_setup.clock_source) | FTM_SC_PS(pwm_setup->clk_setup.pre_scalar);
		return 1;
	case TEENSY_PWM_PIN_25:
	case TEENSY_PWM_PIN_32:
		pwm_setup->clk_setup.sim_ftm_cs_mask = SIM_SCGC3_FTM2_MASK;
		SIM_SCGC3 |= pwm_setup->clk_setup.sim_ftm_cs_mask;
		FTM2_QDCTRL = 0;
		FTM2_SC = 0;
	    	FTM2_CNTIN = 0;
	    	FTM2_CNT = 0;
		FTM2_MOD = pwm_setup->clk_setup.pulse_width;
	    	FTM2_SC = FTM_SC_CLKS(pwm_setup->clk_setup.clock_source) | FTM_SC_PS(pwm_setup->clk_setup.pre_scalar);
		return 1;
	}


	pwm_setup->clk_setup.sim_ftm_cs_mask = SIM_SCGC6_FTM0_MASK;
	SIM_SCGC6 |= pwm_setup->clk_setup.sim_ftm_cs_mask;
	FTM0_QDCTRL = 0;
	FTM0_SC = 0;
    	FTM0_CNTIN = 0;
    	FTM0_CNT = 0;
	FTM0_MOD = pwm_setup->clk_setup.pulse_width;
	FTM0_SC = FTM_SC_CLKS(pwm_setup->clk_setup.clock_source) | FTM_SC_PS(pwm_setup->clk_setup.pre_scalar);

	return 1;
}

uint32_t init_pwm_ports(uint32_t teensy_pin, struct teensy_pwm_setup *teensy_setup)
{
	teensy_setup->pin_setup.mux = PORT_PCR_MUX(4);

	switch (teensy_pin) {
	case TEENSY_PWM_PIN_3:
		teensy_setup->pin_setup.pcr = PORTA_PCR12;
		teensy_setup->pin_setup.mux = PORT_PCR_MUX(3);
		PORTA_PCR12 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_4:
		teensy_setup->pin_setup.pcr = PORTA_PCR13;
		teensy_setup->pin_setup.mux = PORT_PCR_MUX(3);
		PORTA_PCR13 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_5:
		teensy_setup->pin_setup.pcr = PORTD_PCR7;
		PORTD_PCR7 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_6:
		teensy_setup->pin_setup.pcr = PORTD_PCR4;
		PORTD_PCR4 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_9:
		teensy_setup->pin_setup.pcr = PORTC_PCR3;
		PORTC_PCR3 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_10:
		teensy_setup->pin_setup.pcr = PORTC_PCR4;
		PORTC_PCR4 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_20:
		teensy_setup->pin_setup.pcr = PORTD_PCR5;
		PORTD_PCR5 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_21:
		teensy_setup->pin_setup.pcr = PORTD_PCR6;
		PORTD_PCR6 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_22:
		teensy_setup->pin_setup.pcr = PORTC_PCR1;
		PORTC_PCR1 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_23:
		teensy_setup->pin_setup.pcr = PORTC_PCR2;
		PORTC_PCR2 |= teensy_setup->pin_setup.mux;
		break;
	case TEENSY_PWM_PIN_25:
		teensy_setup->pin_setup.pcr = PORTB_PCR19;
		teensy_setup->pin_setup.mux = PORT_PCR_MUX(3);
		PORTB_PCR19 |= PORT_PCR_MUX(3);
		break;
	case TEENSY_PWM_PIN_32:
		teensy_setup->pin_setup.pcr = PORTB_PCR18;
		teensy_setup->pin_setup.mux = PORT_PCR_MUX(3);
		PORTB_PCR18 |= PORT_PCR_MUX(3);
		break;
	default:
		return -1;
	}

	teensy_setup->pin_setup.pin = teensy_pin;

	return 1;
}
