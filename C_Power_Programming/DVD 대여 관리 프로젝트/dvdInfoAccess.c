/* Name : dvdInfoAccess ver 1.0
* Content : DVD ���� ���� �� ���� �Լ����� ����
* Implementation : piecemakerz
*
* Last modified 2017.05.23
*/

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

/* �Լ� :int AddDVDInfo(char * ISBN, char * title, int genre)
* ��� : dvdInfo �Ҵ� �� ����
* ��ȯ : ���� �� '��ϵ� ������ ����', ���� �� 0�� ��ȯ
*
*/

int AddDVDInfo(char * ISBN, char * title, int genre) {
	if (numOfDVD >= MAX_DVD)
		return 0;

	dvdInfo * save = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(save->ISBN, ISBN);
	strcpy(save->title, title);
	save->genre = genre;

	save->rentState = RETURNED; // �뿩 ���� ����
	save->numOfRentCus = 0; // ��ϵ� �뿩 ������ ����
	
	dvdList[numOfDVD++] = save;
	return numOfDVD;
}

/* �Լ� : dvdInfo * GetDVDPtrByISBN(char * ISBN)
* ��� : �ش� ISBN�� ������ ��� �ִ� ������ ������ ��ȯ
* ��ȯ : ��� �ȵ� ISBN�� ��� NULL ������ ��ȯ
*
*/

dvdInfo * GetDVDPtrByISBN(char * ISBN) {
	for (int i = 0; i < numOfDVD; i++) {
		if (!strcmp(ISBN, dvdList[i]->ISBN))
			return dvdList[i];
	}
	return NULL;
}

/* �Լ� : int IsRegistISBN(char * ISBN)
* ��� : ��� �� ISBN���� Ȯ��
* ��ȯ : ��� �Ǿ����� 1, �ƴϸ� 0 ��ȯ
*
*/

int IsRegistISBN(char * ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;
	else
		return 1;
}

/* �Լ� : int SetDVDRented(char * ISBN, char * cusID, int rentDay) 
 * ��� : �뿩 ���·� ���� 
 * ��ȯ : ���� 1, ���� 0
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

/* �Լ� : int SetDVDReturned(char * ISBN)
 * ��� : �뿩 ���� ���·� ����
 * ��ȯ : ���� 1, ���� 0
 */

int SetDVDReturned(char * ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);

	if (pDVD == 0)
		return 0;

	pDVD->rentState = RETURNED;
	return 1;
}

/* �Լ� : int GetDVDRentState(char * ISBN)
 * ��� : ���� �뿩 ���� ��ȯ
 * ��ȯ : RETURNED, RENTED, �������� �ʴ� ISBN�� ��� -1 ��ȯ
 */

int GetDVDRentState(char * ISBN) {
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return -1;

	return pDVD->rentState;
}

/* end of file */