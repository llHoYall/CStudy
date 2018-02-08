/*******************************************************************************
 * @file		big_endian.c
 * @brief		Convert to/from big endian.
 * @author	llHoYall <hoya128@gmail.com>
 *******************************************************************************
 * @version	v1.0
 * @note
 *	- 2018.01.20	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

/* Definitions ---------------------------------------------------------------*/
#define BUFSIZE		256

/* Private Variables ---------------------------------------------------------*/
const uint8_t val8 = 101;
const uint16_t val16 = 10001;
const uint32_t val32 = 100000001;
const uint64_t val64 = 1000000000001L;
const int MESSAGE_LENGTH = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint32_t) + sizeof(uint64_t);
static char strBuf[BUFSIZE];

/* Private Functions ---------------------------------------------------------*/
char* BytesToDecString(uint8_t* byteArray, int arrayLen) {
	char* cp = strBuf;
	size_t bufSpaceLeft = BUFSIZE;
	for (int i = 0; i < arrayLen && bufSpaceLeft > 0; i++) {
		int strl = snprintf(cp, bufSpaceLeft, "%u ", byteArray[i]);
		bufSpaceLeft -= strl;
		cp += strl;
	}
	return strBuf;
}

int EncodeIntBigEndian(uint8_t dst[], uint64_t val, int offset, int size) {
	for (int i = 0; i < size; i++) {
		dst[offset++] = (uint8_t)(val >> ((size - 1) - i) * CHAR_BIT);
	}
	return offset;
}


uint64_t DecodeIntBigEndian(uint8_t val[], int offset, int size) {
	uint64_t ret = 0;
	for (int i = 0; i < size; i++) {
		ret = (ret << CHAR_BIT) | val[offset + i];
	}
	return ret;
}

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	uint8_t msg[MESSAGE_LENGTH];

	int offset = 0;
	offset = EncodeIntBigEndian(msg, val8, offset, sizeof(uint8_t));
	offset = EncodeIntBigEndian(msg, val16, offset, sizeof(uint16_t));
	offset = EncodeIntBigEndian(msg, val32, offset, sizeof(uint32_t));
	offset = EncodeIntBigEndian(msg, val64, offset, sizeof(uint64_t));
	printf("Encoded message:\n%s\n", BytesToDecString(msg, MESSAGE_LENGTH));

	uint64_t value = DecodeIntBigEndian(msg, sizeof(uint8_t), sizeof(uint16_t));
	printf("Decoded 2-byte integer = %u\n", (unsigned int)value);
	value = DecodeIntBigEndian(msg, sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint32_t), sizeof(uint64_t));
	printf("Decoded 8-byte integer = %llu\n", value);

	offset = 4;
	int iSize = sizeof(int32_t);
	value = DecodeIntBigEndian(msg, offset, iSize);
	printf("Decoded value (offset %d, size %d) = %llu\n", offset, iSize, value);
	int signedVal = DecodeIntBigEndian(msg, offset, iSize);
	printf("... same as signed value %d\n", signedVal);
}
