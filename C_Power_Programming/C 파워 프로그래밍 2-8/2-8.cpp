#include <stdio.h>

int main(void) {
	int input;
	int num = 0;
	int array[10];
	fputs("10진수 정수 입력 : ", stdout);
	scanf("%d", &input);
	printf("%d를 2진수로 변환하면 : ", input);
	while (input >= 1) {
		array[num++] = input % 2;
		input /= 2;
	}
	for (int i = num-1; i >= 0; i--) {
		printf("%d", array[i]);
	}
	puts("");
	return 0;
}