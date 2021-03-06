/* Name : main.c ver 1.1
 * Content : DVD 대여 관리 프로그램 main
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "blManager.h"
#include "screenOut.h"
#include "rentInfoAccess.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"

enum { CUS_REGIST = 1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, DVD_RENT, DVD_RETURN, DVD_INQUIRY, CUS_DVD_INQUIRY, QUIT };

int main(void)
{
	LoadCusInfo();
	LoadDVDInfo();
	LoadRentList();

	int inputMenu = 0;

	while (1) {
		ShowMenu();
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu) {
		case CUS_REGIST:
			RegistCustomer();
			break;

		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;

		case DVD_RENT:
			RentDVD();
			break;

		case DVD_RETURN:
			ReturnDVD();
			break;

		case DVD_INQUIRY:
			RentedDVDList();
			break;

		case CUS_DVD_INQUIRY:
			ShowAllCusRentedDVD();
			break;
		}

		if (inputMenu == QUIT) {
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	return 0;
}

/* end of file */