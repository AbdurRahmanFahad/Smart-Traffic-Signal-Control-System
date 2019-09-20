#include <avr/io.h>
#include "MrLCDATmega32.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#define F_CPU 1000000

int main(void) {
    unsigned char c;
    DDRA = Ob00000000;
    DDRB = Ob11111111;

    while(true) {
        c = PINA;
        PORTB = c;
    }
}