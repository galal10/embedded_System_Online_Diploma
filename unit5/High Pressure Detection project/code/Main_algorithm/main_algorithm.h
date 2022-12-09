#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include "driver.h"
#include "Alarm_monitor.h"

#define THERSHOLD   20

extern int getPressureVal();
void waiting();
void High_pressure_detected();

#endif /* MAIN_ALGORITHM_H_ */