#include <stdio.h>
#define ARR_LENGTH 5
void bubblesort(int * array);

int main(void) {
	int num[ARR_LENGTH];
	for (int i = 0; i < ARR_LENGTH; i++) {
		printf("숫자 %d 입력 : ", i+1);
		scanf("%d", &num[i]);
	}
	bubblesort(num);
	fputs("정렬된 출력 : ", stdout);
	for (int i = 0; i < ARR_LENGTH; i++) {
		printf("%d ", num[i]);
	}
	return 0;
}

void bubblesort(int * array) {
	int i = 0, save;
	for (int i = 0; i < ARR_LENGTH - 1; i++) {
		for (int j = 0; j < (ARR_LENGTH - 1) - i; j++) {
			if (array[j] > array[j + 1]) {
				save = array[j];
				array[j] = array[j + 1];
				array[j + 1] = save;
			}
		}
	}
}