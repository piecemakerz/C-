#include <stdio.h>
#include <string.h>

int LetterCount(char * str, char c);

int main(void) {
	char str[100];
	char c;
	fputs("��� ���ڿ� �Է� : ", stdout);
	gets(str);
	fputs("���� �� ���� �Է� : ", stdout);
	c = getchar();
	printf("%c�� ���� : %d\n", c, LetterCount(str, c));
	return 0;
}

int LetterCount(char * str, char c) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == c)
			count++;
	return count;
}