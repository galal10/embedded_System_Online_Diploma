/*
 * MUSART_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"

/* USART initialization */
void MUSART_Vid_Init(void);

/* USART send Data */
void MUSART_Vid_SendData(u8 Copy_u8_data);

/* USART receive Data */
u8 MUSART_u8_ReceiveData(void);

void MUSART_Vid_SendDataNoBlock(u8 Copy_u8_data);

u8 MUSART_u8_ReceiveDataNoBlock(void);

/* Enable USART Interrupts */
void MUSART_Vid_EnableInterrupt(u8 Copy_u8_InterruptID);

