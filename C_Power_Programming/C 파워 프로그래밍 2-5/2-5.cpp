#include <stdio.h>
#define PI 3.14

int main(void) {
	double f1, f2, rad;
	fputs("�� ���� �Ǽ� �Է� : ", stdout);
	scanf("%lf %lf", &f1, &f2);
	printf("���� ��� : %f\n", f1 + f2);
	printf("���� ��� : %f\n", f1 - f2);
	printf("���� ��� : %f\n", f1 * f2);
	printf("������ ��� : %f\n", f1 / f2);
	fputs("������ �Է� : ", stdout);
	scanf("%lf", &rad);
	printf("���� ���� : %f", (rad*rad)*PI);
	return 0;
}