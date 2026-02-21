#include <Arduino.h>
#include "led.h"

static int led_pin;
static bool led_state = false;

void led_init(int pin) {
    led_pin = pin;
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);
}

void led_set(bool state) {
    led_state = state;
    digitalWrite(led_pin, state ? HIGH : LOW);
}

bool led_get() {
    return led_state;
}