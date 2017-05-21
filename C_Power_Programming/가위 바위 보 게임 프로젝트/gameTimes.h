/* Name : gameTimes.h ver 1.0
 * Content : �·� ���� �Լ� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#ifndef __GAMETIMES_H__
#define __GAMETIMES_H__

void IncreGameTimes(void);
int GetGameTimes(void);
void IncreYouWinTimes(void);
int GetYouWinTimes(void);
//void SetGameTimes(int num);
//void SetYouWinTimes(int num);
void StoreGameTimesToFile(FILE * fp);
void LoadGameTimesFromFile(FILE * fp);
int GetPercenOfVictory(void);

//int WinningRate(void);

#endif
/* end of file */