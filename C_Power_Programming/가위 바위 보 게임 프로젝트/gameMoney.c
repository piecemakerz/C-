static int gamermoney = 1000;
static int compumoney = 1000;

#define GamblingTableMoney 200

void ComputerWin(void) {
	gamermoney -= GamblingTableMoney;
	compumoney += GamblingTableMoney;
}

void GamerWin(void) {
	gamermoney += GamblingTableMoney;
	compumoney -= GamblingTableMoney;
}

int GetCompumoney(void) {
	return compumoney;
}

int GetGamermoney(void) {
	return gamermoney;
}
