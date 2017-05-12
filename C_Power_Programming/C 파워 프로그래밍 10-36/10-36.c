#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char character[] = "가나다라마바사아자차카타파하";
	int inputnum;
	int ch;
	FILE* f;
	f = fopen("character.txt", "wt");
	/*for (int i = 0; i < strlen(character);) {
		fputc(character[i++], f);
		fputc(character[i++], f);
	}
	puts("입력이 완료되었습니다.\n");
	fclose(f);

	FILE * f = fopen("character.txt", "rt");
	fputs("출력할 문자의 개수는 ? ", stdout);
	scanf("%d", &inputnum);
	for (int i = 0; i < inputnum; i++) {
		printf("%c", fgetc(f));
		printf("%c", fgetc(f));
	}
	puts("\n출력이 완료되었습니다.");
	fclose(f);
	*/
	if (f == NULL) {
		puts("파일 'character.txt'가 열리지 않았습니다.");
		return -1;
	}

	for (int i = 0; i < sizeof(character) - 1; i++)
		fputc(character[i], f);

	fclose(f);
	puts("입력이 완료되었습니다.");

	f = fopen("character.txt", "rt");
	if (f == NULL) {
		puts("파일 'character.txt'가 열리지 않았습니다.");
		return -1;
	}

	printf("출력할 문자의 개수는? ");
	scanf("%d", &inputnum);

	for (int i = 0; i < inputnum * 2; i++) {
		ch = fgetc(f);
		if (ch == EOF) {
			puts("파일의 끝에 도달하였거나 오류가 발생하였습니다.");
			return -1;
		}

		fputc(ch, stdout);
	}

	fclose(f);
	puts("");
	puts("출력이 완료되었습니다.");
	
	return 0;
}