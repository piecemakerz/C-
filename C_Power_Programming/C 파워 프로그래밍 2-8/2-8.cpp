#include <stdio.h>

int main(void) {
	int input;
	int num = 0;
	int array[10];
	fputs("10���� ���� �Է� : ", stdout);
	scanf("%d", &input);
	printf("%d�� 2������ ��ȯ�ϸ� : ", input);
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