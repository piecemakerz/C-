/* Name : screenOut.c ver 1.0 
 * Content : �ܼ� ����� ���� �Լ� ����
 * Implementation : piecemakerz
 *
 * Last modified 2015.05.18
 */

#include "common.h"
#include "phoneData.h"

/* �Լ� : void ShowMenu(void)
 * ��� : ������ ���� �޴� ���
 * ��ȯ : void
 *
 */

void ShowMenu(void) {
	system("cls");

	printf("------ ��	��------\n");
	printf(" 1. ��ȭ��ȣ �Է� \n");
	printf(" 2. ��ü ���� ��� \n");
	printf(" 3. ���� \n");
	printf("--------------------\n");
	printf("����>>");
}

/* �Լ� : void ShowPhoneInfo(phoneData phone)
 * ��� : �̸��� ��ȭ��ȣ ���� ���
 * ��ȯ : void
 */

void ShowPhoneInfo(phoneData phone) {
	printf("��--------------------\n");
	printf("| > �̸� : %s \n", phone.name);
	printf("| ��ȭ��ȣ : %d \n", phone.phoneNum);
	printf("��--------------------\n\n");
}

/* end of file */