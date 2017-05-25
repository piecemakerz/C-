#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDVDPtrByISBN(char * ISBN);
int IsRegistISBN(char * ISBN);

int SetDVDRented(char * ISBN);
int SetDVDReturned(char * ISBN);
int GetDVDRentState(char * ISBN);

void LoadDVDInfo(void);
void ChangeDVDInfo(dvdInfo * pDVD);
#endif
/* end of file */