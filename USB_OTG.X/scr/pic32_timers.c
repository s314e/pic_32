#include <xc.h>
#include <plib.h>
#include "pic32_timers.h"
#include "hw_profile.h"

uint32_t u32_millis_counter;
uint32_t u32_timeout_counter;

#pragma interrupt OC1Interrupt ipl2 vector 6
void OC1Interrupt(void){
	IFS0bits.OC1IF = 0;
}
void pic32_set_pwm(unsigned  long int pwm_period, unsigned long int pwm_duty_cycle){

	unsigned long int calculated_pr;
	unsigned long int calculated_duty_cycle;

	CloseOC3();

 	calculated_pr = (pwm_period*SYS_FREQ)-1; 
	calculated_duty_cycle = calculated_pr * (pwm_duty_cycle/100);
	OpenOC3( OC_ON |
 		OC_TIMER2_SRC |
 		OC_PWM_FAULT_PIN_DISABLE,
 		0,
 		0);
  	OpenTimer2( T2_ON |
  		T1_PS_1_1 |
  		T2_SOURCE_INT,
  		calculated_pr);

 	SetDCOC3PWM(calculated_duty_cycle/2); 

}

/*Timeout using the CORETIMER*/
void timers_trigger_timeout(uint16_t timeout_seconds){ 
	OpenCoreTimer(CORE_TICK_RATE);
	u32_timeout_counter  = timeout_seconds*1000;
	mCTClearIntFlag();
	UpdateCoreTimer(CORE_TICK_RATE);		
}
void timers_coretimer_setup(void){	
	OpenCoreTimer(CORE_TICK_RATE);
	mConfigIntCoreTimer((CT_INT_OFF | CT_INT_PRIOR_2 | CT_INT_SUB_PRIOR_0));
}

char timers_timeout_reached(void){
	if (!mCTGetIntFlag() ){
		return 0;
	}
	mCTClearIntFlag();

	if (u32_millis_counter)u32_millis_counter--;
		
	if (u32_timeout_counter){
		u32_timeout_counter--;
		UpdateCoreTimer(CORE_TICK_RATE);
		return 0;
	}
	CloseCoreTimer();
	
	return 1;
}
