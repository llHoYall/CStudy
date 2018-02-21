/*******************************************************************************
 * @file		cli_test.c
 * @brief		Test cli module.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.02.21	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdlib.h>
#include <unistd.h>
// System
#include "cli.h"

/* Private Function Prototypes -----------------------------------------------*/
static void CMD_Help(int argc, char* argv[]);
static void CMD_Exit(int argc, char* argv[]);

/* Private Variables ---------------------------------------------------------*/
tCOMMAND	tCmd[] = {
	{"Help", "    Display menu", CMD_Help},
	{"Exit", "    Exit program", CMD_Exit},
	{NULL, NULL, NULL}
};

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	CLI_Init(tCmd);
	CLI_DisplayMenu();

	while (1) {
		CLI_GetCommand();

		usleep(100);
	}

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static void CMD_Help(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	CLI_DisplayMenu();
}

static void CMD_Exit(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	exit(0);
}
