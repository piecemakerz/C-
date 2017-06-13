#include "common.h"
#include "keyCurControl.h"

#define LEVEL_DIFF 2 // �ܰ躰 �ӵ� ���� ����
#define LEVEL_UP_SCORE_DIFF 20 // ������ �����ϴ� ���ھ� ���� ����

static int curGameLevel = 1;
static int curGameScore = 0;

void ShowCurrentScoreAndLevel(void) {
	SetCurrentCursorPos(30, 4);
	printf("���� ���� : %d", curGameLevel);
	
	SetCurrentCursorPos(30, 7);
	printf("���� ���� : %d", curGameScore);
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
