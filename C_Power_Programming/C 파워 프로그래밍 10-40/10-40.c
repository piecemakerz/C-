#include <stdio.h>
#include <string.h>
#define STR_LEN 100
#define READ_CNT 100
int main(void) {
	char str1[STR_LEN];
	char str2[STR_LEN];
	int i=0;
	FILE * fp = fopen("string.txt", "wt");

	puts("------���ڿ� �Է� �� ����------");
	fputs("ù ��° ���ڿ� : ", stdout);
	fgets(str1, STR_LEN, stdin);

	fputs("�� ��° ���ڿ� : ", stdout);
	fgets(str2, STR_LEN, stdin);

	fwrite(str1, strlen(str1), 1, fp);
	fwrite(str2, strlen(str2), 1, fp);
	puts("");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	puts("------����� ���ڿ� ���------");
	while (1) {
		fread(&str1[i], sizeof(char), 1, fp);
		if (str1[i] == '\n') {
			str1[i+1] = 0;
			break;
		}
		i++;
	}
	i = 0;
	while (1) {
		fread(&str2[i], sizeof(char), 1, fp);
		if (str2[i] == '\n') {
			str2[i+1] = 0;
			break;
		}
		i++;
	}
	i = 0;
	printf("ù ��° ���ڿ� : %s", str1);
	printf("�� ��° ���ڿ� : %s", str2);
	fclose(fp);
	// 10-40-1

	FILE * fp2;
	int ch;
	fputs("���� �̸� : ", stdout);
	gets(str1);
	fputs("���纻 �̸� : ", stdout);
	gets(str2);
	
	fp = fopen(str1, "rb");
	fp2 = fopen(str2, "wb");
	
	while ((ch = fgetc(fp)) != EOF)
		fputc(ch, fp2);

	puts("���簡 �Ϸ�Ǿ����ϴ�.");
	fclose(fp);
	fclose(fp2);
	//10-40-2

	char dataBuff[READ_CNT];
	int readCnt;
	fputs("���� �̸� : ", stdout);
	gets(str1);
	fputs("���纻 �̸� : ", stdout);
	gets(str2);

	fp = fopen(str1, "rb");
	fp2 = fopen(str2, "wb");

	while (1) {
		readCnt = fread(dataBuff, 1, READ_CNT, fp);
		if (readCnt < READ_CNT) {
			if (feof(fp) != 0) {
				fwrite(dataBuff, 1, readCnt, fp2);
				break;
			}
			else {
				puts("���� �߻�! ���縦 �Ϸ����� ���߽��ϴ�.");
				return -1;
			}
		}
		fwrite(dataBuff, 1, readCnt, fp2);
	}
	puts("���簡 �Ϸ�Ǿ����ϴ�.");
	fclose(fp);
	fclose(fp2);
	return 0;
}