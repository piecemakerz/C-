#include <stdio.h>

int main(void) {
	int num=0;
	int sum = 0;
	while (1) {
		fputs("1 �̻��� ���� �Է� : ", stdout);
		scanf("%d", &num);
		if (num < 1)
			puts("1 �̻��� ������ �Է��ؾ� �մϴ�.");
		else
			break;
	}
	for (int i = 1; i <= num; i++) {
		sum += i;
	}
	printf("1���� %d������ ���� %d\n", num, sum);
	sum = 0;

	int num1, num2;
	fputs("�� ���� ���� �Է� : ", stdout);
	scanf("%d %d", &num1, &num2);
	if (num1 > num2) {
		num = num1;
		num1 = num2;
		num2 = num;
	}
	for (int i = num1; i <= num2; i++) {
		sum += i;
	}
	printf("%d�� %d�� �����Ͽ� �� ���̿� �ִ� �������� �� : %d\n", num1, num2, sum);
}