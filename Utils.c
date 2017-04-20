#include "Utils.h"
#define TRUE 1
#define FALSE 0

int getLength(char* string) {
	int i = 0;
	if (string == NULL) {
		return -1;
	}
	while (TRUE) {
		if (string[i] == '\0') {
			break;
		}
		i++;
	}
	return i;
}

int isIFormat(char* string) {
	int length = getLength(string);
	if ((string[length - 1] == 'I') || (string[length - 1] == 'U' && string[length - 2] == 'I')) {
		return TRUE;
	}
	return FALSE;
}

int absoluteVal(int num) {
	if (num < 0) {
		return num *= -1;
	}
	return num;
}