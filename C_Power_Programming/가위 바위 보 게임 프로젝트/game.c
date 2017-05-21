/* Name : game.c ver 2.1
 * Content : 게임 관련 함수 정의
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"

/* 함수 : int ChoiceOfCom(void)
 * 기능 : 무작위 값을 반환
 * 반환 : 1~3 범위의 값을 반환
 *
 */

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return (rand() % 3) + 1;
}

/* 함수 : int ChoiceOfMe(void)
 * 기능 : 사용자의 선택을 입력 받음
 * 반환 : 사용자 입력
 *
 */

int ChoiceOfMe(void) {
	int choice;
	fputs("가위(1) 바위(2) 보(3) 종료(4) 선택? ", stdout);
	scanf("%d", &choice);
	return choice;
}

/* 함수 : void WhoIsWinner(int com, int you)
 * 기능 : 승자를 가림
 * 반환 : void
 *
 */

void WhoIsWinner(int com, int you) {
	/*if( (com==1 && you==2) || (com==2 && you==3) || (com==3 && you==1))
		puts("당신이 승자입니다!");
	else if (com == you)
		puts("비겼습니다.");
	else
		puts("컴퓨터의 승자이군요!");
	return;
	*/
	int outcome = you - com;
	// extern int winplay;
	IncreGameTimes();

	switch (outcome) {
	case 0:
		puts("비겼습니다.");
		return;
	case 1: case -2:
		puts("당신이 승자입니다.");
		IncreYouWinTimes();
		GamerWin();
		//winplay++;
		return;
	}

	puts("컴퓨터가 승자이군요!");
	ComputerWin();
}

void ShowRSP(int rsp) {
	switch (rsp) {
	case SISSORS:
		fputs("가위", stdout);
		break;
	case ROCK:
		fputs("바위", stdout);
		break;
	case PAPER:
		fputs("보", stdout);
		break;
	}
}
/* end of file */