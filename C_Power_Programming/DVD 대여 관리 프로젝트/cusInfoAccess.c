/* Name : cusInfoAccess ver 1.1
* Content : 고객 정보 저장 및 참조 함수들의 정의
* Implementation : piecemakerz
*
* Last modified 2017.05.23
*/

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

/* 함수 : int AddCusInfo (char * ID, char * name, char * num)
* 기능 : cusInfo 할당 및 저장
* 반환 : 성공 시 '등록된 정보의 개수', 실패 시 0을 반환
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

/* 함수 : cusInfo * GetCusPtrByID(char * ID)
* 기능 : 해당 ID의 정보를 담고 있는 변수의 포인터 반환
* 반환 : 등록 안된 ID의 경우 NULL 포인터 반환
*
*/

cusInfo * GetCusPtrByID(char * ID) {
	for (int i = 0; i < numOfCustomer; i++) {
		if (!strcmp(ID, cusList[i]->ID))
			return cusList[i];
	}
	return NULL;
}

/* 함수 : int IsRegistID(char * ID)
* 기능 : 가입 된 ID인지 확인
* 반환 : 가입 되었으면 1, 아니면 0 반환
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