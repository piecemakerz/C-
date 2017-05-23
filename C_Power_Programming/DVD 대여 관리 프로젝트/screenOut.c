/* Name : screenOut.c ver 1.1
 * Content : 콘솔 출력을 위한 함수들의 정의
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

/* 프로그램 사용을 위한 메뉴 */
void ShowMenu(void) {
	system("cls");

	printf("------- 메뉴 ------ \n");
	printf("1. 신규가입 \n");
	printf("2. 고객검색 \n");
	printf("------------------- \n");
	printf("3. DVD 등록 \n");
	printf("4. DVD 검색 \n");
	printf("------------------- \n");
	printf("5. 종료 \n");
	printf("------------------- \n");
	printf("선택>> ");
}

/* 고객 개인의 기본 정보 출력 */
void ShowCustomerInfo(cusInfo * pCus) {
	printf("┌----------------- \n");
	printf("┃▶ ID : %s \n", pCus->ID);
	printf("┃▶ 이름 : %s \n", pCus->name);
	printf("┃▶ 전화번호 : %s \n", pCus->phoneNum);
	printf("└------------------ \n");
}

void ShowDVDInfo(dvdInfo * pDVD) {
	printf("┌----------------- \n");
	printf("┃▶ ISBN : %s \n", pDVD->ISBN);
	printf("┃▶ 타이틀 : %s \n", pDVD->title);
	printf("┃▶ 장르 : "); 
	switch (pDVD->genre) {
	case ACTION:
		puts("액션");
		break;
	case COMIC:
		puts("코믹");
		break;
	case SF:
		puts("SF");
		break;
	case ROMANTIC:
		puts("로맨틱");
		break;
	}
	printf("└------------------ \n");
}
/* end of file */