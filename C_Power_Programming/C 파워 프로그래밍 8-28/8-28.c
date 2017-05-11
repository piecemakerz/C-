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

	puts("******** ���� ���� �Է� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets(books[i].bookTitle);
		fputs("���ǻ� �� : ", stdout);
		gets(books[i].bookPub);
		fputs("���� ���� : ", stdout);
		scanf("%d", &(books[i].bookPrice));
		getchar();
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