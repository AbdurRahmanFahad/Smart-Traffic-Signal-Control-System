#include <avr/io.h>
#include "MrLCDATmega32.h"
#include <avr/interrupt.h>
#include <util/delay.h> 
#include <stdlib.h>

#define F_CPU 1000000

int main(void) {
	DDRA = 0b00000000;
	DDRB = 0b11111111;
	DDRD = 0b11111111;

	int state = 1;
	
	while(1)
	{
		if(state == 1)
		{
			PORTB = 0b00000001;
			state = 2;
			_delay_ms(4000);
		}
		else if(state == 2)
		{
			PORTB = 0b00000010;
			state = 3;
			_delay_ms(4000);
		}
		else if(state == 3)
		{
			PORTB = 0b00000100;
			state = 4;
			_delay_ms(4000);
		}
		else if (state == 4)
		{
			PORTB = 0b00001000;
			state = 1;
			_delay_ms(4000);
		}

		while(1) {
			if(PINA & 1) {
				//PORTD = 0b00000001;
				PORTB = 0b00000001;
				_delay_ms(4000);
			} else if (PINA & (1 << 1)) {
				//PORTD = 0b00000010;
				PORTB = 0b00000010;
				_delay_ms(4000);
			} else if (PINA & (1 << 2)) {
				//PORTD = 0b00000100;
				PORTB = 0b00000100;
				_delay_ms(4000);
			} else if (PINA & (1 << 3)) {
				//PORTD = 0b00001000;
				PORTB = 0b00001000;
				_delay_ms(4000);
			} else {
				break;
			}
		}
	}
}
