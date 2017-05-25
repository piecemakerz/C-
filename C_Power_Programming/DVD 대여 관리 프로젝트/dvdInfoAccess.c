/* Name : dvdInfoAccess ver 1.0
* Content : DVD 정보 저장 및 참조 함수들의 정의
* Implementation : piecemakerz
*
* Last modified 2017.05.23
*/

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

/* 함수 :int AddDVDInfo(char * ISBN, char * title, int genre)
* 기능 : dvdInfo 할당 및 저장
* 반환 : 성공 시 '등록된 정보의 개수', 실패 시 0을 반환
*
*/

int AddDVDInfo(char * ISBN, char * title, int genre) {
	if (numOfDVD >= MAX_DVD)
		return 0;

	dvdInfo * save = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(save->ISBN, ISBN);
	strcpy(save->title, title);
	save->genre = genre;

	save->rentState = RETURNED; // 대여 상태 정보
	save->numOfRentCus = 0; // 등록된 대여 정보의 개수
	
	dvdList[numOfDVD++] = save;
	return numOfDVD;
}

/* 함수 : dvdInfo * GetDVDPtrByISBN(char * ISBN)
* 기능 : 해당 ISBN의 정보를 담고 있는 변수의 포인터 반환
* 반환 : 등록 안된 ISBN의 경우 NULL 포인터 반환
*
*/

dvdInfo * GetDVDPtrByISBN(char * ISBN) {
	for (int i = 0; i < numOfDVD; i++) {
		if (!strcmp(ISBN, dvdList[i]->ISBN))
			return dvdList[i];
	}
	return NULL;
}

/* 함수 : int IsRegistISBN(char * ISBN)
* 기능 : 등록 된 ISBN인지 확인
* 반환 : 등록 되었으면 1, 아니면 0 반환
*
*/

int IsRegistISBN(char * ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;
	else
		return 1;
}

/* 함수 : int SetDVDRented(char * ISBN, char * cusID, int rentDay) 
 * 기능 : 대여 상태로 변경 
 * 반환 : 성공 1, 실패 0
 */

int SetDVDRented(char * ISBN, char * cusID, int rentDay) {
	int rentCusNum;
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return 0;

	rentCusNum = pDVD->numOfRentCus;

	pDVD->rentState = RENTED;
	strcpy(pDVD->rentList[rentCusNum].cusID, cusID);
	pDVD->rentList[rentCusNum].rentDay = rentDay;
	pDVD->numOfRentCus++;
	return 1;
}

/* 함수 : int SetDVDReturned(char * ISBN)
 * 기능 : 대여 가능 상태로 변경
 * 반환 : 성공 1, 실패 0
 */

int SetDVDReturned(char * ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;

	pDVD->rentState = RETURNED;
	return 1;
}

/* 함수 : int GetDVDRentState(char * ISBN)
 * 기능 : 현재 대여 상태 반환
 * 반환 : RETURNED, RENTED, 존재하지 않는 ISBN의 경우 -1 반환
 */

int GetDVDRentState(char * ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return -1;

	return pDVD->rentState;
}

/* end of file */