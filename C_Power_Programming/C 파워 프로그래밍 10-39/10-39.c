#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100

int main(void) {
	int num;
	char str[MAX_STR_LEN];
	char ch;
	FILE * fp;
	fp = fopen("weather_info.txt", "wt");
	if (fp == NULL) {
		puts("���� 'weather_info.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	while (1) {
		puts("**���� ���� �Է�******");
		fputs("��¥ : ", stdout);

		if(scanf("%d", &num)==EOF){
			puts("�Է��� �Ϸ�Ǿ����ϴ�.");
			puts("\n");
			fclose(fp);
			break;
		}

		fwrite(&num, sizeof(int), 1, fp);
		getchar();

		fputs("���� : ", stdout);
		fgets(str, MAX_STR_LEN, stdin);
		fputs(str, fp);

		fputs("����(A)/����(P) : ", stdout);
		ch = fgetc(stdin);
		fputc(ch, fp);
		getchar();

		fputs("���� : ", stdout);
		fgets(str, MAX_STR_LEN, stdin);
		fputs(str, fp);

		puts("\n");
	}
	// ������� ���� 39-1

	fp = fopen("weather_info.txt", "rt");
	if (fp == NULL) {
		puts("���� 'weather_info.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	while(1){
		fread(&num, sizeof(int), 1, fp);
		if (feof(fp) != 0)
			break;
		printf("��¥ : %d\n", num);

		fgets(str, MAX_STR_LEN, fp);
		printf("���� : %s", str);

		ch = fgetc(fp);
		printf("����(A)/����(P) : %c\n", ch);

		fgets(str, MAX_STR_LEN, fp);
		printf("���� : %s\n", str);
	}

	puts("����� �Ϸ�Ǿ����ϴ�.\n");
	fclose(fp);

	// ������� ���� 39-2

	int day, day_f;
	char strRegion[MAX_STR_LEN], strRegion_f[MAX_STR_LEN];
	char ap, ap_f;
	char strWeather_f[MAX_STR_LEN];

	fp = fopen("weather_info.txt", "rt");
	if (fp == NULL) {
		puts("���� 'weather_info.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	fputs("�˻��� ��¥ �� ���� ���� �Է� : ", stdout);
	scanf("%d %s %c", &day, strRegion, &ap);

	sprintf(strRegion, "%s\n", strRegion);

	while (1)
	{
		fread(&day_f, sizeof(int), 1, fp);
		if (feof(fp) != 0) 
			break;

		fgets(strRegion_f, MAX_STR_LEN, fp);
		ap_f = fgetc(fp);
		fgets(strWeather_f, MAX_STR_LEN, fp);

		if (day == day_f && !strcmp(strRegion, strRegion_f) && ap == ap_f) {
			printf("��¥ : %d\n", day_f);
			printf("���� : %s", strRegion_f);
			printf("����(A)/����(P) : %c\n", ap_f);
			printf("���� : %s\n", strWeather_f);
			fclose(fp);
			puts("�˻��� �Ϸ�Ǿ����ϴ�.");
			return 0;
		}
	}

	fclose(fp);
	puts("�ش� ��¥ �� ������ �����Ͱ� �������� �ʽ��ϴ�.");
	return 0;
	// ������� ���� 39-3
}