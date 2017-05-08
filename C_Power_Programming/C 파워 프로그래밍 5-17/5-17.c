#include <stdio.h>
#include <string.h>
#define ARR_NUM 5

int main(void) {
	char inarr[ARR_NUM][20];
	char save[20];
	for (int i = 0; i < ARR_NUM; i++) {
		printf("문자열 입력 %d : ", i+1);
		gets(inarr[i]);
	}
	for(int i=0; i < ARR_NUM-1; i++){
		for (int j = 0; j < ARR_NUM - 1 - i; j++) {
			if (strlen(inarr[j]) > strlen(inarr[j + 1])) {
				strcpy(save, inarr[j]);
				strcpy(inarr[j], inarr[j + 1]);
				strcpy(inarr[j + 1], save);
			}
		}
	}
	for (int i = 0; i < ARR_NUM; i++)
		puts(inarr[i]);
	return 0;
}