#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 50
#define BOOK_INFO_NUM 3

typedef struct __bookInfo {
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
} bookInfo;

void BookArrangeSave(bookInfo * books, bookInfo temp);

int main(void) {
	bookInfo books[3] = { 0, };

	puts("******** 도서 정보 입력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		bookInfo temp;
		printf("%d번째 도서 정보 입력.\n", i + 1);
		fputs("도서 제목 : ", stdout);
		gets(temp.bookTitle);
		fputs("출판사 명 : ", stdout);
		gets(temp.bookPub);
		fputs("도서 가격 : ", stdout);
		scanf("%d", &(temp.bookPrice));
		getchar();
		BookArrangeSave(books, temp);
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

void BookArrangeSave(bookInfo * books, bookInfo temp) {
	printf("도서 제목 : %s\n", temp.bookTitle);
	printf("출판사 명 : %s\n", temp.bookPub);
	printf("도서 가격 : %d\n", temp.bookPrice);
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("도서 제목 : %s\n", books[i].bookTitle);
		if (books[i].bookTitle == 0) {
			books[i] = temp;
			return;
		}
		if (strcmp(books[i].bookTitle, temp.bookTitle) > 0) {
			books[i + 1] = books[i];
			books[i] = temp;
			return;
		}
	}
}