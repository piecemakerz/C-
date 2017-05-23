/* Name : cusManager.c ver 1.1
 * Content : 고객 관련 업무 처리 함수들의 정의
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/* 함수 : void RegisterCustomer(void)
 * 기능 : 신규 회원 가입
 * 반환 : void
 *
 */

void RegistCustomer(void) {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	while (1) {
		fputs("ID 입력 : ", stdout);
		scanf("%s", ID);
		if (IsRegistID(ID)) {
			puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주세요.");
		}
		else
			break;
	}
	fputs("이름 입력 : ", stdout);
	scanf("%s", name);
	fputs("전화번호 입력 : ", stdout);
	scanf("%s", phone);
	getchar();

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
	scanf("%s", searchID);
	getchar();
	save = GetCusPtrByID(searchID);
	if (save == NULL)
		puts("등록된 회원이 없습니다.");
	else
		ShowCustomerInfo(save);

	getchar();
	return;
}

/* end of file */