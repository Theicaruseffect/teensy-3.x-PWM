/**
 * PWM Stuff
 */

#include "pwm.h"

#include "arm_cm4.h"

#define PWM_CnSC (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK)

void pwm_init(uint16_t mod)
{
    //enable clock
    SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;
    SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK;
    SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK;

    //quaden = 0
    FTM0_QDCTRL = 0;
    FTM0_SC = 0;

    //every n cycles, the timer will go off
    FTM0_CNTIN = 0;
    FTM0_CNT = 0;
    FTM0_MOD = mod;

    //quaden = 0
    FTM1_QDCTRL = 0;
    FTM1_SC = 0;

    //every n cycles, the timer will go off
    FTM1_CNTIN = 0;
    FTM1_CNT = 0;
    FTM1_MOD = mod;


    //quaden = 0
    FTM2_QDCTRL = 0;
    FTM2_SC = 0;

    //every n cycles, the timer will go off
    FTM2_CNTIN = 0;
    FTM2_CNT = 0;
    FTM2_MOD = mod;


    //no interrupts, clock source is system clock, prescaler is 32
    FTM0_SC = FTM_SC_CLKS(1) | FTM_SC_PS(2);
    FTM1_SC = FTM_SC_CLKS(1) | FTM_SC_PS(2);
    FTM2_SC = FTM_SC_CLKS(1) | FTM_SC_PS(2);
}

void pwm_set(uint8_t chan, uint16_t value)
{
    //PORTA_PCR12 = PORT_PCR_MUX(3);
    //PORTA_PCR13 = PORT_PCR_MUX(3);

    PORTB_PCR18 = PORT_PCR_MUX(3);

    //FTM1_C0SC = PWM_CnSC;
    //FTM1_C0V = value;

    FTM2_C0SC = PWM_CnSC;
    FTM2_C0V = value;
}

/*
void pwm_set(uint8_t chan, uint16_t value)
{
    PORTA_PCR12 = PORT_PCR_MUX(3);
    PORTA_PCR13 = PORT_PCR_MUX(3);

    FTM1_C0SC = PWM_CnSC;
    FTM1_C0V = value;

    FTM1_C1SC = PWM_CnSC;
    FTM1_C1V = value;
}
*/
