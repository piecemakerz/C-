#include <stdio.h>

int main(void) {
	char str[100];

	fputs("문자열 입력 : ", stdout);
	//printf("문자열 입력 : ");
	gets_s(str);
	//gets_s(str);
	fputs("입력된 문자열 : ", stdout);
	puts(str);
	//printf("입력된 문자열 : %s\n", str);
	return 0;
}