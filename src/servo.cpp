#include <Arduino.h>
#include <ESP32Servo.h>
#include "servo.h"

static Servo myServo;
static int current_angle = 0;

void servo_init(int pin) {
    myServo.attach(pin);
}

void servo_set_angle(int angle) {
    angle = constrain(angle, 0, 180);
    current_angle = angle;
    myServo.write(angle);
}

int servo_get_angle() {
    return current_angle;
}