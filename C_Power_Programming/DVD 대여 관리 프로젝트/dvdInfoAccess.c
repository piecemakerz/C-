/* Name : dvdInfoAccess ver 1.0
* Content : DVD ���� ���� �� ���� �Լ����� ����
* Implementation : piecemakerz
*
* Last modified 2017.05.23
*/

#include "common.h"
#include "dvdInfo.h"
#include "rentInfoAccess.h"
#include "dvdInfoAccess.h"

#define MAX_DVD 100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

/* �Լ� :int AddDVDInfo(char * ISBN, char * title, int genre)
* ��� : dvdInfo �Ҵ� �� ����
* ��ȯ : ���� �� '��ϵ� ������ ����', ���� �� 0�� ��ȯ
*
*/

int AddDVDInfo(char * ISBN, char * title, int genre) {
	FILE * fp;
	if (numOfDVD >= MAX_DVD)
		return 0;

	fp = fopen("dvdInfo.txt", "wt");
	if (fp == NULL)
		return 0;

	numOfDVD++;

	fprintf(fp, "numOfDVD : %d\n", numOfDVD);
	fseek(fp, 0, SEEK_END);

	dvdInfo * save = (dvdInfo *)malloc(sizeof(dvdInfo));

	strcpy(save->ISBN, ISBN);
	strcpy(save->title, title);
	save->genre = genre;
	save->rentState = RETURNED; // �뿩 ���� ����
	
	fprintf(fp, "ISBN : %s title : %s genre : %d rentState : %d\n", ISBN, title, genre, RETURNED);
	dvdList[numOfDVD-1] = save;
	fclose(fp);
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

int SetDVDRented(char * ISBN){
	dvdInfo * pDVD = GetDVDPtrByISBN(ISBN);
	if (pDVD == 0)
		return 0;

	pDVD->rentState = RENTED;
	ChangeDVDInfo(pDVD);
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
	ChangeDVDInfo(pDVD);
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

void LoadDVDInfo() {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;

	FILE * fp = fopen("dvdInfo.txt", "rt");
	if (fp == NULL)
		return;

	fscanf(fp, "numOfDVD : %d\n", &numOfDVD);

	for (int i = 0; i < numOfDVD; i++) {
		dvdInfo * save = (dvdInfo *)malloc(sizeof(dvdInfo));
		if (fscanf(fp, "ISBN : %s title : %s genre : %d rentState : %d\n", ISBN, title, &genre, &rentState) == EOF)
			break;
		strcpy(save->ISBN, ISBN);
		strcpy(save->title, title);
		save->genre = genre;
		save->rentState = rentState;
		dvdList[i] = save;
	}

	fclose(fp);
	return numOfDVD;
}

void ChangeDVDInfo(dvdInfo * pDVD) {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;

	int pos;
	FILE * fp = fopen("dvdInfo.txt", "rt");
	if (fp == NULL)
		return;

	fscanf(fp, "numOfDVD : %d\n", &numOfDVD);
	pos = ftell(fp);

	for (int i = 0; i < numOfDVD; i++) {
		if(fscanf(fp, "ISBN : %s title : %s genre : %d rentState : %d\n", ISBN, title, &genre, &rentState) == EOF)
			break;

		if (!strcmp(pDVD->ISBN, ISBN)) {
			fclose(fp);
			fp = fopen("dvdInfo.txt", "wt");
			fseek(fp, pos, SEEK_SET);
			fprintf(fp, "ISBN : %s title : %s genre : %d rentState : %d\n", pDVD->ISBN, pDVD->title, pDVD->genre, pDVD->rentState);
			break;
		}

		pos = ftell(fp);
	}
	
	fclose(fp);
	return;
}
/* end of file */