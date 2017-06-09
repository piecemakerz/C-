/* 블록, 게임화면 컨트롤 함수들의 정의*/
#include <time.h>
#include "common.h"
#include "point.h"
#include "blockInfo.h"
#include "keyCurControl.h"
#include "blockStageControl.h"

#define GBOARD_WIDTH (10)
#define GBOARD_HEIGHT (20)

#define GBOARD_ORIGIN_X (2*2)
#define GBOARD_ORIGIN_Y (2)

static int currentBlockModel;
static int curPosX, curPosY;
static int rotateSte;
//static int savedBlocks[GBOARD_HEIGHT+1][GBOARD_WIDTH+2] = { 0, };
static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };

void InitNewBlockPos(int x, int y) {
	if (x < 0 || y < 0)
		return;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

/* void InitGameBoard(void) {
	for (int i = 0; i < GBOARD_HEIGHT + 1; i++) {
		savedBlocks[i][0] = 1;
		savedBlocks[i][GBOARD_WIDTH + 1] = 1;
	}

	for (int i = 0; i < GBOARD_WIDTH + 2; i++)
		savedBlocks[GBOARD_HEIGHT][i] = 1;
}
*/

void ChooseBlock(void) {
	srand((unsigned int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

int GetCurrentBlockIdx(void) {
	return currentBlockModel + rotateSte;
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

int DetectCollision(int posX, int posY, char blockModel[][4]) {
	int x, y;

	int arrX = (posX - GBOARD_ORIGIN_X) / 2;
	int arrY = posY - GBOARD_ORIGIN_Y;

	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			if (blockModel[y][x] == 1 && gameBoardInfo[arrY + y][arrX + x] == 1)
				return 0;
		}
	}
	return 1;
}

int BlockDown(void) {
	/*if (DownCrashCheck(blockModel[GetCurrentBlockIdx()])) {
		BlockPosSaved(blockModel[GetCurrentBlockIdx()]);
		DrawCurrentState();
		return 1;
	}
	*/
	if (!DetectCollision(curPosX, curPosY + 1, blockModel[GetCurrentBlockIdx()]))
		return 0;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);

	return 1;
}

/*void ArrowMove(void) {
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
*/

void ShiftLeft(void) {
	/*if (LeftCrashCheck(blockModel[GetCurrentBlockIdx()]))
		return;
	*/
	if (!DetectCollision(curPosX - 2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 2;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void ShiftRight(void) {
	/*if (RightCrashCheck(blockModel[GetCurrentBlockIdx()]))
		return;
	*/
	if (!DetectCollision(curPosX + 2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 2;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void RotateBlock(void) {
	int nextRotSte;

	nextRotSte = rotateSte + 1;
	nextRotSte %= 4;

	/*if (LeftCrashCheck(blockModel[nextRotSte]) || RightCrashCheck(blockModel[nextRotSte]) || DownCrashCheck(blockModel[nextRotSte]))
		return;
	*/
	if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
		return;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	rotateSte = nextRotSte;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void DrawGameBoard(void) {
	int x, y;

	for (y = 0; y <= GBOARD_HEIGHT; y++) {
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("└");
		else
			printf("│");
	}

	for (y = 0; y <= GBOARD_HEIGHT; y++) {
		SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("┘");
		else
			printf("│");
	}

	for (x = 1; x < GBOARD_WIDTH + 1; x++) {
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("─");
	}

	SetCurrentCursorPos(0, 0);

	//InitGameBoard();

	for (y = 0; y < GBOARD_HEIGHT; y++) {
		gameBoardInfo[y][0] = 1;
		gameBoardInfo[y][GBOARD_WIDTH + 1] = 1;
	}

	for (x = 0; x < GBOARD_WIDTH + 2; x++) {
		gameBoardInfo[GBOARD_HEIGHT][x] = 1;
	}
}

void AddCurrentBlockInfoToBoard(void) {
	int x, y;

	int arrCurX;
	int arrCurY;

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			arrCurX = (curPosX - GBOARD_ORIGIN_X) / 2;
			arrCurY = curPosY - GBOARD_ORIGIN_Y;

			if (blockModel[GetCurrentBlockIdx()][y][x] == 1)
				gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
		}
	}
}

int IsGameOver(void) {
	if (!DetectCollision(curPosX, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 1;
	else
		return 0;
}

/*void BlockPosSaved(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (blockInfo[y][x] == 1)
				savedBlocks[curPos.y - GBOARD_ORIGIN_Y + y][(curPos.x - GBOARD_ORIGIN_X)/2 + x] = 1;
		}
	}
}

void DrawCurrentState(void) {
	int y, x;
	SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y);

	for (y = 0; y < GBOARD_HEIGHT; y++) {
		for (x = 0; x < GBOARD_WIDTH; x++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + y);
			if (savedBlocks[y][x] == 1)
				printf("■");
		}
	}
	SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y);
}

int LeftCrashCheck(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (blockInfo[y][x] == 1 && savedBlocks[curPos.y - GBOARD_ORIGIN_Y + y][(curPos.x - GBOARD_ORIGIN_X)/2 + x - 1] == 1)
				return 1;
		}
	}

	return 0;
}

int RightCrashCheck(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 3; x >= 0; x--) {
			if (blockInfo[y][x] == 1 && savedBlocks[curPos.y - GBOARD_ORIGIN_Y + y][(curPos.x - GBOARD_ORIGIN_X)/2 + x + 1] == 1)
				return 1;
		}
	}
	return 0;
}

int DownCrashCheck(char blockInfo[][4]) {
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (blockInfo[y][x] == 1 && savedBlocks[curPos.y - GBOARD_ORIGIN_Y + y + 1][(curPos.x - GBOARD_ORIGIN_X)/2 + x] == 1)
				return 1;
		}
	}

	return 0;
}
*/