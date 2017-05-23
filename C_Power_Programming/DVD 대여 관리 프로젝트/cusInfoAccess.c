/* Name : cusInfoAccess ver 1.1
* Content : �� ���� ���� �� ���� �Լ����� ����
* Implementation : piecemakerz
*
* Last modified 2017.05.23
*/

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

/* �Լ� : int AddCusInfo (char * ID, char * name, char * num)
* ��� : cusInfo �Ҵ� �� ����
* ��ȯ : ���� �� '��ϵ� ������ ����', ���� �� 0�� ��ȯ
*
*/

int AddCusInfo(char * ID, char * name, char * num) {
	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	cusInfo * save = (cusInfo *)malloc(sizeof(cusInfo));

	strcpy(save->ID, ID);
	strcpy(save->name, name);
	strcpy(save->phoneNum, num);

	cusList[numOfCustomer++] = save;
	return numOfCustomer;
}

/* �Լ� : cusInfo * GetCusPtrByID(char * ID)
* ��� : �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ
* ��ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ
*
*/

cusInfo * GetCusPtrByID(char * ID) {
	for (int i = 0; i < numOfCustomer; i++) {
		if (!strcmp(ID, cusList[i]->ID))
			return cusList[i];
	}
	return NULL;
}

/* �Լ� : int IsRegistID(char * ID)
* ��� : ���� �� ID���� Ȯ��
* ��ȯ : ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ
*
*/

int IsRegistID(char * ID) {
	/*for (int i = 0; i < numOfCustomer; i++) {
		if (!strcmp(ID, cusList[i]->ID))
			return 1;
	}
	return 0;
	*/
	cusInfo * pCus = GetCusPtrByID(ID);

	if (pCus == 0)
		return 0;
	else
		return 1;
}

/* end of file */