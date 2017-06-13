#include <Windows.h>
#include "common.h"
#include "keyCurControl.h"
#include "blockStageControl.h"
#include "scoreLevelControl.h"

#define START_CURPOS_X (5*2)
#define START_CURPOS_Y (2)
//#define SYS_DELAY 100

int main(void) {
	InitKeyDelayRate(10);

	RemoveCursor();

	DrawGameBoard();

	ShowCurrentScoreAndLevel();

	//printAllGameboardInfo();
	while(1) {

		InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

		ChooseBlock();

		if (IsGameOver())
			break;

		while (1) {
			if (BlockDown() == 0)
				//AddCurrentBlockInfoToBoard();
				//printAllGameboardInfo();
				break;

				/*if (CheckLineClear()) {
					RedrawBlocks();
					ShowInfo();
					CheckLevelUp();
				}
				*/
				//printAllGameboardInfo();
				if(ProcessKeyInput())
					break;
		}
	}
	/*while (1) {
		BlockDown();
		for (int i = 0; i < 15000; i++)
				CheckArrowInput();
		//Sleep(SYS_DELAY);
	}
	*/

	SetCurrentCursorPos(10, 10);
	puts("Game Over ^^");
	return 0;
} 