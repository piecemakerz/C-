#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "dvdInfo.h"
#include "cusInfo.h"

typedef struct __dvdRentInfo {
	char cusID[ID_LEN]; // 대여고객 ID
	char ISBN[ISBN_LEN]; // 대여 DVD ISBN
	unsigned int rentDay; // 대여일
}dvdRentInfo;

#endif
/* end of file */
