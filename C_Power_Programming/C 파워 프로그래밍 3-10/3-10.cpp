#include <stdio.h>

int main(void) {
	int num, num1, num2;
	int sum = 0;

	fputs("두 개의 정수 입력 : ", stdout);
	scanf("%d %d", &num1, &num2);
	if (num1 > num2) {
		num = num1;
		num1 = num2;
		num2 = num;
	}
	for (int i = num1; i <= num2; i++) {
		if (!(i % 3) || !(i % 5)) {
			printf("%d는 합에서 제외.\n", i);
			continue;
		}
		sum += i;
	}
	printf("%d과 %d를 포함하여 그 사이에 있는 정수들의 합 : %d\n", num1, num2, sum);
}