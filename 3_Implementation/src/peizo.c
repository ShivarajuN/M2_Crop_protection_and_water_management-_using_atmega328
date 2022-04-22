#include "project.h"


void InitADC()
{
 // Select Vref=AVcc
 ADMUX = (1<<REFS0);
 ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);  
}

uint16_t ReadADC(int pin)
{
   if(pin < 0 || pin > 7)
    { //ADC0 - ADC7 is available
        return 1; //pin number is out of range
    }
     
    pin &= 0x7;
    ADMUX = (ADMUX & 0xF8)|pin;
     
    ADCSRA |= (1<<ADSC);

    while(ADCSRA & (1<<ADSC)); //as long as ADSC pin is 1 just wait.
    return (ADC);
}



