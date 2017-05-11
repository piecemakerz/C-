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

	puts("******** ���� ���� �Է� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		bookInfo temp;
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets(temp.bookTitle);
		fputs("���ǻ� �� : ", stdout);
		gets(temp.bookPub);
		fputs("���� ���� : ", stdout);
		scanf("%d", &(temp.bookPrice));
		getchar();
		BookArrangeSave(books, temp);
		printf("%d��° �Է� �Ϸ�......", i + 1);
		puts("\n");
	}

	puts("******** ���� ���� ��� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ���� : %s\n", books[i].bookTitle);
		printf("���ǻ� �� : %s\n", books[i].bookPub);
		printf("���� ���� : %d\n", books[i].bookPrice);
		puts("\n");
	}

	return 0;
}

void BookArrangeSave(bookInfo * books, bookInfo temp) {
	printf("���� ���� : %s\n", temp.bookTitle);
	printf("���ǻ� �� : %s\n", temp.bookPub);
	printf("���� ���� : %d\n", temp.bookPrice);
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("���� ���� : %s\n", books[i].bookTitle);
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