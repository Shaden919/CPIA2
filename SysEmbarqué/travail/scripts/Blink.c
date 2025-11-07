#define F_CPU 16000000UL   // Fréquence du quartz sur la carte Arduino Uno
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Met la broche PB5 (broche 13 Arduino) en sortie
    DDRB |= (1 << PB5);

    while (1)
    {
        // Allume la LED
        PORTB |= (1 << PB5);
        _delay_ms(500);

        // Éteint la LED
        PORTB &= ~(1 << PB5);
        _delay_ms(500);
    }

    return 0;
}
