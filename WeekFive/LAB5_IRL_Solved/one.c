// Write C to calibrate sensors, should take raw sensor reading and return calibrated value
#include <stdio.h>

float caliSensor(float raw)
{
    // Example Cali Logic
    float caliFactor = 1.2;
    return raw * caliFactor;
}

int main()
{

    float raw = 2.2;
    raw = caliSensor(raw);
    printf("RAW value after calibration %.2f", raw);
    return 0;
}