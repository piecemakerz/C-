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
	if (numOfRentCus >= RENT_LEN)
		return 0;
	
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus++].rentDay = rentDay;
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