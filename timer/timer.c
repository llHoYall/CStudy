/*******************************************************************************
 * @file		timer.c
 * @brief		POSIX real-time timer.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.02.20	Created.
 *******************************************************************************
 *  Method 1
 *		setitimer()					sigaction()
 *	-	ITIMER_REAL			->	SIGALRM
 *	-	ITIMER_VIRTUAL	->	SIGVTALRM
 *	- ITIMER_PROF			->	SIGPROF
 *
 *	Method 2
 *   	Need rt library.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
// System
#include "timer.h"

/* APIs ----------------------------------------------------------------------*/
// Method 1
eTIMER_STATUS Timer_Create1(const int msec, Timer_Handler1 handler) {
	struct itimerval	itv;
	itv.it_value.tv_sec = msec / 1000;
	itv.it_value.tv_usec = (msec % 1000) * 1000;
	itv.it_interval.tv_sec = msec / 1000;
	itv.it_interval.tv_usec = (msec % 1000) * 1000;
	if (setitimer(ITIMER_VIRTUAL, &itv, NULL) < 0) {
		perror("setitimer()");
		return eTIMER_STATUS_FAIL_CREATE;
	}

	struct sigaction	sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler;
	if (sigaction(SIGVTALRM, &sa, NULL) < 0) {
		perror("sigaction()");
		return eTIMER_STATUS_FAIL_CREATE;
	}

	return eTIMER_STATUS_SUCCESS;
}

// Method 2
eTIMER_STATUS Timer_Create2(timer_t* tid, int msec, Timer_Handler2 handler) {
	struct sigevent	se;
	se.sigev_notify = SIGEV_SIGNAL;
	se.sigev_signo = SIGRTMIN;
	se.sigev_value.sival_ptr = tid;
	if (timer_create(CLOCK_REALTIME, &se, tid) < 0) {
		perror("timer_create()");
		return eTIMER_STATUS_FAIL_CREATE;
	}

	struct itimerspec	its;
	its.it_interval.tv_sec = msec / 1000;
	its.it_interval.tv_nsec = (msec % 1000) * 1000000;
	its.it_value.tv_sec = msec / 1000;
	its.it_value.tv_nsec = (msec % 1000)  * 1000000;
	if (timer_settime(*tid, 0, &its, NULL) < 0) {
		perror("timer_settime()");
		return eTIMER_STATUS_FAIL_CREATE;
	}

	struct sigaction	sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGRTMIN, &sa, NULL) < 0) {
		perror("sigaction()");
		return eTIMER_STATUS_FAIL_CREATE;
	}

	return eTIMER_STATUS_SUCCESS;
}
