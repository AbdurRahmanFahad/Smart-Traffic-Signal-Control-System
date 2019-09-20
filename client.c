#include <avr/io.h>
#include "MrLCDATmega32.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#define F_CPU 1000000

static volatile int pulse = 0;
static volatile int i = 0;

int main(void)
{
	int16_t count_a = 0;
	uint8_t timerOverflowCount = 0;
	int distance;
	TCNT0 = 0x00;
	char show_a[16];

	DDRD = 0b11111011; // outputs whether there is jam in pin D6
	DDRA = 0b00000000;
	DDRB = 0b11111111;

	_delay_ms(50);

	Initialise();

	GICR |= 1<<INT0;
	MCUCR |= 1<<ISC00;

	sei();
	
	while(1)
	{
		
		if(PINA & 1) {
			PORTB = 0b00000001;
			PORTD &= ~(1<<PIND6);
		} else {
			PORTB = 0b00000010;

			PORTD |= 1<<PIND0;
			_delay_us(15);

			PORTD &= ~(1<<PIND0);
			PORTD &= ~(1<<PIND6);
			count_a = pulse/58;
			
			distance = pulse/58;
			
			
			if((8-distance) >= 1) {
				if((TCNT0 | 0x00) == 0)
				{
					timerOverflowCount = 0;
					TCCR0 = (1<<CS00) | (1<<CS02);
				}
				else
				{
					if ((TIFR & 0x01) != 0)
					{
						TCNT0 = 0x00;
						TIFR=0x01; //clear timer1 overflow flag
						timerOverflowCount++;
						if (timerOverflowCount>=38)
						{
							PORTD |= 1<<PIND6;
							_delay_ms(300);
						}
					}
				}
			}else {
				PORTD &= ~(1<<PIND6);
				//_delay_ms(300);
				TCNT0 = 0x00;
				TIFR = 0x01;
				timerOverflowCount = 0;
			}

			Send_A_String("Distance Sensor");
			GoToMrLCDLocation(1,2);
			Send_A_String("Distance=");
			itoa(count_a,show_a,10);
			Send_A_String(show_a);
			Send_A_String(" ");
			GoToMrLCDLocation(13,2);
			Send_A_String("cm");
			GoToMrLCDLocation(1,1);
		}
		}
}

ISR(INT0_vect)
{
	if(i == 1)
	{
		TCCR1B = 0;
		pulse = TCNT1;
		TCNT1 = 0;
		i = 0;
	}

	if(i==0)
	{
		TCCR1B |= 1<<CS10;
		i = 1;
	}
}
