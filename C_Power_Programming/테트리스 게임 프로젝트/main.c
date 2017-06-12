#include <Windows.h>
#include "keyCurControl.h"
#include "blockStageControl.h"

#define START_CURPOS_X (5*2)
#define START_CURPOS_Y (2)
#define SYS_DELAY 100

int main(void) {
	InitKeyDelayRate(10);

	RemoveCursor();

	DrawGameBoard();

	ShowInfo();

	//printAllGameboardInfo();
	while(1) {

		InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

		ChooseBlock();

		if (IsGameOver())
			break;

		while (1) {
			if (BlockDown() == 0) {
				AddCurrentBlockInfoToBoard();
				//printAllGameboardInfo();

				if (CheckLineClear()) {
					RedrawBlocks();
					ShowInfo();
					CheckLevelUp();
				}
				//printAllGameboardInfo();
				break;
			}
			
			ProcessKeyInput();
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