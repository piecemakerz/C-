#include <stdio.h>

int main(void) {
	int n1, n2, sum;
	fputs("�� ���� 16������ �Է� : ", stdout);
	scanf("%x %x", &n1, &n2);
	sum = n1 + n2;
	printf("���� ��� 8���� : %o\n", sum);
	printf("���� ��� 10���� : %d\n", sum);
	printf("���� ��� 16���� : %x\n", sum);
	return 0;
}