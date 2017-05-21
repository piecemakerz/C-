/* Name : main.c ver 2.3
 * Content : 게임 main 함수
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
		puts("자! 게임을 시작합니다.");
		puts("");

		SetGamerMoney();
	}
	else {
		StartContinue(fp);
		fclose(fp);
	}
	printf("게이머 머니: %d\n", GetGamermoney());
	printf("컴퓨터 머니: %d\n", GetCompumoney());

	while (1) {
		SetGamblingTableMoney();
		puts("☆☆☆☆☆☆ 대결! ☆☆☆☆☆☆");
		com = ChoiceOfCom();
		/*if (com == SISSORS)
			comChoice = "가위";
		else if (com == ROCK)
			comChoice = "바위";
		else if (com == PAPER)
			comChoice = "보";
		*/
		you = ChoiceOfMe();
		if (you == 4)
			break;
		/*if (you == SISSORS)
			yourChoice = "가위";
		else if (you == ROCK)
			yourChoice = "바위";
		else if (you == PAPER)
			yourChoice = "보";
		*/
		puts("");

		//totalplay++;
		puts("★★★★★★ 결과! ★★★★★★");
		WhoIsWinner(com, you);

		printf(" ▷ 컴퓨터의 선택은 ");
		ShowRSP(com);
		puts("");

		printf(" ▷ 당신의 선택은 ");
		ShowRSP(you);
		puts("");

		printf("승률: %d%% \n", GetPercenOfVictory());
		puts("");

		printf("게이머 머니: %d\n", GetGamermoney());
		printf("컴퓨터 머니: %d\n", GetCompumoney());
		puts("");
		if (GetCompumoney() <= 0 || GetGamermoney() <= 0)
			break;
	}
	puts("◇◇◇◇◇◇ 최종 결과 ◇◇◇◇◇◇");
	printf("최종 승률: %d%%\n", GetPercenOfVictory());
	if (!(GetCompumoney() <= 0 || GetGamermoney() <= 0))
		SaveContinue();
	else
		ClearContinueInfo();
	puts("이용해 주셔서 고마워요~");
	return 0;
}