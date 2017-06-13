#include "common.h"
#include "keyCurControl.h"

#define LEVEL_DIFF 2 // 단계별 속도 증가 정보
#define LEVEL_UP_SCORE_DIFF 20 // 레벨이 증가하는 스코어 간격 정보

static int curGameLevel = 1;
static int curGameScore = 0;

void ShowCurrentScoreAndLevel(void) {
	SetCurrentCursorPos(30, 4);
	printf("현재 레벨 : %d", curGameLevel);
	
	SetCurrentCursorPos(30, 7);
	printf("현재 점수 : %d", curGameScore);
}

void GameLevelUp(void) {
	curGameLevel++;
	KeyDelaySpeedCtl(LEVEL_DIFF);
}

void AddGameScore(int score) {
	if (score < 1)
		return;

	curGameScore += score;

	if (curGameScore >= curGameLevel * LEVEL_UP_SCORE_DIFF)
		GameLevelUp();
}
