#include <stdio.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3

typedef struct __bookInfo {
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
} bookInfo;

int main(void) {
	bookInfo books[3];

	puts("******** 도서 정보 입력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 입력.\n", i + 1);
		fputs("도서 제목 : ", stdout);
		gets(books[i].bookTitle);
		fputs("출판사 명 : ", stdout);
		gets(books[i].bookPub);
		fputs("도서 가격 : ", stdout);
		scanf("%d", &(books[i].bookPrice));
		getchar();
		printf("%d번째 입력 완료......", i + 1);
		puts("\n");
	}

	puts("******** 도서 정보 출력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목 : %s\n", books[i].bookTitle);
		printf("출판사 명 : %s\n", books[i].bookPub);
		printf("도서 가격 : %d\n", books[i].bookPrice);
		puts("\n");
	}

	return 0;
}