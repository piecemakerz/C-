#include "common.h"

#include "dvdInfo.h"
#include "cusInfo.h"

#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "rentInfoAccess.h"

#include "screenOut.h"

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
	SetDVDRented(searchISBN);

	AddRentList(searchISBN, rentID, rentDay);

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

	registDVD = IsRegistISBN(returnISBN);

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

	if (rentSte == RETURNED) {
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

	PrintOutRentAllCusInfo(ISBN);

	puts("조회를 완료하였습니다.");
	getchar();
	return;
}

/* 함수 : void RegisterCustomer(void)
* 기능 : 신규 회원 가입
* 반환 : void
*
*/

void RegistCustomer(void) {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	fputs("ID 입력 : ", stdout);
	gets(ID);

	if (IsRegistID(ID)) {
		puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주세요.");
		getchar();
		return;
	}

	fputs("이름 입력 : ", stdout);
	gets(name);
	fputs("전화번호 입력 : ", stdout);
	gets(phone);

	if (!AddCusInfo(ID, name, phone)) {
		puts("계정 등록에 실패했습니다.");
	}
	else
		puts("가입이 완료되었습니다.");

	getchar();
	return;
}

/* 함수 : void SearchCusInfo(void)
* 기능 : ID를 통한 회원 정보 검색
* 반환 : void
*
*/

void SearchCusInfo(void) {
	char searchID[ID_LEN];
	cusInfo * save;

	fputs("찾는 ID 입력 : ", stdout);
	gets(searchID);
	save = GetCusPtrByID(searchID);
	if (save == NULL)
		puts("등록된 회원이 없습니다.");
	else
		ShowCustomerInfo(save);

	getchar();
	return;
}

/* end of file */

void ShowAllCusRentedDVD(void) {
	char ID[ID_LEN];
	unsigned int start, end;
	cusInfo * save;

	fputs("찾는 ID 입력 : ", stdout);
	gets(ID);

	save = GetCusPtrByID(ID);
	if (save == NULL) {
		puts("가입된 회원이 없습니다.");
		getchar();
		return;
	}

	fputs("대여 기간 입력 : ", stdout);
	scanf("%u %u", &start, &end);
	getchar();

	if (start > end) {
		puts("기간 정보가 잘못 입력되었습니다.");
		getchar();
		return;
	}

	PrintOutCusAllRentInfo(ID, start, end);

	puts("조회를 완료하였습니다.");
	getchar();
	return;
}