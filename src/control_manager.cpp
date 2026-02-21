#include <Arduino.h>
#include "control_manager.h"
#include "servo.h"
#include "led.h"
#include "adc_reader.h"

static unsigned long last_mqtt_time = 0;
static const unsigned long MQTT_TIMEOUT = 5000;
static int mqtt_servo_angle = 0;

void control_init() {
    adc_init(34);
}

void control_set_servo_from_mqtt(int angle) {
    mqtt_servo_angle = angle;
    last_mqtt_time = millis();
    servo_set_angle(angle);
}

void control_set_led_from_mqtt(bool state) {
    led_set(state);
}

void control_update() {

    if (millis() - last_mqtt_time > MQTT_TIMEOUT) {
        int pot_angle = adc_read_angle();
        servo_set_angle(pot_angle);
    }
}