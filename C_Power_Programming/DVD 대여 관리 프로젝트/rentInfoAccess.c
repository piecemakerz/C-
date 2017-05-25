#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

/* �Լ� : void AddRentList(char * ISBN, char * cusID, int rentDay)
 * ��� : �뿩 ������ ����
 * ��ȯ : void
 */

void AddRentList(char * ISBN, char * cusID, int rentDay) {
	FILE * fp;
	if (numOfRentCus >= RENT_LEN)
		return 0;

	numOfRentCus++;

	if(numOfRentCus==1)
		fp = fopen("rentInfo.txt", "wt");
	else
		fp = fopen("rentInfo.txt", "at");
	fprintf("numOfRentCus : %d\n", numOfRentCus);
	fseek(fp, 0, SEEK_END);

	strcpy(rentList[numOfRentCus-1].ISBN, ISBN);
	strcpy(rentList[numOfRentCus-1].cusID, cusID);
	rentList[numOfRentCus-1].rentDay = rentDay;
	
	fprintf(fp, "ISBN : %s, cusID : %s, rentDay : %d\n", ISBN, cusID, rentDay);
	fclose(fp);
	return;
}

/* �Լ� : void PrintOutRentAllCusInfo(char * ISBN)
 * ��� : Ư�� ISBN�� DVD �뿩 ���� ��ü ���
 * ��ȯ : void
 */

void PrintOutRentAllCusInfo(char * ISBN) {
	for (int i = 0; i < numOfRentCus; i++) {
		if (!(strcmp(rentList[i].ISBN, ISBN))) {
			printf("�뿩�� : %d\n", rentList[i].rentDay);
			ShowCustomerInfo(GetCusPtrByID(rentList[i].cusID));
			puts("");
		}
	}
}

/* �Լ� : void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end)
 * ��� : ���� �Ⱓ �ȿ� �̷��� Ư�� ���� DVD �뿩 ���� ���
 * ��ȯ : void
 */

void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end) {
	for (int i = 0; i < numOfRentCus; i++) {
		if (!strcmp(rentList[i].cusID, ID) &&
			(rentList[i].rentDay >= start && rentList[i].rentDay <= end)) {
			ShowCusRentDVDInfo(&rentList[i]);
			puts("");
		}
	}
	return;
}

void LoadRentList() {
	char ISBN[ISBN_LEN];
	char cusID[ID_LEN];
	int rentDay;

	FILE * fp = fopen("rentInfo.txt", "rt");
	if (fp == NULL)
		return;

	fscanf("numOfRentCus : %d\n", &numOfRentCus);
	for (int i = 0; i < numOfRentCus; i++) {
		fscanf(fp, "ISBN : %s, cusID : %s, rentDay : %d\n", ISBN, cusID, &rentDay);
		if (!feof(fp))
			break;
		strcpy(rentList[i].ISBN, ISBN);
		strcpy(rentList[i].cusID, cusID);
		rentList[i].rentDay = rentDay;
	}
	fclose(fp);
	return;
}