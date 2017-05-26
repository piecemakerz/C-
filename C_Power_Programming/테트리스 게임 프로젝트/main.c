#include "common.h"
#include "BlockModels.h"

void ShowBlock(char blockInfo[][4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);

int main(void) {
	srand(time(NULL));
	RemoveCursor();

	int random_num[7] = { 0,4,8,12,16,20,24 };
	int pick = rand()%7;
	int y = 0;
	while (1) {
		system("cls");
		SetCurrentCursorPos(12, y);
		ShowBlock(blockModel[random_num[pick]]);
		y++;
		Sleep(100);
	}
}

void ShowBlock(char blockInfo[][4]) {
	int y, x;
	COORD curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (blockInfo[y][x] == 1)
				printf("бс");
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void SetCurrentCursorPos(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCurrentCursorPos(void) {
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

void RemoveCursor(void) {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}