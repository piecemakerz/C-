/* Name : main.c ver 1.1
 * Content : main �Լ�
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.19
*/

#include "common.h"
#include "ScreenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, QUIT };
/* �Լ� : int main (void)
 * ��� : ����� ���� ó��
 * ��ȯ : ���� ���� �� 0
*/
int main(void) {
	int inputMenu = 0;

	while (1) {
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu) {
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowAllData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
		case DELETE:
			DeletePhoneData();
			break;
		}

		if (inputMenu == QUIT) {
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	return 0;
}

/* end of file*/