/* Name : main.c ver 1.0
 * Content : main �Լ�
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.18
*/

#include "common.h"
#include "ScreenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, QUIT };
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
		}

		if (inputMenu == QUIT) {
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	return 0;
}

/* end of file*/