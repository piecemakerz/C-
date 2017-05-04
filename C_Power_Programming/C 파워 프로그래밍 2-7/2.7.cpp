#include <stdio.h>

int main(void) {
	int num1, num2, num3;
	fputs("두 개의 숫자를 입력하세요 : ", stdout);
	scanf("%d %d", &num1, &num2);
	printf("큰 수는 %d\n", (num1 > num2) ? num1 : num2);

	fputs("세 개의 숫자를 입력하세요 : ", stdout);
	scanf("%d %d %d", &num1, &num2, &num3);
	printf("큰 수는 %d\n", (num1 > num2) ? 
		(num1 > num3 ? num1 : num3)
		: (num2 > num3 ? num2 : num3));
	return 0;
}