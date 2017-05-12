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
bookInfo *bookInfoPtr[BOOK_INFO_NUM];

int InsertList(bookInfo bookPtr);

void InitSortList(void);
void PrintSortList(void);

void ArrangeByTitle();
void ArrangeByPub();
void ArrangeByPrice();

int main(void) {
	int i, num;
	int choice;
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

	InitSortList();

	while (1) {
		puts("******** ���� ���� ��� ********");
		puts("���Ĺ�� ����......");
		puts("1. ���� ���� ��, 2. ���ǻ� ��, 3. ���� ��, 4. ����");
		fputs("�״��� ������? ", stdout);
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			ArrangeByTitle();
			PrintSortList();
			break;
		case 2:
			ArrangeByPub();
			PrintSortList();
			break;
		case 3:
			ArrangeByPrice();
			PrintSortList();
			break;
		case 4:
			puts("���α׷��� �����մϴ�.");
			return 0;
		}
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

void InitSortList(void) {
	int i;
	for (i = 0; i < BOOK_INFO_NUM; i++)
		bookInfoPtr[i] = &bookInfoList[i];
}

void PrintSortList(void) {
	int i;
	for (i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� ���. \n", (i + 1));
		printf("���� ���� : %s \n", bookInfoPtr[i]->bookTitle);
		printf("���ǻ� �� : %s \n", bookInfoPtr[i]->bookPub);
		printf("���� ���� : %d \n\n", bookInfoPtr[i]->bookPrice);
	}
}

void ArrangeByTitle(void) {
	InitSortList();
}


/*void ArrangeByTitle() {
bookInfo temp;
for(int i=0; i < BOOK_INFO_NUM - 1; i++)
for (int j = 0; j < (BOOK_INFO_NUM - i) - 1; j++) {
if (strcmp(bookInfoList[i].bookTitle, bookInfoList[i + 1].bookTitle) > 0) {
temp = bookInfoList[i];
bookInfoList[i] = bookInfoList[i + 1];
bookInfoList[i + 1] = temp;
}
}
return;
}

void ArrangeByPub() {
bookInfo temp;
for (int i = 0; i < BOOK_INFO_NUM - 1; i++)
for (int j = 0; j < (BOOK_INFO_NUM - i) - 1; j++) {
if (strcmp(bookInfoList[j].bookPub, bookInfoList[j + 1].bookPub) > 0) {
temp = bookInfoList[j];
bookInfoList[j] = bookInfoList[j + 1];
bookInfoList[j + 1] = temp;
}
}
return;
}

void ArrangeByPrice() {
bookInfo temp;
for (int i = 0; i < BOOK_INFO_NUM - 1; i++)
for (int j = 0; j < (BOOK_INFO_NUM - i) - 1; j++) {
if (bookInfoList[i].bookPrice > bookInfoList[i + 1].bookPrice) {
temp = bookInfoList[i];
bookInfoList[i] = bookInfoList[i + 1];
bookInfoList[i + 1] = temp;
}
}
return;
}
*/

/*void ArrangeByTitle() {
bookInfo* temp;
for (int i = 0; i < BOOK_INFO_NUM - 1; i++)
for (int j = 0; j < (BOOK_INFO_NUM - i) - 1; j++) {
if (strcmp(bookInfoList[i].bookTitle, bookInfoList[i + 1].bookTitle) > 0) {
temp = bookInfoPtr[i];
bookInfoPtr[i] = bookInfoPtr[i + 1];
bookInfoPtr[i + 1] = temp;
}
}
return;
}
*/

void ArrangeByPub() {
	bookInfo* temp;
	for (int i = 0; i < BOOK_INFO_NUM - 1; i++)
		for (int j = 0; j < (BOOK_INFO_NUM - i) - 1; j++) {
			if (strcmp(bookInfoPtr[j]->bookPub, bookInfoPtr[j + 1]->bookPub) > 0) {
				temp = bookInfoPtr[j];
				bookInfoPtr[j] = bookInfoPtr[j + 1];
				bookInfoPtr[j + 1] = temp;
			}
		}
	return;
}

void ArrangeByPrice() {
	bookInfo* temp;
	for (int i = 0; i < BOOK_INFO_NUM - 1; i++)
		for (int j = 0; j < (BOOK_INFO_NUM - i) - 1; j++) {
			if (bookInfoPtr[j]->bookPrice > bookInfoPtr[j + 1]->bookPrice) {
				temp = bookInfoPtr[j];
				bookInfoPtr[j] = bookInfoPtr[j + 1];
				bookInfoPtr[j + 1] = temp;
			}
		}
	return;
}