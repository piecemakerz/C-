/* Name : cusManager.c ver 1.1
 * Content : �� ���� ���� ó�� �Լ����� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"
#include "rentInfoAccess.h"

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