/*******************************************************************************
 * @file		timer_test.c
 * @brief		Test timer module.
 * @author	llHoYall <hoya128@gmail.com>
 *******************************************************************************
 * @version	v1.0
 * @note
 *	- 2018.02.20	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdio.h>
// System
#include "timer.h"

/* Global Variables ----------------------------------------------------------*/
timer_t	tid1;
timer_t	tid2;

/* Private Function Prototypes -----------------------------------------------*/
void Timer_Handler1(int signum) {
	static int count = 0;
	printf("Timer1: %d\n", ++count);
}

void Timer_Handler2(int sig, siginfo_t* si, void* uc) {
	static int count1 = 0;
	static int count2 = 0;
	timer_t* ptid = si->si_value.sival_ptr;
	if (*ptid == tid1) {
		printf("Timer2 - TID1: %d\n", ++count1);
	}
	else if (*ptid == tid2) {
		printf("Timer2 - TID2: %d\n", ++count2);
	}
}

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	// Method1
	Timer_Create1(500, &Timer_Handler1);

	// Method2
	Timer_Create2(&tid1, 1000, &Timer_Handler2);
	Timer_Create2(&tid2, 2500, &Timer_Handler2);

	while (1) {
	}

	return 0;
}
