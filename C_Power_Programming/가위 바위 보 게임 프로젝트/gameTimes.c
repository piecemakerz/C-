/* Nmae : gameTimes.c ver 1.0
 * Content: ½Â·ü °ü·Ã ÇÔ¼ö Á¤ÀÇ
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

/*int totalplay = 0;
  int winplay = 0;
*/
#include "common.h"

static int gameNumOfTimes = 0;
static int youWinNumOfTimes = 0;

void IncreGameTimes(void) {
	gameNumOfTimes++;
}

int GetGameTimes(void) {
	return gameNumOfTimes;
}

void IncreYouWinTimes(void) {
	youWinNumOfTimes++;
}

int GetYouWinTimes(void) {
	return youWinNumOfTimes;
}

int GetPercenOfVictory(void) {
	if (gameNumOfTimes == 0)
		return 0;
	
	return (double)youWinNumOfTimes / gameNumOfTimes * 100;
}

/*void SetGameTimes(int num) {
	gameNumOfTimes = num;
}

void SetYouWinTimes(int num) {
	youWinNumOfTimes = num;
}
*/

void StoreGameTimesToFile(FILE * fp) {
	fwrite(&gameNumOfTimes, sizeof(int), 1, fp);
	fwrite(&youWinNumOfTimes, sizeof(int), 1, fp);
}

void LoadGameTimesFromFile(FILE * fp) {
	int readCnt1, readCnt2;

	readCnt1 = fread(&gameNumOfTimes, sizeof(int), 1, fp);
	readCnt2 = fread(&youWinNumOfTimes, sizeof(int), 1, fp);

	if (readCnt1 != 1 || readCnt2 != 1) {
		gameNumOfTimes = 0;
		youWinNumOfTimes = 0;
	}
}
/*int WinningRate(void) {
	return  ((double)winplay / totalplay) * 100;
}
*/
/* end of file */