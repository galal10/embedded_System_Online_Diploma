#include "main_algorithm.h"

static int P_val;
void (*P_main_ptr)();

void waiting()
{
    P_val = getPressureVal();
    (P_val > THERSHOLD) ? (P_main_ptr = High_pressure_detected) : (P_main_ptr = waiting);
}

void High_pressure_detected()
{
    Start_alarm();
    P_main_ptr = waiting;
}