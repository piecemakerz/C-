#include <stdio.h>

int main(void) {
	int input;
	int max, min;
	int sum = 0;

	fputs("������ ������ �Է� : ", stdout);
	scanf("%d", &input);
	max = input;
	min = input;
	sum += input;

	for (int i = 0; i < 6; i++) {
		fputs("������ ������ �Է� : ", stdout);
		scanf("%d", &input);
		if (input > max)
			max = input;
		if (input < min)
			min = input;
		sum += input;
	}

	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);
	printf("��ü�� : %d\n", sum);
	printf("�� �� : %f\n", (double)sum / 7);
}