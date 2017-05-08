#include <stdio.h>
#include <string.h>

int LetterCount(char * str, char c);

int main(void) {
	char str[100];
	char c;
	fputs("대상 문자열 입력 : ", stdout);
	gets(str);
	fputs("세어 볼 문자 입력 : ", stdout);
	c = getchar();
	printf("%c의 개수 : %d\n", c, LetterCount(str, c));
	return 0;
}

int LetterCount(char * str, char c) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == c)
			count++;
	return count;
}