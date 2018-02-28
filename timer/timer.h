/*******************************************************************************
 * @file		timer.h
 * @brief		POSIX real-time timer.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.02.20	Created.
 ******************************************************************************/

#ifndef __HoYa_TIMER_H__
#define __HoYa_TIMER_H__

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <signal.h>
#include <time.h>

/* Definitinos ---------------------------------------------------------------*/
// Method 1
typedef void (*Timer_Handler1)(int);
// Method 2
typedef void (*Timer_Handler2)(int, siginfo_t*, void*);

/* Enumerations --------------------------------------------------------------*/
typedef enum _eTIMER_STATUS {
	eTIMER_STATUS_SUCCESS			= 0,
	eTIMER_STATUS_FAIL_CREATE	= -1,
} eTIMER_STATUS;

/* API Prototypes ------------------------------------------------------------*/
// Method 1
eTIMER_STATUS Timer_Create1(const int msec, Timer_Handler1 handler);
// Method 2
eTIMER_STATUS Timer_Create2(timer_t* tid, const int msec, Timer_Handler2 handler);

#endif
