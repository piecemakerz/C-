/* Name : screenOut.c ver 1.1
 * Content : �ܼ� ����� ���� �Լ����� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void) {
	system("cls");

	printf("------- �޴� ------ \n");
	printf("1. �ű԰��� \n");
	printf("2. ���˻� \n");
	printf("------------------- \n");
	printf("3. DVD ��� \n");
	printf("4. DVD �˻� \n");
	printf("------------------- \n");
	printf("5. ���� \n");
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

void ShowDVDInfo(dvdInfo * pDVD) {
	printf("��----------------- \n");
	printf("���� ISBN : %s \n", pDVD->ISBN);
	printf("���� Ÿ��Ʋ : %s \n", pDVD->title);
	printf("���� �帣 : "); 
	switch (pDVD->genre) {
	case ACTION:
		puts("�׼�");
		break;
	case COMIC:
		puts("�ڹ�");
		break;
	case SF:
		puts("SF");
		break;
	case ROMANTIC:
		puts("�θ�ƽ");
		break;
	}
	printf("��------------------ \n");
}
/* end of file */