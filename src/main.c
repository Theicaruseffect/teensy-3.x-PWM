#include "pwm.h"


int main(void)
{
                
	const uint32_t pulseWidth = 5000;
	const uint32_t dutyCyclePercent = 10;
	const uint32_t dutyCycleVal = pulseWidth / 100 * (100 - dutyCyclePercent);
        uint32_t i = 0;
        struct teensy_pwm_setup pwm_setup;
        
        const uint32_t pwm_pins[TEENSY_PWM_NUM] = {
            TEENSY_PWM_PIN_3,TEENSY_PWM_PIN_4,TEENSY_PWM_PIN_5,
            TEENSY_PWM_PIN_6,TEENSY_PWM_PIN_9,TEENSY_PWM_PIN_10,
            TEENSY_PWM_PIN_20,TEENSY_PWM_PIN_21,TEENSY_PWM_PIN_22,
            TEENSY_PWM_PIN_23,TEENSY_PWM_PIN_25,TEENSY_PWM_PIN_32
        };
        
        for (i = 0; i < TEENSY_PWM_NUM; i++) {
        
            pwm_setup.clk_setup.pulse_width = pulseWidth;
            pwm_setup.clk_setup.duty_cycle = dutyCycleVal;
            pwm_setup.clk_setup.clock_source = 1;
            pwm_setup.clk_setup.pre_scalar = 2;
            
            init_pwm_ports(pwm_pins[i], &pwm_setup);        
            init_pwm_clk(&pwm_setup);
            set_pwm(&pwm_setup);
            
        }

	return  0;
}
