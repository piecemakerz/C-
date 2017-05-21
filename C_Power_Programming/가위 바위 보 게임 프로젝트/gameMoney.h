#ifndef __GAMEMONEY_H__
#define __GAMEMONEY_H__

void ComputerWin(void);
void GamerWin(void);
int GetCompumoney(void);
int GetGamermoney(void);
void SetGamerMoney(void);
void SetGamblingTableMoney(void);
//void SetGamerContinueMoney(int money);
//void SetCompuContinueMoney(int money);
void StoreGameMoneyToFile(FILE * fp);
void LoadGameMoneyFromFile(FILE * fp);
#endif