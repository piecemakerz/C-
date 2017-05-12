#include "myString.h"
int strLen(char * str) {
	int count = 0;
	while ((*str) != 0) {
		count++;
		str++;
	}
	return count;
}

int strCpy(char * dest, char * source) {
	int sourlen = strLen(source);
	for (int i = 0; i <= sourlen; i++) {
		dest[i] = source[i];
	}
	return sourlen;
}