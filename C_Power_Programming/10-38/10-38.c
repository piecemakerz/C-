#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 100

void PrintString(int choice, FILE * fp);
void PrintAllString(FILE * fp);

int main(void) {
	char input[STR_LEN];
	int choice;

	FILE * fp = fopen("string.txt", "wt");
	if (fp == NULL) {
		puts("���� 'string.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		printf("%d��° ���ڿ� �Է� : ", i + 1);
		fgets(input, STR_LEN, stdin);
		fputs(input, fp);
	}

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	if (fp == NULL) {
		puts("���� 'string.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	fputs("����� ���ڿ� ���� �Է�(6�̻��� ��ü ���): ", stdout);
	scanf("%d", &choice);
	
	if (0 < choice && choice < 6)
		PrintString(choice, fp);
	else if (choice >= 6)
		PrintAllString(fp);
	else
		puts("����ġ ���� �Է�!");

	puts("����� �Ϸ�Ǿ����ϴ�.");
	fclose(fp);
	return 0;
}

void PrintString(int choice, FILE * fp) {
	int i;
	char str[STR_LEN];

	for (i = 0; i < choice - 1; i++)
		fgets(str, STR_LEN - 1, fp);

	fgets(str, STR_LEN - 1, fp);
	fputs(str, stdout);
}

void PrintAllString(FILE * fp) {
	char str[STR_LEN];

	while (1) {
		fgets(str, STR_LEN - 1, fp);
		if (feof(fp) != 0)
			break;
		fputs(str, stdout);
	}
}