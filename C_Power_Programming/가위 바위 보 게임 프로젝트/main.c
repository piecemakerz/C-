/* Name : main.c ver 2.0
 * Content : ���� main �Լ�
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#include "common.h"
#include "game.h"
#include "gameTimes.h"

int main(void) {
	int com;
	//char * comChoice;
	int you;
	//char * yourChoice;
	puts("��! ������ �����մϴ�.");
	puts("");

	while (1) {
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

		totalgame++;
		puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�");
		WhoIsWinner(com, you);

		printf(" �� ��ǻ���� ������ ");
		ShowRSP(com);
		puts("");

		printf(" �� ����� ������ ");
		ShowRSP(you);
		puts("");
		printf("�·�: %d\%", WinningRate());
		puts("");
		puts("");
	}
	puts("�̿��� �ּż� ������~");
	return 0;
}