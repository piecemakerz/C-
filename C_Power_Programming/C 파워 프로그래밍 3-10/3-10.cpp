#include <stdio.h>

int main(void) {
	int num, num1, num2;
	int sum = 0;

	fputs("�� ���� ���� �Է� : ", stdout);
	scanf("%d %d", &num1, &num2);
	if (num1 > num2) {
		num = num1;
		num1 = num2;
		num2 = num;
	}
	for (int i = num1; i <= num2; i++) {
		if (!(i % 3) || !(i % 5)) {
			printf("%d�� �տ��� ����.\n", i);
			continue;
		}
		sum += i;
	}
	printf("%d�� %d�� �����Ͽ� �� ���̿� �ִ� �������� �� : %d\n", num1, num2, sum);
}