#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch; int i; double d; char str[100];
	printf("%s\n", "�����͸� ���� �������� �Է��Ͻÿ�.[����, ����, �Ǽ�, ���ڿ�]");
	scanf("%c, %d, %lf, %s", &ch, &i, &d, str);
	printf("%c, %d, %g, %s\n", ch, i, d, str);
	return 0;
}