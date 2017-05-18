/*
 * Name : phoneFunc.c ver 1.1
 * Content : ��ȭ��ȣ ��Ʈ�� �Լ�
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.18
 */

#include "common.h"
#include "phoneData.h"
#include "ScreenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

/* �Լ� : void InputPhoneData(void)
 * ��� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
 * ��ȯ : void
 *
 */

void InputPhoneData(void)
{
	phoneData data;
	if (numOfData >= LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}
	fputs("�̸��� �Է��ϼ��� : ", stdout);
	gets(data.name);
	fputs("��ȭ��ȣ�� �Է��ϼ��� : ", stdout);
	gets(data.phoneNum);

	phoneList[numOfData++] = data;

	getchar();
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");

	return;
}

/* �Լ� : void ShowAllData(void)
 * ��� : ����� ������ ��ü ���
 * ��ȯ : void
 *
 */

void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		ShowPhoneInfo(phoneList[i]);
	}
	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
	return;
}
