/* Name : game.h ver 1.0
 * Content : ���� ���� �Լ� ����
 * Implementation : piecemakerz
 *
 * Last modified 2017.05.21
 */

#ifndef __GAME_H__
#define __GAME_H__

enum { ODD = 1, EVEN };

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);

#endif

/* end of file */