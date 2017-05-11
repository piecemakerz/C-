#include <stdio.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3

int main(void) {
	char bookname[BOOK_INFO_NUM][STR_LEN];
	char publisher[BOOK_INFO_NUM][STR_LEN];
	int price[BOOK_INFO_NUM];

	puts("******** 도서 정보 입력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 입력.\n", i + 1);
		fputs("도서 제목 : ", stdout);
		gets(bookname[i]);
		fputs("출판사 명 : ", stdout);
		gets(publisher[i]);
		fputs("도서 가격 : ", stdout);
		scanf("%d", &price[i]);
		getchar();
		printf("%d번째 입력 완료......", i+1);
		puts("\n");
	}

	puts("******** 도서 정보 출력 ********");
	for (int i = 0; i < BOOK_INFO_NUM; i++) {
		printf("%d번째 도서 정보 출력.\n", i + 1);
		printf("도서 제목 : %s\n", bookname[i]);
		printf("출판사 명 : %s\n", publisher[i]);
		printf("도서 가격 : %d\n", price[i]);
		puts("\n");
	}
}