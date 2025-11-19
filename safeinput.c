#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "safeinput.h"


bool parseLong(const char *str, long *val)
{
    char *endptr;
    errno = 0;
    *val = strtol(str, &endptr, 10); //bas 10

    if (endptr == str || *endptr != '\0' ||
        ((*val == LONG_MIN || *val == LONG_MAX) && errno == ERANGE))
        return false;

    return true;
}


bool GetInputChar(char* prompt, char* value)
{
	char buff[255];
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK)
		return false;

	*value = buff[0];
	return true;
}

INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize){

	if (prompt && *prompt) printf("%s", prompt);
	
		
	if (fgets(buff, maxSize, stdin) == NULL || (strlen(buff) == 1 && buff[0] == '\n'))
		return INPUT_RESULT_NO_INPUT; 
    

	// för långt svar = rensa stdin
	if (buff[strlen(buff) - 1] != '\n') {
		int ch;
		while (((ch = getchar()) != '\n') && (ch != EOF));
        
		return INPUT_RESULT_TOO_LONG;
	}

	// tar bort newline
	buff[strcspn(buff, "\n")] = '\0';
	return INPUT_RESULT_OK;
}




