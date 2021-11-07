#ifndef BOARD_H
#define BOARD_H
#include "resistor.h"

typedef struct {
	ResistorList resistors;
	int width, height;
} Board;

/* Prints board represetation to standard-out */
void printBoard(Board*);

/* Returns value higher than 0 if resistor overlaps an existing resistor */ 
int BoardIsObstructed(Board *board, Resistor *r); 

/* Adds resistor to board if unobstructed */
int BoardPlaceResistor(Board *board, Resistor r);

/* Removes first restor overlapping point */
void BoardRemoveResistor(Board *board, int row, int col);

/* Returns 1 if columns connected either directly or through any number of resistor hops */
int BoardArePointsConnected(Board *board, int p1, int p2);

/* Deallocates board */
void ClearBoard(Board *board);

/* Board factory */
Board CreateBoard(int width, int height);

#endif /* ifndef BOARD_H */
