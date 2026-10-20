#ifndef BLACKBOX_CONFIG_H,#define BLACKBOX_CONFIG_H,,#define _XTAL_FREQ 20000000UL,#define BLACKBOX_UART_BAUD 9600UL,,/* Pin map: verify against the assembled schematic. */,#define BLACKBOX_ADC_CHANNEL 0u       /* AN0 */,#define BLACKBOX_EVENT_LED_TRIS TRISBbits.TRISB0,#define BLACKBOX_EVENT_LED_LAT  LATBbits.LATB0,,/* ADC thresholds are raw 10-bit values until sensor scaling is confirmed. */,#define BLACKBOX_OVERSPEED_THRESHOLD 800u,#define BLACKBOX_LOW_SIGNAL_THRESHOLD 80u,#define BLACKBOX_SAMPLE_PERIOD_MS 1000u,,#endif

/* Compatibility aliases for the current firmware entry point. */
#define UART_BAUD BLACKBOX_UART_BAUD
#define OVERSPEED_ADC BLACKBOX_OVERSPEED_THRESHOLD
#define LOW_SIGNAL_ADC BLACKBOX_LOW_SIGNAL_THRESHOLD
