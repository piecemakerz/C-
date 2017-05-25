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
	FILE * fp;
	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	numOfCustomer++;

	if(numOfCustomer == 1)
		fp = fopen("cusInfo.txt", "wt");
	else
		fp = fopen("cusInfo.txt", "at");
	fprintf(fp, "numOfCustomer : %d\n", numOfCustomer);
	fseek(fp, 0, SEEK_END);

	cusInfo * save = (cusInfo *)malloc(sizeof(cusInfo));

	strcpy(save->ID, ID);
	strcpy(save->name, name);
	strcpy(save->phoneNum, num);

	cusList[numOfCustomer-1] = save;
	fprintf(fp, "ID : %s, name : %s, phoneNum : %s\n", ID, name, num);
	fclose(fp);
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

void LoadCusInfo() {
	FILE * fp = fopen("cusInfo.txt", "rt");
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];

	if (fp == NULL)
		return;

	fscanf(fp, "numOfCustomer : %d\n", &numOfCustomer);
	for(int i=0; i<numOfCustomer; i++){
		cusInfo * save = (cusInfo *)malloc(sizeof(cusInfo));
		fscanf(fp, "ID : %s, name : %s, phoneNum : %s\n", ID, name, num);
		if (!feof(fp))
			break;
		strcpy(save->ID, ID);
		strcpy(save->name, name);
		strcpy(save->phoneNum, num);
		cusList[i] = save;
	}
	fclose(fp);
	return;
}
/* end of file */