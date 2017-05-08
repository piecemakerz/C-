#include <stdio.h>
#define DIVISOR_ERROR_OCCURED -256

int DivInt(int, int, int*, int*);

int main(void) {
	int dividend, divisor;
	int quotient, remainder;
	int result = DIVISOR_ERROR_OCCURED;
	while (1) {
		fputs("나눗셈 위한 두 정수 입력 : ", stdout);
		scanf("%d %d", &dividend, &divisor);
		result = DivInt(dividend, divisor, &quotient, &remainder);
		if (result == DIVISOR_ERROR_OCCURED)
			puts("0으로 나누는 오류발생! 숫자 재 입력");
		else
			break;
	}
	printf("몫 : %d, 나머지 : %d\n", quotient, remainder);
	return 0;
}

int DivInt(int dividend, int divisor, int* quotient, int* remainder) {
	if (divisor == 0)
		return DIVISOR_ERROR_OCCURED;
	else {
		*quotient = dividend / divisor;
		*remainder = dividend % divisor;
		return 1;
	}
}