#ifndef __BLOCKST_CONTROL_H__
#define __BLOCKST_CONTROL_H__

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
void BlockDown(void);

#endif