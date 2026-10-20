/* Car Black Box - PIC18F4580 / XC8 starter firmware
 *
 * Hardware assumptions used here:
 *   - 20 MHz crystal on OSC1/OSC2
 *   - AN0 is the first analog vehicle/sensor input
 *   - RC6/TX and RC7/RX are the diagnostic UART
 *   - RB0 drives an event indicator LED
 *
 * Verify every pin and threshold against the real schematic before connection.
 */
#include <xc.h>
#include <stdint.h>

#pragma config OSC = HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = ON, BOREN = ON, WDT = OFF
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, XINST = OFF

#define _XTAL_FREQ 20000000UL
#define UART_BAUD 9600UL
#define OVERSPEED_ADC 800u
#define LOW_SIGNAL_ADC 80u

static void uart_init(void)
{
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;
    TXSTAbits.SYNC = 0;
    TXSTAbits.BRGH = 1;
    BAUDCONbits.BRG16 = 0;
    SPBRG = (uint8_t)((_XTAL_FREQ / (16UL * UART_BAUD)) - 1UL);
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1;
    RCSTAbits.CREN = 1;
}

static void uart_putc(char value)
{
    while (!PIR1bits.TXIF) { }
    TXREG = value;
}

static void uart_puts(const char *text)
{
    while (*text != 0) uart_putc(*text++);
}

static void uart_put_uint16(uint16_t value)
{
    char buffer[6];
    uint8_t i = 0;
    if (value == 0) { uart_putc('0'); return; }
    while (value > 0 && i < sizeof(buffer)) {
        buffer[i++] = (char)('0' + (value % 10u));
        value = (uint16_t)(value / 10u);
    }
    while (i > 0) uart_putc(buffer[--i]);
}

static void adc_init(void)
{
    ADCON1 = 0x0E;       /* AN0 analog, remaining pins digital */
    ADCON2bits.ADFM = 1; /* right justified */
    ADCON2bits.ACQT = 0b010;
    ADCON2bits.ADCS = 0b110;
    ADCON0bits.CHS = 0;
    ADCON0bits.ADON = 1;
}

static uint16_t adc_read_an0(void)
{
    ADCON0bits.CHS = 0;
    __delay_us(10);
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO) { }
    return (uint16_t)(((uint16_t)ADRESH << 8) | ADRESL);
}

static void gpio_init(void)
{
    TRISBbits.TRISB0 = 0;
    LATBbits.LATB0 = 0;
}

void main(void)
{
    uint16_t signal;
    uart_init();
    adc_init();
    gpio_init();
    uart_puts("PIC18F4580 Car Black Box ready\r\n");

    for (;;) {
        signal = adc_read_an0();
        uart_puts("AN0=");
        uart_put_uint16(signal);

        if (signal >= OVERSPEED_ADC) {
            LATBbits.LATB0 = 1;
            uart_puts(" EVENT=OVERSPEED");
        } else if (signal <= LOW_SIGNAL_ADC) {
            LATBbits.LATB0 = 1;
            uart_puts(" EVENT=LOW_SIGNAL");
        } else {
            LATBbits.LATB0 = 0;
            uart_puts(" EVENT=NORMAL");
        }
        uart_puts("\r\n");
        __delay_ms(1000);
    }
}
