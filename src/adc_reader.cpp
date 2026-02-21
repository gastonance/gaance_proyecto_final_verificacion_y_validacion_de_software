#include <Arduino.h>
#include "adc_reader.h"

static int adc_pin;

void adc_init(int pin) {
    adc_pin = pin;
    pinMode(adc_pin, INPUT);
}

int adc_read_raw() {
    return analogRead(adc_pin);
}

int adc_read_angle() {
    int raw = adc_read_raw();
    return map(raw, 0, 4095, 0, 180);
}