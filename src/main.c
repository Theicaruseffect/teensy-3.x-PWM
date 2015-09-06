#include "common.h"
#include "arm_cm4.h"
#include "pwm.h"

#define LED_ON  GPIOC_PSOR=(1<<5)
#define LED_OFF GPIOC_PCOR=(1<<5)

struct teensy_pwm_pin_setup
{
	int pin;
	int port;
	int channel;
	int ftm;
	int pcr_mux;
	int pcr;
};

struct teensy_pwm_clk_setup
{
	int freq;
	int duty;
};

void init_teensy_setup(int teensy_pin, struct teensy_pwm_pin_setup *setup)
{
	int base_pcr_addr = 0;

	switch (teensy_pin) {
	case 3:
		base_pcr_addr = 12;
		break;
	}
}
int main(void)
{

	const int pulseWidth = 2000;
	const int dutyCycle = 25; //In percentage
	const int dutyCycleVal = pulseWidth / 100 * dutyCycle;
	int i;


	pwm_init(pulseWidth);

	pwm_set(0, dutyCycleVal);

/*
	pwm_set(1, dutyCycleVal);


	pwm_set(2, dutyCycleVal);
	pwm_set(3, dutyCycleVal);

	pwm_set(4, dutyCycleVal);

	pwm_set(5, dutyCycleVal);
	pwm_set(6, dutyCycleVal);
	pwm_set(7, dutyCycleVal);
*/

	//usb_init();
	PORTD_PCR5 |= PORT_PCR_ISF_MASK;
	enable_irq(IRQ(INT_PORTD));
	EnableInterrupts

	while(1)
	{}

	return  0;
}


void PORTD_IRQHandler(void)
{

	LED_ON;

	

	PORTD_PCR5 |= PORT_PCR_ISF_MASK;
}
