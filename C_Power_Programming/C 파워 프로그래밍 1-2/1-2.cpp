#include <stdio.h>

int main(void) {
	char str[100];

	fputs("���ڿ� �Է� : ", stdout);
	//printf("���ڿ� �Է� : ");
	gets_s(str);
	//gets_s(str);
	fputs("�Էµ� ���ڿ� : ", stdout);
	puts(str);
	//printf("�Էµ� ���ڿ� : %s\n", str);
	return 0;
}