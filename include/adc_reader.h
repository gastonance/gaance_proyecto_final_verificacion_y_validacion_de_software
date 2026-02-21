#ifndef ADC_READER_H
#define ADC_READER_H

void adc_init(int pin);
int adc_read_raw();
int adc_read_angle();

#endif