/* Name : dvdManager.c ver 1.0
 * Content : DVD ���� ���� ó�� �Լ����� ����
 * Implementation : piecemaerz
 * Last modified 2017.05.23
 */

#include "common.h"
#include "dvdInfo.h"
#include "DVDInfoAccess.h"
#include "screenOut.h"
#include "cusInfoAccess.h"

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

void RentDVD(void) {
	char searchISBN[ISBN_LEN];
	char rentName[NAME_LEN];
	dvdInfo * save;

	fputs("�뿩 DVD ISBN �Է� : ", stdout);
	gets(searchISBN);
	save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL)
		puts("��ϵ� DVD�� �����ϴ�.");
	else {
		if (save->rentState == RENTED) {
			puts("�뿩 ���̶� �뿩�� �Ұ����մϴ�.");
			getchar();
			return;
		}

		puts("�뿩�� �����մϴ�. �뿩 ������ �����մϴ�.");
		fputs("�뿩 �� ID �Է� : ", stdout);
		gets(rentName);

		if (GetCusPtrByID(rentName) == NULL) {
			puts("���� ���� �ƴմϴ�.");
			getchar();
			return;
		}

		strcpy(save->rentList[save->numOfRentCus].cusID, rentName);
		fputs("�뿩 ��¥ �Է� : ", stdout);
		scanf("%d", &(save->rentList[save->numOfRentCus].rentDay));
		getchar();
	}
	save->numOfRentCus++;
	save->rentState = RENTED;
	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;
}

void ReturnDVD(void) {
	char returnISBN[ISBN_LEN];
	dvdInfo * save;
	fputs("�ݳ� DVD ISBN �Է� : ", stdout);
	gets(returnISBN);
	save = GetDVDPtrByISBN(returnISBN);

	if (save == NULL) {
		puts("��ϵ��� �ʴ� ISBN �Դϴ�.");
		getchar();
		return;
	}
	else if (save->rentState == RETURNED) {
		puts("�뿩���� ���� DVD �Դϴ�.");
		getchar();
		return;
	}

	save->rentState = RETURNED;
	puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;

}

void ReturnedDVDList(void) {
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

	for (int i = 0; i < save->numOfRentCus; i++) {
		printf("�뿩�� : %d\n", save->rentList[i].rentDay);
		ShowCustomerInfo(GetCusPtrByID(save->rentList[i].cusID));
		puts("");
	}
	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar();
	return;
}