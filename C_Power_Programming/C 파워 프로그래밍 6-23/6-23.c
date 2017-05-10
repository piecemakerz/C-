#include <stdio.h>
#define STR_MAX 100

int strLen(char*);
int strCpy(char*, char*);
int strCat(char*, char*);
int strCmp(char*, char*);

int main(void) {
	char str1[STR_MAX] = "Good morning?";
	char str2[STR_MAX] = "HaHaHa!";
	char buffString[STR_MAX];

	/**strLen test**/
	printf("length of \"%s\" : %d \n", str1, strLen(str1));
	printf("length of \"%s\" : %d \n", str2, strLen(str2));

	/**strCpy test**/
	strCpy(buffString, str1);
	printf("copy string : \"%s\" \n", buffString);

	/**strCat test**/
	strCat(buffString, str2);
	printf("concat string : \"%s\" \n", buffString);

	/** strCmp test**/
	printf("cmp str1, str1 : %d \n", strCmp(str1, str1));
	printf("cmp str2, str2 : %d \n", strCmp(str2, str2));
	printf("cmp str1, str2 : %d \n", strCmp(str1, str2));
	printf("cmp str2, str1 : %d \n", strCmp(str2, str1));
	return 0;
}

int strLen(char * str) {
	int count = 0;
	/*for (int i = 0; ; i++)
		if (str[i] == '\0')
			break;
		else
			count++;
	*/
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

int strCat(char * dest, char * source) {
	int destlen = strLen(dest);
	int sourlen = strLen(source);
	for (int i = 0; i <= sourlen; i++) {
		dest[destlen + i] = source[i];
	}
	return strLen(dest);
}

int strCmp(char * str1, char * str2) {
	/*int str1len = strLen(str1);
	int str2len = strLen(str2);
	int max, min;
	if (str1len >= str2len) {
		max = str1len;
		min = str2len;
	}
	else {
		max = str2len;
		min = str1len;
	}
	for (int i = 0; i < min; i++) {
		if (str1[i] > str2[i])
			return -1;
		else if (str1[i] < str2[i])
			return 1;
	}
	if (max == min)
		return 0;
	else
		if (str1[min] != '\0')
			return -1;
		else if (str2[min] != '\0')
			return 1;
	*/
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