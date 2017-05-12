#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input;
	FILE * fp = fopen("numeric.dat", "wb");
	if (fp == NULL) {
		puts("파일 'numeric.dat'가 열리지 않았습니다.");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		printf("파일에 저장할 숫자 %d : ", i + 1);
		scanf("%d", &input);
		if (fwrite(&input, sizeof(int), 1, fp) < 1) {
			puts("데이터 입력 중 오류 발생");
			return -1;
		}
	}
	puts("입력이 완료되었습니다.");
	fclose(fp);

	fp = fopen("numeric.dat", "rb");
	int num=0;
	if (fp == NULL) {
		puts("파일 'numeric.dat'가 열리지 않았습니다.");
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		if (fread(&num, sizeof(int), 1, fp) < 1) {
			puts("파일의 끝 혹은 에러 발생");
			return -1;
		}
		printf("%d번째 입력 된 숫자 : %d\n", i + 1, num);
	}
	puts("출력이 완료되었습니다.");
	fclose(fp);
	return 0;
}