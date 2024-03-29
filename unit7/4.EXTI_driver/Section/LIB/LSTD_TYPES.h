/*
 * STD_TYPES.h
 *
 *  Created on: Aug 10, 2023
 *      Author: galal
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef enum
{
	NOK = 0,
	OK
}Error_state;

#define NULL_PTR 	((void *)0)

typedef unsigned char	u8;
typedef signed char		s8;

typedef unsigned short int	u16;
typedef signed short int	s16;

typedef unsigned long int	u32;
typedef signed long int		s32;

typedef unsigned long long int	u64;
typedef signed long long int	s64;

typedef float 	f32;
typedef double	f64;

#endif /* STD_TYPES_H_ */
