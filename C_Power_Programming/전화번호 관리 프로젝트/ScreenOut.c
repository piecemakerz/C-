/* Name : screenOut.c ver 1.0 
 * Content : 콘솔 출력을 위한 함수 정의
 * Implementation : piecemakerz
 *
 * Last modified 2015.05.18
 */

#include "common.h"
#include "phoneData.h"

/* 함수 : void ShowMenu(void)
 * 기능 : 선택을 위한 메뉴 출력
 * 반환 : void
 *
 */

void ShowMenu(void) {
	system("cls");

	printf("------ 메	뉴------\n");
	printf(" 1. 전화번호 입력 \n");
	printf(" 2. 전체 정보 출력 \n");
	printf(" 3. 종료 \n");
	printf("--------------------\n");
	printf("선택>>");
}

/* 함수 : void ShowPhoneInfo(phoneData phone)
 * 기능 : 이름과 전화번호 정보 출력
 * 반환 : void
 */

void ShowPhoneInfo(phoneData phone) {
	printf("┌--------------------\n");
	printf("| > 이름 : %s \n", phone.name);
	printf("| 전화번호 : %d \n", phone.phoneNum);
	printf("└--------------------\n\n");
}

/* end of file */