/* 블록, 게임화면 컨트롤 함수들의 정의*/
#include <time.h>
#include "common.h"
#include "point.h"
#include "blockInfo.h"
#include "keyCurControl.h"
#include "blockStageControl.h"

static int currentBlockModel;
static int curPosX, curPosY;

void InitNewBlockPos(int x, int y) {
	if (x < 0 || y < 0)
		return;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

void ChooseBlock(void) {
	srand((unsigned int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

int GetCurrentBlockIdx(void) {
	return currentBlockModel;
}

void ShowBlock(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("■");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

void DeleteBlock(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("  ");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

void BlockDown(void) {
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void ArrowMove(void) {
	int arrow = _getch();

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);

	switch (arrow) {

	case LEFT_ARROW:
		curPosX -= 2;
		SetCurrentCursorPos(curPosX, curPosY);
		break;
	case RIGHT_ARROW:
		curPosX += 2;
		SetCurrentCursorPos(curPosX, curPosY);
		break;
	case UPPER_ARROW:
		if (GetCurrentBlockIdx() % 4 == 3)
			currentBlockModel -= 3;
		else
			currentBlockModel += 1;
		break;
	}

	ShowBlock(blockModel[GetCurrentBlockIdx()]);

	return;
}