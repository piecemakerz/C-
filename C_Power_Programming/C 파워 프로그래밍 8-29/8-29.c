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

int numOfData = 0;
bookInfo bookInfoList[BOOK_INFO_NUM];

int InsertList(bookInfo bookPtr);

int main(void) {
	int i, num;
	bookInfo book;

	puts("******** 도서 정보 입력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 입력.\n", i + 1);
		fputs("도서 제목 : ", stdout);
		gets(book.bookTitle);
		fputs("출판사 명 : ", stdout);
		gets(book.bookPub);
		fputs("도서 가격 : ", stdout);
		scanf("%d", &(book.bookPrice));
		getchar();

		num = InsertList(book);
		if (num == -1)
			printf("입력에 실패하였습니다. \n");
		else
			printf("%d번째 입력 완료........\n\n", num);
	}

	puts("******** 도서 정보 출력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목 : %s\n", bookInfoList[i].bookTitle);
		printf("출판사 명 : %s\n", bookInfoList[i].bookPub);
		printf("도서 가격 : %d\n", bookInfoList[i].bookPrice);
		puts("\n");
	}
}

int InsertList(bookInfo bookPtr) {
	int idx;
	int inputIdx = numOfData;

	if (numOfData >= BOOK_INFO_NUM)
		return -1;

	for (idx = 0; idx < numOfData; idx++) {
		if (strcmp(bookInfoList[idx].bookTitle, bookPtr.bookTitle) > 0)
		{
			inputIdx = idx;
			break;
		}
	}

	for (idx = numOfData; idx > inputIdx; idx--)
		bookInfoList[idx] = bookInfoList[idx - 1];

	bookInfoList[inputIdx] = bookPtr;

	return ++numOfData;
}