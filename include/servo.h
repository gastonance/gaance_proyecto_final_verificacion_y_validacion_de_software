#ifndef SERVO_H
#define SERVO_H

void servo_init(int pin);
void servo_set_angle(int angle);
int servo_get_angle();

#endif