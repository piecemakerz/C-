/* Name : phoneData.h ver 1.0
 * Content : 구조체 phoneData의 선언 및 정의
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.18
 */

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __phoneData
{
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
} phoneData;

#endif
/* end of file */