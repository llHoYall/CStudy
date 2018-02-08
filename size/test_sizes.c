/*******************************************************************************
 * @file		test_sizes.c
 * @brief		Test sizes on current platform.
 * @author	llHoYall <hoya128@gmail.com>
 *******************************************************************************
 * @version	v1.0
 * @note
 *	- 2018.01.19	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	printf("CHAR_BIT: %d\n", CHAR_BIT);
	puts("");
	printf("char: %lu\n", sizeof(char));
	printf("short: %lu\n", sizeof(short));
	printf("int: %lu\n", sizeof(int));
	printf("long: %lu\n", sizeof(long));
	printf("long long: %lu\n", sizeof(long long));
	puts("");
	printf("int8_t: %lu\n", sizeof(int8_t));
	printf("int16_t: %lu\n", sizeof(int16_t));
	printf("int32_t: %lu\n", sizeof(int32_t));
	printf("int64_t: %lu\n", sizeof(int64_t));
	puts("");
	printf("uint8_t: %lu\n", sizeof(uint8_t));
	printf("uint16_t: %lu\n", sizeof(uint16_t));
	printf("uint32_t: %lu\n", sizeof(uint32_t));
	printf("uint64_t: %lu\n", sizeof(uint64_t));
}
