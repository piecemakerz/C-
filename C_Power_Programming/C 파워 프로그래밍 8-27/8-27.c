#include <stdio.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3

int main(void) {
	char bookname[BOOK_INFO_NUM][STR_LEN];
	char publisher[BOOK_INFO_NUM][STR_LEN];
	int price[BOOK_INFO_NUM];

	puts("******** ���� ���� �Է� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		fputs("���� ���� : ", stdout);
		gets(bookname[i]);
		fputs("���ǻ� �� : ", stdout);
		gets(publisher[i]);
		fputs("���� ���� : ", stdout);
		scanf("%d", &price[i]);
		getchar();
		printf("%d��° �Է� �Ϸ�......", i+1);
		puts("\n");
	}

	puts("******** ���� ���� ��� ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ���� : %s\n", bookname[i]);
		printf("���ǻ� �� : %s\n", publisher[i]);
		printf("���� ���� : %d\n", price[i]);
		puts("\n");
	}
}