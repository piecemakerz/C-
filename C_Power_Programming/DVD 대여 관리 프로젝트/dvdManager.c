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

/* 함수 : void RentDVD(void)
 * 기능 : 고객이 DVD를 대여하는 과정 처리
 * 반환 : void
 */

void RentDVD(void) {
	char searchISBN[ISBN_LEN];
	char rentID[NAME_LEN];
	int registDVD;
	int registCus;
	int rentSte;
	unsigned int rentDay;

	//dvdInfo * save;

	fputs("대여 DVD ISBN 입력 : ", stdout);
	gets(searchISBN);

	/*save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL) {
		puts("등록된 DVD가 없습니다.");
		getchar();
		return;
	}
	*/

	registDVD = IsRegistISBN(searchISBN);
	if (registDVD == 0) {
		puts("등록되지 않은 ISBN 입니다.");
		getchar();
		return;
	}
	
	/*if (save->rentState == RENTED) {
		puts("대여 중이라 대여가 불가능합니다.");
		getchar();
		return;
	}
	*/

	rentSte = GetDVDRentState(searchISBN);
	if (rentSte == RENTED) {
		puts("대여 중이라 대여가 불가능합니다.");
		getchar();
		return;
	}

	puts("대여가 가능합니다. 대여 과정을 진행합니다.");
	fputs("대여 고객 ID 입력 : ", stdout);
	gets(rentID);

	registCus = IsRegistID(rentID);

	/*if (GetCusPtrByID(rentID) == NULL) {
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}
	*/

	if (registCus == 0) {
		puts("가입 고객이 아닙니다.");
		getchar();
		return;
	}

	//strcpy(save->rentList[save->numOfRentCus].cusID, rentID);
	fputs("대여 날짜 입력 : ", stdout);
	scanf("%u", &rentDay);
	getchar();

	//save->numOfRentCus++;
	//save->rentState = RENTED;
	SetDVDRented(searchISBN, rentID, rentDay);
	puts("대여가 완료되었습니다.");
	getchar();
	return;
}

/* 함수 : void ReturnDVD(void)
 * 기능 : 고객이 DVD를 반납하는 과정 처리
 * 반환 : void
 */

void ReturnDVD(void) {
	char returnISBN[ISBN_LEN];
	int registDVD;
	int rentSte;
	//dvdInfo * save;

	fputs("반납 DVD ISBN 입력 : ", stdout);
	gets(returnISBN);

	//save = GetDVDPtrByISBN(returnISBN);

	registDVD = IsRegistID(returnISBN);

	/*if (save == NULL) {
		puts("등록되지 않는 ISBN 입니다.");
		getchar();
		return;
	}
	*/

	if (registDVD == 0) {
		puts("등록되지 않는 ISBN 입니다.");
		getchar();
		return;
	}

	rentSte = GetDVDRentState(returnISBN);

	/*else if (save->rentState == RETURNED) {
		puts("대여되지 않은 DVD 입니다.");
		getchar();
		return;
	}
	*/

	if (rentSte = RETURNED) {
		puts("대여되지 않은 DVD 입니다.");
		getchar();
		return;
	}

	//save->rentState = RETURNED;
	SetDVDReturned(returnISBN);
	puts("반납이 완료되었습니다.");
	getchar();
	return;

}

/* 함수 : void RentedDVDList(void)
 * 기능 : 특정 DVD 대여자 전체정보 출력
 * 반환 : void
 */

void RentedDVDList(void) {
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