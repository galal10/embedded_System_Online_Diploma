#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "driver.h"

#define ON      1
#define OFF     0
#define delay   300000

extern void (*alarmPtr)();

void Start_alarm();
void Stop_alarm();

#endif /* ALARM_MONITOR_H_ */