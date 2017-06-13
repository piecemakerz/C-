#ifndef __KEY_CURSOR_H_
#define __KEY_CURSOR_H_

//#define ARROW_CHECK 224

#include "point.h"

void RemoveCursor(void);
point GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
//void CheckArrowInput(void);
int ProcessKeyInput(void);
void InitKeyDelayRate(int rate);
void KeyDelaySpeedCtl(int addSpeed);
//void IncreDelayRate(void);
//void SpaceInput(void);
#endif