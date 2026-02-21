#include <unity.h>
#include "adc_reader.h"

void test_angle_mapping() {
    int angle = map(2048, 0, 4095, 0, 180);
    TEST_ASSERT_INT_WITHIN(2, 90, angle);
}