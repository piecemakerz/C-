#include "common.h"

static int gamermoney=1000;
static int compumoney=1000;

static int gamblingTableMoney;

void SetGamerMoney(void) {
	int money;
	fputs("# ����� �Ӵϸ� �Է��ϼ���: ", stdout);
	scanf("%d", &money);
	gamermoney = money;
}

/*void SetGamerContinueMoney(int money) {
	gamermoney = money;
	return;
}

void SetCompuContinueMoney(int money) {
	compumoney = money;
	return;
}
*/

void StoreGameMoneyToFile(FILE * fp) {
	fwrite(&compumoney, sizeof(int), 1, fp);
	fwrite(&gamermoney, sizeof(int), 1, fp);
}

void LoadGameMoneyFromFile(FILE * fp) {
	int readCnt1, readCnt2;

	readCnt1 = fread(&compumoney, sizeof(int), 1, fp);
	readCnt2 = fread(&gamermoney, sizeof(int), 1, fp);

	if (readCnt1 != 1 || readCnt2 != 1) {
		compumoney = 0;
		gamermoney = 0;
	}
}

void SetGamblingTableMoney(void) {
	int money;
	while (1) {
		puts("$ �ǵ� �����մϴ�! $");
		fputs("�ǵ� �Է�: ", stdout);
		scanf("%d", &money);
		puts("");

		if (money > gamermoney) {
			puts("�����ϰ� �ִ� �ݾ� ������ �ż���!");
			printf("����� ���� ���� �Ӵ� : %d\n", gamermoney);
		}
		else if (money > compumoney) {
			puts("��ǻ�� ���� �ݾ� �ʰ��Դϴ�!");
			printf("��ǻ���� ���� ���� �Ӵ� : %d\n", compumoney);
		}
		else {
			gamblingTableMoney = money;
			break;
		}
	}
	return;
}

void ComputerWin(void) {
	gamermoney -= gamblingTableMoney;
	compumoney += gamblingTableMoney;
}

void GamerWin(void) {
	gamermoney += gamblingTableMoney;
	compumoney -= gamblingTableMoney;
}

int GetCompumoney(void) {
	return compumoney;
}

int GetGamermoney(void) {
	return gamermoney;
}
