/* Name : game.c ver 1.1
 * Content : ���� ���� �Լ� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#include <time.h>
#include "common.h"
#include "game.h"

/* �Լ� : int ChoiceOfCom(void)
 * ��� : ������ ���� ��ȯ
 * ��ȯ : 0~99 ������ ���� ��ȯ
 *
 */

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 100;
}

/* �Լ� : int ChoiceOfMe(void)
 * ��� : ������� ������ �Է� ����
 * ��ȯ : ����� �Է�
 *
 */

int ChoiceOfMe(void) {
	int choice;
	fputs("Ȧ���̸� 1, ¦���̸� 2�� �Է�: ", stdout);
	scanf("%d", &choice);
	return choice;
}

/* �Լ� : void WhoIsWinner(int com, int you)
 * ��� : ���ڸ� ����
 * ��ȯ : void
 *
 */

void WhoIsWinner(int com, int you) {
	if ((com % 2) == (you % 2))
		puts("����� �����Դϴ�!");
	else
		puts("��ǻ���� �����̱���!");
	return;
}

/* end of file */