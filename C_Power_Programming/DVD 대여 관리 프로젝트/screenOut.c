/* Name : screenOut.c ver 1.0
 * Content : �ܼ� ����� ���� �Լ����� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "cusInfo.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void) {
	system("cls");

	printf("------- �޴� ------ \n");
	printf("1. �ű԰��� \n");
	printf("2. ���˻� \n");
	printf("3. ���� \n");
	printf("------------------- \n");
	printf("����>> ");
}

/* �� ������ �⺻ ���� ��� */
void ShowCustomerInfo(cusInfo * pCus) {

	printf("��----------------- \n");
	printf("���� ID : %s \n", pCus->ID);
	printf("���� �̸� : %s \n", pCus->name);
	printf("���� ��ȭ��ȣ : %s \n", pCus->phoneNum);
	printf("��------------------ \n");
}

/* end of file */