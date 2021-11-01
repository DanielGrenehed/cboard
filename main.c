#include "menu.h" 
#include "save.h"
#include <stdio.h>

void promptBoardSize(Board *board) {
	printf("Enter size for board>");
	int res = scanf("%d", &board->width);
	if (res > 1) scanf("%d", &board->height);
	else board->height = board->width;
	ClearBuffer();
	printf("\n");
}

Board GenerateBoard(int argc, char **argv) {
	Board board = CreateBoard(0, 0);
	int success = 0;
	if (argc == 2) {
		success = sscanf(argv[1], "%d", &board.width);
		if (success) board.height = board.width;
		else {
			board = LoadBoardFromFile(argv[1], &success);
			if (!success) printf("Could not load %s !\n", argv[1]);
		}
	} else if (argc == 3) {
		success = sscanf(argv[1], "%d", &board.width);
		if (!success) printf("Accepts only numbers when provided with 2 arguments\n");
		
		success = sscanf(argv[2], "%d", &board.height);
		if (!success) printf("Accepts only numbers when provided with 2 arguments\n");
		
	} else if (argc > 3) printf("Too many arguments provided, max 2 arguments!\n");
	
	if (!success) promptBoardSize(&board);
	return board;
}

int main(int argc, char **argv) {
	Board board = GenerateBoard(argc, argv);

	if (board.width > 1 || board.height > 1) {
		MenuShow(&board);
	} else printf("Will not show boards of 1 or less dimentions!\n");
	ClearBoard(&board);
}

