#include <stdio.h>

int main(void) {
	int num;
	int odd = 0, even = 0, count=1;
	int sum = 0;
	fputs("�ڿ��� �Է� : ", stdout);
	scanf("%d", &num);
	while (num<=0) {
		puts("0���� ū ������ �Է��� �ּ���");
		fputs("�ڿ��� �Է� : ", stdout);
		scanf("%d", &num);
	}
	for (int i = num; i >= 1; i--) {
		if (i % 2)
			odd += i;
		else
			even += i;
	}
	printf("%d ���� Ȧ�� �� : %d\n", num, odd);
	printf("%d ���� ¦�� �� : %d\n", num, even);
	puts("");
	fputs("2 �̻� �Է� : ", stdout);
	scanf("%d", &num);
	while (num <= 1) {
		puts("2�̻��� ������ �Է��� �ּ���");
		fputs("�ڿ��� �Է� : ", stdout);
		scanf("%d", &num);
	}
	while ((sum+count) <= num) {
		sum += count++;
	}
	printf("%d�� ���� �� ó�� %d�� �ѱ� �����Ѵ�.\n", count, num);
	printf("%d�� �ѱ� ������ �� : %d\n", num, sum);
	printf("%d�� ���� ������ �� : %d\n", num, sum+count);
}