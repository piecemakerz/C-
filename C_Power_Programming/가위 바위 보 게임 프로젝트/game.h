/* Name : game.h ver 2.0
 * Content : ���� ���� �Լ� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#ifndef __GAME_H__
#define __GAME_H__

enum { SISSORS = 1, ROCK, PAPER };

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);
void ShowRSP(int rsp);
#endif

/* end of file */