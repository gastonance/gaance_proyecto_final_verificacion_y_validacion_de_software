#ifndef LED_H
#define LED_H

void led_init(int pin);
void led_set(bool state);
bool led_get();

#endif