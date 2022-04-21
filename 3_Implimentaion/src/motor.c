#include "project.h"

void PWMInit(void){
    TCCR1A |= (1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM12)|(1<<CS11)|(1<<CS11);//64 PRESCALER

    DDRB |= (1<<PB1);
}

void run_motor(void)
{
        OCR1A = 1024;
        _delay_ms(200);

}