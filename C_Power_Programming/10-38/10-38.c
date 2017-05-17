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
		puts("파일 'string.txt'가 열리지 않았습니다.");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		printf("%d번째 문자열 입력 : ", i + 1);
		fgets(input, STR_LEN, stdin);
		fputs(input, fp);
	}

	puts("입력이 완료되었습니다.");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	if (fp == NULL) {
		puts("파일 'string.txt'가 열리지 않았습니다.");
		return -1;
	}

	fputs("출력할 문자열 정보 입력(6이상은 전체 출력): ", stdout);
	scanf("%d", &choice);
	
	if (0 < choice && choice < 6)
		PrintString(choice, fp);
	else if (choice >= 6)
		PrintAllString(fp);
	else
		puts("적절치 않은 입력!");

	puts("출력이 완료되었습니다.");
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

/* 내 풀이

#include <stdio.h>
#define MAX_STR_LEN 100
#define STR_NUM 5
int main(void) {
	FILE * fp = fopen("string.txt", "wt");
	char input[MAX_STR_LEN];

	for (int i = 0; i < STR_NUM; i++) {
		printf("%d번째 문자열 입력 : ", i + 1);
		fgets(input, MAX_STR_LEN, stdin);
		fputs(input, fp);
	}
	puts("입력이 완료되었습니다.\n");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	int count;
	fputs("출력할 문자열 정보 입력(6이상은 전체 출력) : ", stdout);
	scanf("%d", &count);
	if (count >= 1 && count <= 5) {
		for (int i = 0; i < (count - 1); i++) {
			fgets(input, MAX_STR_LEN, fp);
		}
		fgets(input, MAX_STR_LEN, fp);
		puts(input);
		puts("출력이 완료되었습니다.");
	}
	else if (count > 5) {
		while(1){
			fgets(input, MAX_STR_LEN, fp);
			if (feof(fp)!=0) {
				break;
			}
			puts(input);
		}
		puts("출력이 완료되었습니다.");
	}
	fclose(fp);
	return 0;
}#include <stdio.h>
#define MAX_STR_LEN 100
#define STR_NUM 5
int main(void) {
	FILE * fp = fopen("string.txt", "wt");
	char input[MAX_STR_LEN];

	for (int i = 0; i < STR_NUM; i++) {
		printf("%d번째 문자열 입력 : ", i + 1);
		fgets(input, MAX_STR_LEN, stdin);
		fputs(input, fp);
	}
	puts("입력이 완료되었습니다.\n");
	fclose(fp);

	fp = fopen("string.txt", "rt");
	int count;
	fputs("출력할 문자열 정보 입력(6이상은 전체 출력) : ", stdout);
	scanf("%d", &count);
	if (count >= 1 && count <= 5) {
		for (int i = 0; i < (count - 1); i++) {
			fgets(input, MAX_STR_LEN, fp);
		}
		fgets(input, MAX_STR_LEN, fp);
		puts(input);
		puts("출력이 완료되었습니다.");
	}
	else if (count > 5) {
		while(1){
			fgets(input, MAX_STR_LEN, fp);
			if (feof(fp)!=0) {
				break;
			}
			puts(input);
		}
		puts("출력이 완료되었습니다.");
	}
	fclose(fp);
	return 0;
}

*/