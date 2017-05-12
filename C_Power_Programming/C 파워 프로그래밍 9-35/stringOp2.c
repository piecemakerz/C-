#include "myString.h"
int strCat(char * dest, char * source) {
	int destlen = strLen(dest);
	int sourlen = strLen(source);
	for (int i = 0; i <= sourlen; i++) {
		dest[destlen + i] = source[i];
	}
	return strLen(dest);
}

int strCmp(char * str1, char * str2) {
	while ((*str1) != 0 || (*str2) != 0) {
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		else {
			str1++;
			str2++;
			continue;
		}
	}
	return 0;
}