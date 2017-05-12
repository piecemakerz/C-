#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input;
	FILE * fp = fopen("numeric.dat", "wb");
	if (fp == NULL) {
		puts("���� 'numeric.dat'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		printf("���Ͽ� ������ ���� %d : ", i + 1);
		scanf("%d", &input);
		if (fwrite(&input, sizeof(int), 1, fp) < 1) {
			puts("������ �Է� �� ���� �߻�");
			return -1;
		}
	}
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	fclose(fp);

	fp = fopen("numeric.dat", "rb");
	int num=0;
	if (fp == NULL) {
		puts("���� 'numeric.dat'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		if (fread(&num, sizeof(int), 1, fp) < 1) {
			puts("������ �� Ȥ�� ���� �߻�");
			return -1;
		}
		printf("%d��° �Է� �� ���� : %d\n", i + 1, num);
	}
	puts("����� �Ϸ�Ǿ����ϴ�.");
	fclose(fp);
	return 0;
}