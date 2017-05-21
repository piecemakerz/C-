#ifndef __GAMECONTINUE_H__
#define __GAMECONTINUE_H__

#define FILE_NAME "gamedata.dat"
#define FILE_DEL_CMD "del gamedata.dat"

void StartContinue(FILE * fp);
void SaveContinue(void);
void ClearContinueInfo(void);

#endif