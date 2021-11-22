/*
 * Switch led on (5s) and off (5s)  using overflow interrupt
 *
 * Created: 11/15/2021 10:42:43 PM
 */ 
#define F_CPU 16000000L

#include <avr/io.h>
#include <avr/interrupt.h>

#define  LED_ON() PORTD |= 1<<7
#define  LED_OFF() PORTD &= ~(1<<7)

#define TOP 0xFF //TCNTn register size
#define N 64 //prescaler

volatile unsigned int tick = 0;

int f_tick = F_CPU/(N*(TOP+1)); //scaled frequency of the overflow(frequency of tick)


ISR(TIMER0_OVF_vect)
{	
	//turn off led at 5s
	if(tick == 5*f_tick){
		LED_OFF();
	}
	//turn on led at 10s and reset clock
	if(tick >= 10*f_tick){
		LED_ON();
		tick = 0;
	}

	tick++;
}

int main(void)
{
    DDRD |= 1<<7; //Select PORTD7 as output
	
	TCCR0B = 1<<CS01 | 1<<CS00; //Select prescaler of 64
	
	TIMSK0 |= 1<<TOIE0; //enable overflow interrupt
	
	sei(); //enable interrupts globally
	
	LED_ON(); //Turn led on
    while (1) 
    {
    }
}

