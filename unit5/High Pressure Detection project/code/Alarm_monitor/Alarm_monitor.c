#include "Alarm_monitor.h"

void (*alarmPtr)();

void Start_alarm()
{
    Set_Alarm_actuator(ON);
    Delay(delay);
    Set_Alarm_actuator(OFF);
    alarmPtr = Stop_alarm;
}

void Stop_alarm()
{
    Set_Alarm_actuator(OFF);
    alarmPtr = Stop_alarm;
}