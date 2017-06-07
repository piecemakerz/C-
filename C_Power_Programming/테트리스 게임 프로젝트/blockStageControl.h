#ifndef __BLOCKST_CONTROL_H__
#define __BLOCKST_CONTROL_H__

#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UPPER_ARROW 72

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
void BlockDown(void);

#endif