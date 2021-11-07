#ifndef SAVE_H
#define SAVE_H
#include "board.h"

/* Tries to write board to file, returns 0 on fail */
int SaveBoardToFile(char *filename, Board *board);

/* Tries to read board from file, success is set to 0 on fail */
Board LoadBoardFromFile(char *filename, int *success);

#endif /* ifndef SAVE_H */
