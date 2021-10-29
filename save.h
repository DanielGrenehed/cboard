#ifndef SAVE_H
#define SAVE_H
#include "board.h"

int SaveBoardToFile(char *filename, Board *board);
Board LoadBoardFromFile(char *filename, int *success);

#endif /* ifndef SAVE_H */
