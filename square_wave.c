/*
 * Square wave using phase correct PWM
 *
 * Created: 11/15/2021 10:42:43 PM
 */ 
#include <avr/io.h>
#define TOP 0xFF

int main(void)
{
    DDRB |= 1<<3; //Select PORTB3(OC2A Pin) as output
	
	TCCR2A = 1<<COM2A1  | 1<<WGM20; //Non-inverting phase correct PWM with TOP = 0xFF
	TCCR2B =  1<<CS21; //prescaler  /8

	OCR2A = TOP/2; //50% duty cycle
    while (1) 
    {
	}
}

