#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char character[] = "�����ٶ󸶹ٻ������īŸ����";
	int inputnum;
	int ch;
	FILE* f;
	f = fopen("character.txt", "wt");
	/*for (int i = 0; i < strlen(character);) {
		fputc(character[i++], f);
		fputc(character[i++], f);
	}
	puts("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	fclose(f);

	FILE * f = fopen("character.txt", "rt");
	fputs("����� ������ ������ ? ", stdout);
	scanf("%d", &inputnum);
	for (int i = 0; i < inputnum; i++) {
		printf("%c", fgetc(f));
		printf("%c", fgetc(f));
	}
	puts("\n����� �Ϸ�Ǿ����ϴ�.");
	fclose(f);
	*/
	if (f == NULL) {
		puts("���� 'character.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (int i = 0; i < sizeof(character) - 1; i++)
		fputc(character[i], f);

	fclose(f);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");

	f = fopen("character.txt", "rt");
	if (f == NULL) {
		puts("���� 'character.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	printf("����� ������ ������? ");
	scanf("%d", &inputnum);

	for (int i = 0; i < inputnum * 2; i++) {
		ch = fgetc(f);
		if (ch == EOF) {
			puts("������ ���� �����Ͽ��ų� ������ �߻��Ͽ����ϴ�.");
			return -1;
		}

		fputc(ch, stdout);
	}

	fclose(f);
	puts("");
	puts("����� �Ϸ�Ǿ����ϴ�.");
	
	return 0;
}