#ifndef __RENTINFOACC_H__
#define __RENTINFOACC_H__

void AddRentList(char * ISBN, char * cusID, int rentDay);
void PrintOutRentAllCusInfo(char * ISBN);
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end);

#endif;