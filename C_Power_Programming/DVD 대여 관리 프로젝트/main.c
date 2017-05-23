/* Name : main.c ver 1.0
 * Content : DVD �뿩 ���� ���α׷� main
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.23
 */

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum { CUS_REGIST = 1, CUS_SEARCH, QUIT };

int main(void)
{
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
		}

		if (inputMenu == QUIT) {
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	return 0;
}

/* end of file */