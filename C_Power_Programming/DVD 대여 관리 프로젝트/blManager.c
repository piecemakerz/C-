#include "common.h"

#include "dvdInfo.h"
#include "cusInfo.h"

#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "rentInfoAccess.h"

#include "screenOut.h"

/* �Լ� : void RegistDVD(void)
* ��� : DVD ���
* ��ȯ : void
*
*/

void RegistDVD(void) {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	fputs("ISBN �Է� : ", stdout);
	gets(ISBN);
	if (IsRegistISBN(ISBN)) {
		puts("�ش� ISBN�� �̹� ��ϵǾ����ϴ�.");
		getchar();
		return;
	}

	fputs("���� �Է� : ", stdout);
	gets(title);
	fputs("�帣 �Է� (�׼� 1, �ڹ� 2, SF 3, �θ�ƽ 4) : ", stdout);
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
		puts("DVD ��Ͽ� �����߽��ϴ�.");
	else
		puts("����� �Ϸ�Ǿ����ϴ�.");

	getchar();
	return;
}

/* �Լ� : void SearchDVDInfo(void)
* ��� : ISBN�� ���� ȸ�� ���� �˻�
* ��ȯ : void
*
*/

void SearchDVDInfo(void) {
	char searchISBN[ISBN_LEN];
	dvdInfo * save;

	fputs("ã�� ISBN �Է� : ", stdout);
	gets(searchISBN);
	save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL)
		puts("��ϵ� DVD�� �����ϴ�.");
	else
		ShowDVDInfo(save);

	getchar();
	return;
}

/* �Լ� : void RentDVD(void)
* ��� : ���� DVD�� �뿩�ϴ� ���� ó��
* ��ȯ : void
*/

void RentDVD(void) {
	char searchISBN[ISBN_LEN];
	char rentID[NAME_LEN];
	int registDVD;
	int registCus;
	int rentSte;
	unsigned int rentDay;

	//dvdInfo * save;

	fputs("�뿩 DVD ISBN �Է� : ", stdout);
	gets(searchISBN);

	/*save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL) {
	puts("��ϵ� DVD�� �����ϴ�.");
	getchar();
	return;
	}
	*/

	registDVD = IsRegistISBN(searchISBN);
	if (registDVD == 0) {
		puts("��ϵ��� ���� ISBN �Դϴ�.");
		getchar();
		return;
	}

	/*if (save->rentState == RENTED) {
	puts("�뿩 ���̶� �뿩�� �Ұ����մϴ�.");
	getchar();
	return;
	}
	*/

	rentSte = GetDVDRentState(searchISBN);
	if (rentSte == RENTED) {
		puts("�뿩 ���̶� �뿩�� �Ұ����մϴ�.");
		getchar();
		return;
	}

	puts("�뿩�� �����մϴ�. �뿩 ������ �����մϴ�.");
	fputs("�뿩 �� ID �Է� : ", stdout);
	gets(rentID);

	registCus = IsRegistID(rentID);

	/*if (GetCusPtrByID(rentID) == NULL) {
	puts("���� ���� �ƴմϴ�.");
	getchar();
	return;
	}
	*/

	if (registCus == 0) {
		puts("���� ���� �ƴմϴ�.");
		getchar();
		return;
	}

	//strcpy(save->rentList[save->numOfRentCus].cusID, rentID);
	fputs("�뿩 ��¥ �Է� : ", stdout);
	scanf("%u", &rentDay);
	getchar();

	//save->numOfRentCus++;
	//save->rentState = RENTED;
	SetDVDRented(searchISBN);

	AddRentList(searchISBN, rentID, rentDay);

	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;
}

/* �Լ� : void ReturnDVD(void)
* ��� : ���� DVD�� �ݳ��ϴ� ���� ó��
* ��ȯ : void
*/

void ReturnDVD(void) {
	char returnISBN[ISBN_LEN];
	int registDVD;
	int rentSte;
	//dvdInfo * save;

	fputs("�ݳ� DVD ISBN �Է� : ", stdout);
	gets(returnISBN);

	//save = GetDVDPtrByISBN(returnISBN);

	registDVD = IsRegistISBN(returnISBN);

	/*if (save == NULL) {
	puts("��ϵ��� �ʴ� ISBN �Դϴ�.");
	getchar();
	return;
	}
	*/

	if (registDVD == 0) {
		puts("��ϵ��� �ʴ� ISBN �Դϴ�.");
		getchar();
		return;
	}

	rentSte = GetDVDRentState(returnISBN);

	/*else if (save->rentState == RETURNED) {
	puts("�뿩���� ���� DVD �Դϴ�.");
	getchar();
	return;
	}
	*/

	if (rentSte == RETURNED) {
		puts("�뿩���� ���� DVD �Դϴ�.");
		getchar();
		return;
	}

	//save->rentState = RETURNED;
	SetDVDReturned(returnISBN);
	puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;

}

/* �Լ� : void RentedDVDList(void)
* ��� : Ư�� DVD �뿩�� ��ü���� ���
* ��ȯ : void
*/

void RentedDVDList(void) {
	char ISBN[ISBN_LEN];
	dvdInfo * save;

	fputs("ã�� ISBN �Է� : ", stdout);
	gets(ISBN);

	save = GetDVDPtrByISBN(ISBN);
	if (save == NULL) {
		puts("��ϵ��� �ʴ� ISBN �Դϴ�.");
		getchar();
		return;
	}

	PrintOutRentAllCusInfo(ISBN);

	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar();
	return;
}

/* �Լ� : void RegisterCustomer(void)
* ��� : �ű� ȸ�� ����
* ��ȯ : void
*
*/

void RegistCustomer(void) {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	fputs("ID �Է� : ", stdout);
	gets(ID);

	if (IsRegistID(ID)) {
		puts("�ش� ID�� ��� �߿� �ֽ��ϴ�. �ٸ� ID�� �������ּ���.");
		getchar();
		return;
	}

	fputs("�̸� �Է� : ", stdout);
	gets(name);
	fputs("��ȭ��ȣ �Է� : ", stdout);
	gets(phone);

	if (!AddCusInfo(ID, name, phone)) {
		puts("���� ��Ͽ� �����߽��ϴ�.");
	}
	else
		puts("������ �Ϸ�Ǿ����ϴ�.");

	getchar();
	return;
}

/* �Լ� : void SearchCusInfo(void)
* ��� : ID�� ���� ȸ�� ���� �˻�
* ��ȯ : void
*
*/

void SearchCusInfo(void) {
	char searchID[ID_LEN];
	cusInfo * save;

	fputs("ã�� ID �Է� : ", stdout);
	gets(searchID);
	save = GetCusPtrByID(searchID);
	if (save == NULL)
		puts("��ϵ� ȸ���� �����ϴ�.");
	else
		ShowCustomerInfo(save);

	getchar();
	return;
}

/* end of file */

void ShowAllCusRentedDVD(void) {
	char ID[ID_LEN];
	unsigned int start, end;
	cusInfo * save;

	fputs("ã�� ID �Է� : ", stdout);
	gets(ID);

	save = GetCusPtrByID(ID);
	if (save == NULL) {
		puts("���Ե� ȸ���� �����ϴ�.");
		getchar();
		return;
	}

	fputs("�뿩 �Ⱓ �Է� : ", stdout);
	scanf("%u %u", &start, &end);
	getchar();

	if (start > end) {
		puts("�Ⱓ ������ �߸� �ԷµǾ����ϴ�.");
		getchar();
		return;
	}

	PrintOutCusAllRentInfo(ID, start, end);

	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar();
	return;
}