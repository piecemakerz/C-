#include <stdio.h>

int main(void) {
	int input;
	int max, min;
	int sum = 0;

	fputs("정수형 데이터 입력 : ", stdout);
	scanf("%d", &input);
	max = input;
	min = input;
	sum += input;

	for (int i = 0; i < 6; i++) {
		fputs("정수형 데이터 입력 : ", stdout);
		scanf("%d", &input);
		if (input > max)
			max = input;
		if (input < min)
			min = input;
		sum += input;
	}

	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);
	printf("전체합 : %d\n", sum);
	printf("평 균 : %f\n", (double)sum / 7);
}