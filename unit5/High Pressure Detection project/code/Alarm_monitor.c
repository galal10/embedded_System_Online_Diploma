#include "Alarm_monitor.h"

void (*alarmPtr)();

void Start_alarm()
{
    Set_Alarm_actuator(OFF);
    Delay(delay);
    Set_Alarm_actuator(ON);
    alarmPtr = Stop_alarm;
}

void Stop_alarm()
{
    Set_Alarm_actuator(ON);
}