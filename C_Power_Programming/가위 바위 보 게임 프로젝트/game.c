/* Name : game.c ver 2.1
 * Content : ���� ���� �Լ� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"

/* �Լ� : int ChoiceOfCom(void)
 * ��� : ������ ���� ��ȯ
 * ��ȯ : 1~3 ������ ���� ��ȯ
 *
 */

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return (rand() % 3) + 1;
}

/* �Լ� : int ChoiceOfMe(void)
 * ��� : ������� ������ �Է� ����
 * ��ȯ : ����� �Է�
 *
 */

int ChoiceOfMe(void) {
	int choice;
	fputs("����(1) ����(2) ��(3) ����(4) ����? ", stdout);
	scanf("%d", &choice);
	return choice;
}

/* �Լ� : void WhoIsWinner(int com, int you)
 * ��� : ���ڸ� ����
 * ��ȯ : void
 *
 */

void WhoIsWinner(int com, int you) {
	/*if( (com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1))
		puts("����� �����Դϴ�!");
	else if (com == you)
		puts("�����ϴ�.");
	else
		puts("��ǻ���� �����̱���!");
	return;
	*/
	int outcome = you - com;
	// extern int winplay;
	IncreGameTimes();

	switch (outcome) {
	case 0:
		puts("�����ϴ�.");
		return;
	case 1: case -2:
		puts("����� �����Դϴ�.");
		IncreYouWinTimes();
		GamerWin();
		//winplay++;
		return;
	}

	puts("��ǻ�Ͱ� �����̱���!");
	ComputerWin();
}

void ShowRSP(int rsp) {
	switch (rsp) {
	case SISSORS:
		fputs("����", stdout);
		break;
	case ROCK:
		fputs("����", stdout);
		break;
	case PAPER:
		fputs("��", stdout);
		break;
	}
}
/* end of file */