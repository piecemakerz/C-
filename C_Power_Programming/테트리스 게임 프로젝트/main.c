#include <Windows.h>
#include "keyCurControl.h"
#include "blockStageControl.h"

#define START_CURPOS_X (5*2)
#define START_CURPOS_Y (0)
#define SYS_DELAY 100

int main(void) {
	InitKeyDelayRate(10);

	RemoveCursor();

	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	ChooseBlock();

	while (1) {
		BlockDown();

		ProcessKeyInput();
	}

	/*while (1) {
		BlockDown();
		for (int i = 0; i < 15000; i++)
				CheckArrowInput();
		//Sleep(SYS_DELAY);
	}
	*/

	return 0;
} 