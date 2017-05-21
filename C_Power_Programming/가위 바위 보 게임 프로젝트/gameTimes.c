/* Nmae : gameTimes.c ver 1.0
 * Content: ½Â·ü °ü·Ã ÇÔ¼ö Á¤ÀÇ
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

/*int totalplay = 0;
  int winplay = 0;
*/

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
/*int WinningRate(void) {
	return  ((double)winplay / totalplay) * 100;
}
*/
/* end of file */