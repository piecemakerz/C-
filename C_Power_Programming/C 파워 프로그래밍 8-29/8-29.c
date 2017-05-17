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

	puts("******** ���� ���� �Է� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets(book.bookTitle);
		fputs("���ǻ� �� : ", stdout);
		gets(book.bookPub);
		fputs("���� ���� : ", stdout);
		scanf("%d", &(book.bookPrice));
		getchar();

		num = InsertList(book);
		if (num == -1)
			printf("�Է¿� �����Ͽ����ϴ�. \n");
		else
			printf("%d��° �Է� �Ϸ�........\n\n", num);
	}

	puts("******** ���� ���� ��� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ���� : %s\n", bookInfoList[i].bookTitle);
		printf("���ǻ� �� : %s\n", bookInfoList[i].bookPub);
		printf("���� ���� : %d\n", bookInfoList[i].bookPrice);
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

/* ���� Ǭ Ǯ��
#include <stdio.h>
#include <string.h>
#define BOOK_INFO_NUM 3
#define STR_LEN 50
typedef struct __bookInfo {
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
} bookInfo;

bookInfo books[BOOK_INFO_NUM] = { 0, };
void InsertBooks(bookInfo input);

int main(void) {
	bookInfo save;

	puts("******���� ���� �Է�******");
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets(save.bookTitle);
		fputs("���ǻ� �� : ", stdout);
		gets(save.bookPub);
		fputs("���� ���� : ", stdout);
		scanf("%d", &(save.bookPrice));
		getchar();
		InsertBooks(save);
		printf("%d��° �Է� �Ϸ�......\n", i + 1);
		puts("");
	}
	puts("******���� ���� ���******");
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		fputs("���� ���� : ", stdout);
		puts(books[i].bookTitle);
		fputs("���ǻ� �� : ", stdout);
		puts(books[i].bookPub);
		fputs("���� ���� : ", stdout);
		printf("%d\n", books[i].bookPrice);
		puts("");
	}
}

void InsertBooks(bookInfo input) {
	int num = 0;
	while (1) {
		if (books[num].bookTitle[0] == 0) {
			books[num] = input;
			break;
		}
		if (strcmp(books[num].bookTitle, input.bookTitle) > 0) {
			for (int i = BOOK_INFO_NUM - 2; i >= num; i--) {
				books[i + 1] = books[i];
			}
			books[num] = input;
			break;
		}
		num++;
	}
	return;
}
*/