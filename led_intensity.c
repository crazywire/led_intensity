/*
 * led intensity using phase correct PWM
 *
 * Created: 11/15/2021 10:42:43 PM
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define TOP 0xFF

int main(void)
{
    DDRB |= 1<<3; //Select PORTB3(OC2A Pin) as output
	
	TCCR2A = 1<<COM2A1  | 1<<WGM20; //Non-inverting phase correct PWM with TOP = 0xFF
	TCCR2B =  1<<CS21; //prescaler  /8

    while (1) 
    {
		//increase intensity
		OCR2A++;
		_delay_ms(10);
	}
}

