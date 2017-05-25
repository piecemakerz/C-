/* Name : screenOut.h ver 1.1
 * content : �ܼ� ����� ���� �Լ����� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo * pCus);
void ShowDVDInfo(dvdInfo * pDVD);
void ShowCusRentDVDInfo(dvdRentInfo * pDVDRent);

#endif
/* end of file */