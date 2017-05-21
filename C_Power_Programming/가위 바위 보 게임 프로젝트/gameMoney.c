#include "common.h"

static int gamermoney=1000;
static int compumoney=1000;

static int gamblingTableMoney;

void SetGamerMoney(void) {
	int money;
	fputs("# 당신의 머니를 입력하세요: ", stdout);
	scanf("%d", &money);
	gamermoney = money;
}

void SetGamblingTableMoney(void) {
	int money;
	while (1) {
		puts("$ 판돈 설정합니다! $");
		fputs("판돈 입력: ", stdout);
		scanf("%d", &money);
		puts("");

		if (money > gamermoney) {
			puts("소유하고 있는 금액 내에서 거세요!");
			printf("당신의 현재 게임 머니 : %d\n", gamermoney);
		}
		else if (money > compumoney) {
			puts("컴퓨터 소유 금액 초과입니다!");
			printf("컴퓨터의 현재 게임 머니 : %d\n", compumoney);
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
