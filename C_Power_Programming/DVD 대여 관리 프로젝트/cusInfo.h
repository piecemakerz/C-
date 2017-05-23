/* Name : cusInfo.h ver 1.0
* Content : �� ���� ����ü
* Implementation : piecemakerz
*
* Last modified 2017.05.23
*/

#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN 10
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __cusInfo {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
} cusInfo;

#endif
/* end of file */