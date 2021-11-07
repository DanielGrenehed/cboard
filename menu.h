#ifndef MENU_H
#define MENU_H
#include "board.h"

/* Clears standard in buffer */
void ClearBuffer();

/* Prompts user to input position of new resistor, then tries to add it to the board */
void AddResistor(Board*);

/* Prompts user to input position of resistor to remove, then tries to remove resistor from board */
void RemoveResistor(Board*);

/* Promts user for points to test connection between, then prints wether the points are connected or not*/
void TestConnection(Board*);

/* Promts user for a filename and tries to save board to file */
void SaveBoard(Board *);

/* Prints menu, prompts and handles user input, loops until user inputs 0 as a menu choice */
void MenuShow(Board *);

#endif /* ifndef MENU_H */
