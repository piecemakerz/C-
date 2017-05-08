#include <stdio.h>
#include <string.h>
#define ARR_LEN 20
#define ARR_NUM 4

// int SortByDict(char *arr1, char*arr2);

int main(void) {
	char arr1[ARR_LEN];
	char arr2[ARR_LEN];
	char arr3[ARR_LEN];
	char arr4[ARR_LEN];
	// char save[ARR_LEN];
	char * save;
	char arrsum[ARR_LEN*ARR_NUM] = { 0, };
	char *arrptr[ARR_NUM] = { arr1, arr2, arr3, arr4 };

	/*fputs("문자열 입력 1 : ", stdout);
	gets(arr1);
	fputs("문자열 입력 2 : ", stdout);
	gets(arr2);
	fputs("문자열 입력 3 : ", stdout);
	gets(arr3);
	fputs("문자열 입력 4 : ", stdout);
	gets(arr4);
	*/

	for (int i = 0; i < ARR_NUM; i++) {
		printf("문자열 입력 %d : ", i + 1);
		gets(arrptr[i]);
	}

	for (int i = 0; i < ARR_NUM - 1; i++) {
		for (int j = 0; j < ARR_NUM - 1 - i; j++) {
			/*if (SortByDict(arrptr[j], arrptr[j + 1])) {
				strcpy(save, arrptr[j]);
				strcpy(arrptr[j], arrptr[j + 1]);
				strcpy(arrptr[j + 1], save);
			}
			*/
			if (strcmp(arrptr[j], arrptr[j + 1]) > 0) {
				save = arrptr[j];
				arrptr[j] = arrptr[j + 1];
				arrptr[j + 1] = save;
			}
		}
	}
	
	for (int i = 0; i < ARR_NUM; i++) {
		strcat(arrsum, arrptr[i]);
		strcat(arrsum, " ");
	}

	printf("정렬된 문자열 : %s\n", arrsum);
	return 0;
}

/*int SortByDict(char *arr1, char*arr2) {
	for (int i = 0; i < ARR_LEN; i++) {
		if (arr1[i] > arr2[i])
			return 1;
		else if (arr1[i] < arr2[i])
			return 0;
	}
}
*/