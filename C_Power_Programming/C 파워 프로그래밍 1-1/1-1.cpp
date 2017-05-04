#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch; int i; double d; char str[100];
	printf("%s\n", "데이터를 다음 포맷으로 입력하시오.[문자, 정수, 실수, 문자열]");
	scanf("%c, %d, %lf, %s", &ch, &i, &d, str);
	printf("%c, %d, %g, %s\n", ch, i, d, str);
	return 0;
}