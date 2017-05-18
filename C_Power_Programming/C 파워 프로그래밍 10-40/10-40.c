#include <stdio.h>
#include <string.h>
#define STR_LEN 100
#define READ_CNT 100
int main(void) {
	char str1[STR_LEN];
	char str2[STR_LEN];
	int i=0;
	FILE * fp = fopen("string.txt", "wt");

	puts("------문자열 입력 및 저장------");
	fputs("첫 번째 문자열 : ", stdout);
	fgets(str1, STR_LEN, stdin);

	fputs("두 번째 문자열 : ", stdout);
	fgets(str2, STR_LEN, stdin);

	fwrite(str1, strlen(str1), 1, fp);
	fwrite(str2, strlen(str2), 1, fp);
	puts("");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	puts("------저장된 문자열 출력------");
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
	printf("첫 번째 문자열 : %s", str1);
	printf("두 번째 문자열 : %s", str2);
	fclose(fp);
	// 10-40-1

	FILE * fp2;
	int ch;
	fputs("원본 이름 : ", stdout);
	gets(str1);
	fputs("복사본 이름 : ", stdout);
	gets(str2);
	
	fp = fopen(str1, "rb");
	fp2 = fopen(str2, "wb");
	
	while ((ch = fgetc(fp)) != EOF)
		fputc(ch, fp2);

	puts("복사가 완료되었습니다.");
	fclose(fp);
	fclose(fp2);
	//10-40-2

	char dataBuff[READ_CNT];
	int readCnt;
	fputs("원본 이름 : ", stdout);
	gets(str1);
	fputs("복사본 이름 : ", stdout);
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
				puts("오류 발생! 복사를 완료하지 못했습니다.");
				return -1;
			}
		}
		fwrite(dataBuff, 1, readCnt, fp2);
	}
	puts("복사가 완료되었습니다.");
	fclose(fp);
	fclose(fp2);
	return 0;
}

/* 내 코드
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 100

int main(void) {
	FILE * fp = fopen("string.txt", "wt");
	char str1[MAX_STR_LEN];
	char str2[MAX_STR_LEN];
	char ch;
	puts("------ 문자열 입력 및 저장------");
	fputs("첫 번째 문자열 : ", stdout);
	fgets(str1, MAX_STR_LEN, stdin);
	fwrite((void*)str1, sizeof(char), strlen(str1), fp);
	fputs("두 번째 문자열 : ", stdout);
	fgets(str2, MAX_STR_LEN, stdin);
	fwrite((void*)str2, sizeof(char), strlen(str2), fp);
	puts("");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	int count = 0;
	puts("------ 저장된 문자열 출력------");
	fputs("첫 번째 문자열 : ", stdout);
	while (1) {
		fread((void*)&ch, sizeof(char), 1, fp);
		if (ch == '\n') {
			str1[count] = ch;
			str1[count+1] = 0;
			break;
		}
		str1[count++] = ch;
	}
	fputs(str1, stdout);
	count = 0;

	fputs("두 번째 문자열 : ", stdout);
	while (1) {
		fread((void*)&ch, sizeof(char), 1, fp);
		if (ch == '\n') {
			str2[count] = ch;
			str2[count+1] = 0;
			break;
		}
		str1[count++] = ch;
	}
	fputs(str2, stdout);
	puts("\n");
	fclose(fp);

	char filename[MAX_STR_LEN];
	char copyname[MAX_STR_LEN];
	fputs("원본 이름 : ", stdout);
	gets(filename);
	fputs("복사본 이름 : ", stdout);
	gets(copyname);
	
	fp = fopen(filename, "rb");
	FILE * copyfp = fopen(copyname, "wb");
	while (1) {
		ch = fgetc(fp);
		if (feof(fp))
			break;
		fputc(ch, copyfp);
	}
	fclose(fp);
	fclose(copyfp);
	puts("복사가 완료되었습니다.");

	fputs("원본 이름 : ", stdout);
	gets(filename);
	fputs("복사본 이름 : ", stdout);
	gets(copyname);

	fp = fopen(filename, "rb");
	copyfp = fopen(copyname, "wb");
	while (1) {
		count = fread((void*)str1, sizeof(char), MAX_STR_LEN, fp);
		if (count < MAX_STR_LEN) {
			if (feof(fp)==0) {
				puts("파일을 읽는 중 오류가 발생했습니다.");
				break;
			}
			fwrite((void*)str1, sizeof(char), MAX_STR_LEN, copyfp);
			puts("복사가 완료되었습니다.");
			break;
		}
		fwrite((void*)str1, sizeof(char), MAX_STR_LEN, copyfp);
	}
	fclose(fp);
	fclose(copyfp);
	return 0;
*/