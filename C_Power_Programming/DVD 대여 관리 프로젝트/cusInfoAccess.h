/* Name : cusInfoAccess.h ver 1.0
 * Content : �� ���� ���� �� ���� �Լ����� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsRegistID(char * ID);

#endif
/* end of file */
