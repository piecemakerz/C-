/* Name : main.c ver 2.3
 * Content : ���� main �Լ�
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"

int main(void) {
	extern int totalplay;
	int com;
	//char * comChoice;
	int you;
	//char * yourChoice;
	FILE * fp = fopen(FILE_NAME, "rb");
	if (fp == NULL) {
		puts("��! ������ �����մϴ�.");
		puts("");

		SetGamerMoney();
	}
	else {
		StartContinue(fp);
		fclose(fp);
	}
	printf("���̸� �Ӵ�: %d\n", GetGamermoney());
	printf("��ǻ�� �Ӵ�: %d\n", GetCompumoney());

	while (1) {
		SetGamblingTableMoney();
		puts("�١١١١١� ���! �١١١١١�");
		com = ChoiceOfCom();
		/*if (com == SISSORS)
			comChoice = "����";
		else if (com == ROCK)
			comChoice = "����";
		else if (com == PAPER)
			comChoice = "��";
		*/
		you = ChoiceOfMe();
		if (you == 4)
			break;
		/*if (you == SISSORS)
			yourChoice = "����";
		else if (you == ROCK)
			yourChoice = "����";
		else if (you == PAPER)
			yourChoice = "��";
		*/
		puts("");

		//totalplay++;
		puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�");
		WhoIsWinner(com, you);

		printf(" �� ��ǻ���� ������ ");
		ShowRSP(com);
		puts("");

		printf(" �� ����� ������ ");
		ShowRSP(you);
		puts("");

		printf("�·�: %d%% \n", GetPercenOfVictory());
		puts("");

		printf("���̸� �Ӵ�: %d\n", GetGamermoney());
		printf("��ǻ�� �Ӵ�: %d\n", GetCompumoney());
		puts("");
		if (GetCompumoney() <= 0 || GetGamermoney() <= 0)
			break;
	}
	puts("�ޡޡޡޡޡ� ���� ��� �ޡޡޡޡޡ�");
	printf("���� �·�: %d%%\n", GetPercenOfVictory());
	if (!(GetCompumoney() <= 0 || GetGamermoney() <= 0))
		SaveContinue();
	else
		ClearContinueInfo();
	puts("�̿��� �ּż� ������~");
	return 0;
}