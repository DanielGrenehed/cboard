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

int main(int argc, char **argv) {
	Board board = (Board){.width = 5, .height = 5};
	/*
	 *	initialize board depending on input arguments
	 *
	 *	// set size at startup
	 *	// load from file
	 *	// prompt user for size
	 * */
	int success = 0;
	if (argc == 2) {
		success = sscanf(argv[1], "%d", &board.width);
		if (success) {
			board.height = board.width;
		} else {
			board = LoadBoardFromFile(argv[1], &success);
			printf("Could not load %s !\n", argv[1]);
		}
	} else if (argc == 3) {
		success = sscanf(argv[1], "%d", &board.width);
		if (!success) {
			printf("Accepts only numbers when provided with 2 arguments\n");
			return 1;
		}
		success = sscanf(argv[2], "%d", &board.height);
		if (!success) {
			printf("Accepts only numbers when provided with 2 arguments\n");
			return 1;
		}
	} else if (argc > 3) {
		printf("Too many arguments provided, max 2 arguments!\n");
	}
	if (!success) promptBoardSize(&board);
	
	if (board.width > 1 || board.height > 1) {
		MenuShow(&board);
	} else printf("Will not show boards of 1 or less dimentions!\n");
	ClearBoard(&board);
}

