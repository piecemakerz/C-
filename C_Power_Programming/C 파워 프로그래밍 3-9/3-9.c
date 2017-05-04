#include <stdio.h>

int main(void) {
	int num=0;
	int sum = 0;
	while (1) {
		fputs("1 이상의 정수 입력 : ", stdout);
		scanf("%d", &num);
		if (num < 1)
			puts("1 이상의 정수를 입력해야 합니다.");
		else
			break;
	}
	for (int i = 1; i <= num; i++) {
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d\n", num, sum);
	sum = 0;

	int num1, num2;
	fputs("두 개의 정수 입력 : ", stdout);
	scanf("%d %d", &num1, &num2);
	if (num1 > num2) {
		num = num1;
		num1 = num2;
		num2 = num;
	}
	for (int i = num1; i <= num2; i++) {
		sum += i;
	}
	printf("%d와 %d를 포함하여 그 사이에 있는 정수들의 합 : %d\n", num1, num2, sum);
}