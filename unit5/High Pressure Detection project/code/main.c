#include "driver.h"
#include "main_algorithm.h"
#include "Alarm_monitor.h"

int main(void)
{
    GPIO_INITIALIZATION();
    alarmPtr = Stop_alarm;
    P_main_ptr = waiting;
    while (1)
    {
        P_main_ptr();
        Delay(delay);
    }
    
    return 0;
}