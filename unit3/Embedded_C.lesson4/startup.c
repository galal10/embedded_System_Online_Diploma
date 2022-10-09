#include "platform_types.h"

extern int main(void);
void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias ("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak,alias ("Default_Handler")));

//booking 1024B located by .bss through unintialized array of int 256 element
static uint32_t Stack_top[256];

void (* const g_p_fn_vectors[] ) () __attribute__((section(".vectors"))) =
{
	(void (*)()) ((uint32_t)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler
};

extern uint32_t _E_text;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void Reset_Handler(void)
{
	// copy data from ROM to RAM
	uint32_t DATA_size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
	uint8_t* P_src = (uint8_t*)&_E_text;
	uint8_t* P_dst = (uint8_t*)&_S_DATA;

	for(int i=0; i<DATA_size; i++)
	{
		*((uint8_t*)P_dst++) = *((uint8_t*)P_src++);
	}

	// init .bss with zero
	uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
	P_dst = (uint8_t*)&_S_bss;

	for (int i=0; i<bss_size; i++)
	{
		*((uint8_t*)P_dst++) = (uint8_t)0;
	}

	main();
}