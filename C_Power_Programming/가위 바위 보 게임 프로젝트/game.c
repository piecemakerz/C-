/* Name : game.c ver 1.1
 * Content : 게임 관련 함수 정의
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#include <time.h>
#include "common.h"
#include "game.h"

/* 함수 : int ChoiceOfCom(void)
 * 기능 : 무작위 값을 반환
 * 반환 : 0~99 범위의 값을 반환
 *
 */

int ChoiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 100;
}

/* 함수 : int ChoiceOfMe(void)
 * 기능 : 사용자의 선택을 입력 받음
 * 반환 : 사용자 입력
 *
 */

int ChoiceOfMe(void) {
	int choice;
	fputs("홀수이면 1, 짝수이면 2를 입력: ", stdout);
	scanf("%d", &choice);
	return choice;
}

/* 함수 : void WhoIsWinner(int com, int you)
 * 기능 : 승자를 가림
 * 반환 : void
 *
 */

void WhoIsWinner(int com, int you) {
	if ((com % 2) == (you % 2))
		puts("당신이 승자입니다!");
	else
		puts("컴퓨터의 승자이군요!");
	return;
}

/* end of file */