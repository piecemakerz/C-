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

/* �Լ� : void RegisterCustomer(void)
 * ��� : �ű� ȸ�� ����
 * ��ȯ : void
 *
 */

void RegistCustomer(void) {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	while (1) {
		fputs("ID �Է� : ", stdout);
		scanf("%s", ID);
		if (IsRegistID(ID)) {
			puts("�ش� ID�� ��� �߿� �ֽ��ϴ�. �ٸ� ID�� �������ּ���.");
		}
		else
			break;
	}
	fputs("�̸� �Է� : ", stdout);
	scanf("%s", name);
	fputs("��ȭ��ȣ �Է� : ", stdout);
	scanf("%s", phone);
	getchar();

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
	scanf("%s", searchID);
	getchar();
	save = GetCusPtrByID(searchID);
	if (save == NULL)
		puts("��ϵ� ȸ���� �����ϴ�.");
	else
		ShowCustomerInfo(save);

	getchar();
	return;
}

/* end of file */