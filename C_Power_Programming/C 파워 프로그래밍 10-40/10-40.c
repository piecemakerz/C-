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