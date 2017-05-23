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

/* end of file */