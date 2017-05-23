/* Name : dvdManager.c ver 1.0
 * Content : DVD 관련 업무 처리 함수들의 정의
 * Implementation : piecemaerz
 * Last modified 2017.05.23
 */

#include "common.h"
#include "dvdInfo.h"
#include "DVDInfoAccess.h"
#include "screenOut.h"
#include "cusInfoAccess.h"

/* 함수 : void RegistDVD(void)
* 기능 : DVD 등록
* 반환 : void
*
*/

void RegistDVD(void) {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	fputs("ISBN 입력 : ", stdout);
	gets(ISBN);
	if (IsRegistISBN(ISBN)) {
		puts("해당 ISBN은 이미 등록되었습니다.");
		getchar();
		return;
	}
	
	fputs("제목 입력 : ", stdout);
	gets(title);
	fputs("장르 입력 (액션 1, 코믹 2, SF 3, 로맨틱 4) : ", stdout);
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
		puts("DVD 등록에 실패했습니다.");
	else
		puts("등록이 완료되었습니다.");

	getchar();
	return;
}

/* 함수 : void SearchDVDInfo(void)
* 기능 : ISBN를 통한 회원 정보 검색
* 반환 : void
*
*/

void SearchDVDInfo(void) {
	char searchISBN[ISBN_LEN];
	dvdInfo * save;

	fputs("찾는 ISBN 입력 : ", stdout);
	gets(searchISBN);
	save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL)
		puts("등록된 DVD가 없습니다.");
	else
		ShowDVDInfo(save);

	getchar();
	return;
}

void RentDVD(void) {
	char searchISBN[ISBN_LEN];
	char rentName[NAME_LEN];
	dvdInfo * save;

	fputs("대여 DVD ISBN 입력 : ", stdout);
	gets(searchISBN);
	save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL)
		puts("등록된 DVD가 없습니다.");
	else {
		if (save->rentState == RENTED) {
			puts("대여 중이라 대여가 불가능합니다.");
			getchar();
			return;
		}

		puts("대여가 가능합니다. 대여 과정을 진행합니다.");
		fputs("대여 고객 ID 입력 : ", stdout);
		gets(rentName);

		if (GetCusPtrByID(rentName) == NULL) {
			puts("가입 고객이 아닙니다.");
			getchar();
			return;
		}

		strcpy(save->rentList[save->numOfRentCus].cusID, rentName);
		fputs("대여 날짜 입력 : ", stdout);
		scanf("%d", &(save->rentList[save->numOfRentCus].rentDay));
		getchar();
	}
	save->numOfRentCus++;
	save->rentState = RENTED;
	puts("대여가 완료되었습니다.");
	getchar();
	return;
}

void ReturnDVD(void) {
	char returnISBN[ISBN_LEN];
	dvdInfo * save;
	fputs("반납 DVD ISBN 입력 : ", stdout);
	gets(returnISBN);
	save = GetDVDPtrByISBN(returnISBN);

	if (save == NULL) {
		puts("등록되지 않는 ISBN 입니다.");
		getchar();
		return;
	}
	else if (save->rentState == RETURNED) {
		puts("대여되지 않은 DVD 입니다.");
		getchar();
		return;
	}

	save->rentState = RETURNED;
	puts("반납이 완료되었습니다.");
	getchar();
	return;

}

void ReturnedDVDList(void) {
	char ISBN[ISBN_LEN];
	dvdInfo * save;

	fputs("찾는 ISBN 입력 : ", stdout);
	gets(ISBN);
	save = GetDVDPtrByISBN(ISBN);
	if (save == NULL) {
		puts("등록되지 않는 ISBN 입니다.");
		getchar();
		return;
	}

	for (int i = 0; i < save->numOfRentCus; i++) {
		printf("대여일 : %d\n", save->rentList[i].rentDay);
		ShowCustomerInfo(GetCusPtrByID(save->rentList[i].cusID));
		puts("");
	}
	puts("조회를 완료하였습니다.");
	getchar();
	return;
}