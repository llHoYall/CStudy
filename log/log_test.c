/*******************************************************************************
 * @file		logi_test.c
 * @brief		Test log module.
 * @author	llHoYall <hoya128@gmail.com>
 *******************************************************************************
 * @version	v1.0
 * @note
 *	- 2018.01.28	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// System
#include "log.h"

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	LOG("This is a test string\r\n");
	int i = 1;
	LOG("Formatter test: %d\r\n", i);

	LOG_User("This is a user String\r\n");
	LOG_System("This is a system String\r\n");
	LOG_Debug("This is a debug String\r\n");

	return 0;
}
