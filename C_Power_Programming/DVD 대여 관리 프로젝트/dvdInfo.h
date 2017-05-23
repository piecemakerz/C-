/* Name : dvdInfo.h ver 1.0
 * Content : ��ȭ DVD ���� ����ü
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum { ACTION = 1, COMIC, SF, ROMANTIC }; // �帣 ����
enum { RENTED, RETURNED };

typedef struct __dvdRentInfo {
	char cusID[ID_LEN]; // �뿩�� ID
	unsigned int rentDay; // �뿩��
}dvdRentInfo;

typedef struct __dvdInfo {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	int rentState; // �뿩 ���� ����
	int numOfRentCus; // ��ϵ� �뿩 ������ ����
	dvdRentInfo rentList[RENT_LEN]; // �뿩 ������ ����Ǵ� �迭
}dvdInfo;

#endif
/* end of file */