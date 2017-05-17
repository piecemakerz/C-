#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_NUM 5
#define EXT_SIZE 5

int ExtendMemForString(char ** pStr, int strLen);
char * ReadString(void);
void SortString(char * strArr[STR_NUM]);

int main(void) {
	/*
	char* strptr[5];
	char * save;

	for (int i = 0; i < 5; i++) {
		int count = 0;
		strptr[i] = (char*)calloc(1, sizeof(char));
		printf("%d번째 문자열 입력 : ", i+1);
		while (1) {
			char c;
			if ((c = getchar()) == '\n') {
				strptr[i][count] = '\0';
				break;
			}
			else {
				strptr[i][count++] = c;
				strptr[i] = (char*)realloc(strptr[i], (count+1) * sizeof(char));
			}
		}
	}

	for(int i=0; i<4;i++)
		for (int j = 0; j < (5 - i) - 1; j++) {
			if (strlen(strptr[j]) > strlen(strptr[j + 1])) {
				save = strptr[j];
				strptr[j] = strptr[j + 1];
				strptr[j + 1] = save;
			}
		}
	for (int i = 0; i < 5; i++) {
		puts(strptr[i]);
		free(strptr[i]);
	}
	*/
	char* strArr[STR_NUM];
	int i;

	for (i = 0; i < STR_NUM; i++) {
		printf("문자열 입력 %d : ", i + 1);
		strArr[i] = ReadString();
	}

	SortString(strArr);

	for (i = 0; i < STR_NUM; i++){
		puts(strArr[i]);
		free(strArr[i]);
	}
	return 0;
}

int ExtendMemForString(char ** pStr, int strLen) {
	int i;
	char * newStrPtr;

	newStrPtr = (char*)malloc(sizeof(char)*(strLen + EXT_SIZE));
	if (newStrPtr == NULL)
		return -1;

	for (i = 0; i < strLen; i++)
		newStrPtr[i] = (*pStr)[i];

	free(*pStr);
	*pStr = newStrPtr;
	return strLen + EXT_SIZE;
}

char * ReadString() {
	int maxStrLen = 10;
	char * str = (char*)malloc(sizeof(char)*maxStrLen);
	int idx = 0;

	while (1) {
		if (idx >= maxStrLen)
			maxStrLen = ExtendMemForString(&str, maxStrLen);
		str[idx] = getchar();
		if (str[idx] == '\n')
		{
			str[idx] = 0;
			break;
		}
		idx++;
	}
	return str;
}

void SortString(char * strArr[STR_NUM]) {
	int i, j;
	char * tempStr;

	for (i = 0; i < STR_NUM - 1; i++) {
		for (j = 0; j < (STR_NUM - i) - 1; j++) {
			if (strlen(strArr[j]) > strlen(strArr[j + 1])) {
				tempStr = strArr[j];
				strArr[j] = strArr[j + 1];
				strArr[j + 1] = tempStr;
			}
		}
	}
}

/* 내 풀이
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_STR_LEN 5
#define INC_STR_LEN 5
void StrInput(char ** strptr, int num);

int main(void) {
	char * strptr[5];
	for (int i = 0; i < 5; i++) {
		printf("%d번째 문자열 입력 : ", i + 1);
		StrInput(strptr, i); // 문자열 입력 및 정렬
	}

	for (int i = 0; i < 5; i++) {
		puts(strptr[i]);
		free(strptr[i]);
	}

	return 0;
}

void StrInput(char**strptr, int num) {
	char * str = (char*)malloc(sizeof(char)*INIT_STR_LEN);
	int count = 0;
	int cur_size = INIT_STR_LEN;

	while (1) {
		str[count] = getchar();

		if (str[count] == '\n') {
			str[count] = 0;
			for (int i = 0; i < num; i++) { // 문자열 정렬
				if (strlen(strptr[i]) > strlen(str)) {
					for (int j = num - 1; j >= i; j--) {
						strptr[j + 1] = strptr[j];
					}
					strptr[i] = str;
					return;
				}
			}
			strptr[num] = str;
			break;
		}

		else {
			if ((count + 1) == cur_size) {
				realloc(str, cur_size + (INC_STR_LEN * sizeof(char))); // 배열 크기 확장
				cur_size += INC_STR_LEN;
			}
			count++;
		}
	}
	return;
}
*/