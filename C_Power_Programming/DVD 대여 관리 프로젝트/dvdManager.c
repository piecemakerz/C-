/* Name : dvdManager.c ver 1.0
 * Content : DVD ���� ���� ó�� �Լ����� ����
 * Implementation : piecemaerz
 * Last modified 2017.05.23
 */

#include "common.h"
#include "dvdInfo.h"
#include "DVDInfoAccess.h"
#include "screenOut.h"

/* �Լ� : void RegistDVD(void)
* ��� : DVD ���
* ��ȯ : void
*
*/

void RegistDVD(void) {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	fputs("ISBN �Է� : ", stdout);
	gets(ISBN);
	if (IsRegistISBN(ISBN)) {
		puts("�ش� ISBN�� �̹� ��ϵǾ����ϴ�.");
		getchar();
		return;
	}
	
	fputs("���� �Է� : ", stdout);
	gets(title);
	fputs("�帣 �Է� (�׼� 1, �ڹ� 2, SF 3, �θ�ƽ 4) : ", stdout);
	scanf("%d", &genre);
	getchar();

	if (!AddDVDInfo(ISBN, title, genre))
		puts("DVD ��Ͽ� �����߽��ϴ�.");
	else
		puts("����� �Ϸ�Ǿ����ϴ�.");

	getchar();
	return;
}

/* �Լ� : void SearchDVDInfo(void)
* ��� : ISBN�� ���� ȸ�� ���� �˻�
* ��ȯ : void
*
*/

void SearchDVDInfo(void) {
	char searchISBN[ISBN_LEN];
	dvdInfo * save;

	fputs("ã�� ISBN �Է� : ", stdout);
	gets(searchISBN);
	save = GetDVDPtrByISBN(searchISBN);
	if (save == NULL)
		puts("��ϵ� DVD�� �����ϴ�.");
	else
		ShowDVDInfo(save);

	getchar();
	return;
}
