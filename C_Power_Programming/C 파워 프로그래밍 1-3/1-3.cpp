#include <stdio.h>

int main(void) {
	int n1, n2, sum;
	fputs("두 수를 16진수로 입력 : ", stdout);
	scanf("%x %x", &n1, &n2);
	sum = n1 + n2;
	printf("연산 결과 8진수 : %o\n", sum);
	printf("연산 결과 10진수 : %d\n", sum);
	printf("연산 결과 16진수 : %x\n", sum);
	return 0;
}