#ifndef BOARD_H
#define BOARD_H
#include "resistor.h"

typedef struct {
	ResistorList resistors;
	int width, height;
} Board;

void printBoard(Board*);

int BoardIsObstructed(Board *board, Resistor *r); 

int BoardPlaceResistor(Board *board, Resistor r);

void BoardRemoveResistor(Board *board, int row, int col);

int BoardArePointsConnected(Board *board, int p1, int p2);

void ClearBoard(Board *board);

Board CreateBoard(int width, int height);

#endif /* ifndef BOARD_H */
