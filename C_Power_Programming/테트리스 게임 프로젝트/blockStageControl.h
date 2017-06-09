#ifndef __BLOCKST_CONTROL_H__
#define __BLOCKST_CONTROL_H__

/*#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UPPER_ARROW 72
*/

void InitNewBlockPos(int x, int y);
//void InitGameBoard(void);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
int DetectCollision(int posX, int posY, char blockModel[][4]);
int BlockDown(void);
void ShiftLeft(void);
void ShiftRight(void);
void RotateBlock(void);
void DrawGameBoard(void);
void AddCurrentBlockInfoToBoard(void);
int IsGameOver(void);

//void BlockPosSaved(char blockInfo[][4]);
//void DrawCurrentState(void);
//int LeftCrashCheck(char blockInfo[][4]);
//int RightCrashCheck(char blockInfo[][4]);
//int DownCrashCheck(char blockInfo[][4]);
#endif