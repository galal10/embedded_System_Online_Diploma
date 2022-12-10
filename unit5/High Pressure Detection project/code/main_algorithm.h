#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include "driver.h"
#include "Alarm_monitor.h"

#define THERSHOLD   ((unsigned char)20)

extern void (*P_main_ptr)();

extern int getPressureVal();
void waiting();
void High_pressure_detected();

#endif /* MAIN_ALGORITHM_H_ */