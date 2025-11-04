#ifndef SAFEINPUT_H
#define SAFEINPUT_H

#include <stdbool.h>

typedef enum
{
	INPUT_RESULT_OK,
	INPUT_RESULT_TOO_LONG,
	INPUT_RESULT_NO_INPUT
} INPUT_RESULT;

INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize);
bool GetInputChar(char* prompt, char* value);
bool parseLong(const char* str, long* val);

#endif