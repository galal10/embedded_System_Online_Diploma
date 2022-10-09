#include "platform_types.h"

#define SYSCTL_RCGC2_R 		*(vuint32_t*)(0x400FE108)
#define GPIO_PORTF_DIR_R 	*(vuint32_t*)(0x40025400)
#define GPIO_PORTF_DEN_R 	*(vuint32_t*)(0x4002551C)
#define GPIO_PORTF_DATA_R 	*(vuint32_t*)(0x400253FC)

void main()
{
	vuint32_t delay_count;
	// Enable the GPIO port
	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure GPIO is up aand running
	for(delay_count=0; delay_count<200; delay_count++);
	
	//Dir is enable in pin 3 for port F
	GPIO_PORTF_DIR_R |= 1<<3;

	//enable GPIO pin 3 for port F
	GPIO_PORTF_DEN_R |= 1<<3;

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3; // on
		for(delay_count=0; delay_count<200000; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3); // off
		for(delay_count=0; delay_count<200000; delay_count++);	
	}

}