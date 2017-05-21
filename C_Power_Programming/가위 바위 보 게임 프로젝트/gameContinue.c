#include "common.h"
#include "gameMoney.h"
#include "gameTimes.h"
#include "gameContinue.h"

void StartContinue(FILE * fp) {
	int choice;

	fputs("게임을 이어서 하시겠습니까? (Yes 1, No 0): ", stdout);
	scanf("%d", &choice);
	if (choice == 1) {
		/*int compumoney, gamermoney, gametimes, youwintimes;
		fscanf(fp, "%d %d %d %d", &compumoney, &gamermoney, &gametimes, &youwintimes);
		SetCompuContinueMoney(compumoney);
		SetGamerContinueMoney(gamermoney);
		SetGameTimes(gametimes);
		SetYouWinTimes(youwintimes);
		*/
		LoadGameTimesFromFile(fp);

		LoadGameMoneyFromFile(fp);
	}
	else if(choice == 0)
		return;
}

void SaveContinue(void) {
	int choice = 0;
	FILE * fp = fopen(FILE_NAME, "wb");
	fputs("게임 내용을 저장하시겠습니까? (Yes 1, No 0): ", stdout);
	scanf("%d", &choice);
	if (choice == 1) {
		StoreGameTimesToFile(fp);

		StoreGameMoneyToFile(fp);
	}
	fclose(fp);
	return;
}

void ClearContinueInfo(void) {
	FILE *fp;
	fp = fopen(FILE_NAME, "rb");

	if (fp != NULL) {
		fclose(fp);
		system(FILE_DEL_CMD);
	}
}