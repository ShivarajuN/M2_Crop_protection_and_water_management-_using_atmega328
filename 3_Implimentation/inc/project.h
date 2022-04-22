#ifndef _LED_
#define _LED_



#include <avr/io.h>
#include "config.h"
#include <util/delay.h>


#define ON (0x01)
#define OFF (0x00)
#define VREF (5)


void peripheral_init(void);

void change_led_state(uint8_t state);

void InitADC();

uint16_t ReadADC(int pin);

void PWMInit(void);

void run_motor(void);

#endif
