#include <stdio.h>

int main(void) {
	double f1, f2;
	fputs("�� ���� �Ǽ� �Է� : ", stdout);
	scanf("%lf %lf", &f1, &f2);
	printf("���� ��� : %f\n", f1 + f2);
	printf("���� ��� : %f\n", f1 - f2);
	printf("���� ��� : %f\n", f1 * f2);
	printf("������ ��� : %f\n", f1 / f2);
	fputs("������ �Է� : ", stdout);
	scanf("%lf", &f1);
	printf("���� ���� : %f", (f1*f1)*3.14);
}