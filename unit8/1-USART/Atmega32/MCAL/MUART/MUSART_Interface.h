/*
 * MUSART_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

#include "../../LIB/LSTD_TYPES.h"

void MUSART_Vid_Init(void);

/* USART send Data */
void MUSART_Vid_SendData(u8 Copy_u8_data);

