#ifndef __KEY_CURSOR_H_
#define __KEY_CURSOR_H_

#define ARROW_CHECK 224

#include "point.h"

void RemoveCursor(void);
point GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
void CheckArrowInput(void);

#endif