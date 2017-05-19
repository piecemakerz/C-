#pragma once
/* Name : screenOut.h ver 1.1
 * Content : 콘솔 출력을 위한 함수 선언
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.19
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData * phone);

#endif
/* end of file */