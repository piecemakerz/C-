#include <stdio.h>
#include <string.h>
char * StringTokenize(char *, char *);

int main(void) {
	char str[] = "111-2222-3333";
	char * delim = "-";
	char * token;
	printf("문자열의 주소 : %d \n", str);

	token = strtok(str, delim);
	while (token != NULL)
	{
		printf("토큰의 주소 : %d \n", token);
		puts(token);
		token = strtok(NULL, delim);
	}
	return 0;
}

char* StringTokenize(char * str, char * delim) {
	static char * nextTokenPos;
	char * curTokenPos;
	char * curStrPos;

	if (str != NULL) {
		curTokenPos = str;
		curStrPos = str;
		nextTokenPos = (char*)-1;
	}
	else {
		curTokenPos = nextTokenPos;
		curStrPos = nextTokenPos;
	}

	if (nextTokenPos == NULL)
		return NULL;

	while (1) {
		if (*curStrPos == 0) {
			nextTokenPos = NULL;
			break;
		}

		if (*curStrPos == delim[0]) {
			*curStrPos = 0;
			nextTokenPos = curStrPos + 1;
			break;
		}

		curStrPos++;
	}
	return curTokenPos;
}