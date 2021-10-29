#ifndef MENU_H
#define MENU_H
#include "board.h"

void ClearBuffer();
void AddResistor(Board*);
void RemoveResistor(Board*);
void TestConnection(Board*);
void SaveBoard(Board *);

void MenuShow(Board *);

#endif /* ifndef MENU_H */
