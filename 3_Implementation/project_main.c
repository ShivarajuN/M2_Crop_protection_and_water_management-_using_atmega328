#include "project.h"


int main(void)
{
    float volt1=0,volt2=0;

    peripheral_init();
    InitADC();
    PWMInit();
    uint16_t temp1=0,temp2=0;

    while(1)
    {
        
           
        temp1=ReadADC(0);
        volt1=ADC_VOLT(temp1);
        temp2=ReadADC(1);
        volt1=ADC_VOLT(temp2);

        if(volt1>3)
        {
            change_led_state(ON);
		    _delay_ms(2000);
		
            change_led_state(OFF);
		    _delay_ms(1000);
        }
    
        if(volt2>3)
        {

            run_motor();
        }
        
        
    }
    return 0;
}