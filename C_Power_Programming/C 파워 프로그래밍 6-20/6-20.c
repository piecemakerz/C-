#include <stdio.h>
#define DIVISOR_ERROR_OCCURED -256

int DivInt(int, int, int*, int*);

int main(void) {
	int dividend, divisor;
	int quotient, remainder;
	int result = DIVISOR_ERROR_OCCURED;
	while (1) {
		fputs("������ ���� �� ���� �Է� : ", stdout);
		scanf("%d %d", &dividend, &divisor);
		result = DivInt(dividend, divisor, &quotient, &remainder);
		if (result == DIVISOR_ERROR_OCCURED)
			puts("0���� ������ �����߻�! ���� �� �Է�");
		else
			break;
	}
	printf("�� : %d, ������ : %d\n", quotient, remainder);
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