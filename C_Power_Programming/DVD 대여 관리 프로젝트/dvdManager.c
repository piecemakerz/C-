/* Name : dvdManager.c ver 1.0
 * Content : DVD 관련 업무 처리 함수들의 정의
 * Implementation : piecemaerz
 * Last modified 2017.05.23
 */

#include "common.h"
#include "dvdInfo.h"
#include "DVDInfoAccess.h"
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
