#include "menu.h"
#include <stdio.h>
#include "colors.h"
#include "save.h"

void ClearBuffer() {
	char c = 0;
	while ((c = getchar()) != '\n' && c != EOF);
}
 
void printResistorList(ResistorList *list) {
	for (ResistorNode * node = list->start; node != NULL; node = node->next) {
		printf("Resistor {start=%d, end=%d, row=%d}\n", node->resistor.position.start, node->resistor.position.end, node->resistor.row);
	}
} 

int promptPoint(int *x, int *y, int max_x, int max_y) {
	printf("Enter x and y for point: %s", C_CYN);
	scanf("%d%d", x, y);
	ClearBuffer();
	printf(C_DEF);
	if (*x > max_x || *x < 0) {
		printf("%sEnter x between 0 and %d%s\n", C_RED, max_x-1, C_DEF);
		return 0;
	}
	if (*y > max_y || *y < 0) {
		printf("%sEnter y between 0 and %d%s\n", C_RED, max_y-1, C_DEF);
		return 0;
	}
	return 1;
}
	
void AddResistor(Board *board) {
	int row1, col1, row2, col2;
	if (!promptPoint(&col1, &row1, board->width, board->height)) return;
	if (!promptPoint(&col2, &row2, board->width, board->height)) return;

	if (row1 != row2 || col1 == col2) {
		printf("%sCan only connect horizontally%s\n", C_RED, C_DEF);
		return;
	} 
		
	Resistor r = CreateResistor(row1, col1, col2);
	
	if (!BoardPlaceResistor(board, r)) {
		printf("%sFailed to place resistor, obstructed!%s\n", C_RED, C_DEF);
	}
}

void RemoveResistor(Board *board) {
	int row, col;
	if (!promptPoint(&col, &row, board->width, board->height)) return;
	BoardRemoveResistor(board, row, col);
}

void TestConnection(Board *board) {
	int row1, col1, row2, col2;
	if (!promptPoint(&col1, &row1, board->width, board->height)) return;
	if (!promptPoint(&col2, &row2, board->width, board->height)) return;
	if (BoardArePointsConnected(board, col1, col2)) {
		printf("Point (%d, %d) is connected to (%d, %d)\n", col1, row1, col2, row2);
	} else {
		printf("Point (%d, %d) is NOT connected to (%d, %d)\n", col1, row1, col2, row2);
	}
}

void SaveBoard(Board *board) {
	char filename[50];
	printf("Enter filename:%s ", C_CYN);
	scanf("%s", filename);
	ClearBuffer();
	printf("\n%s", C_DEF);

	if (!SaveBoardToFile(filename, board)) {
		printf("%sFailed to write to %s %s\n", C_RED, filename, C_DEF);
	}
}
const char *Highlighter = C_BLU;
void printMenu() {
	printf("%s1:%s Add resistor to breadboard\n", Highlighter, C_DEF);
		printf("%s2:%s Remove resistor from breadboard\n", Highlighter, C_DEF);
		printf("%s3:%s Test connection between two points\n", Highlighter, C_DEF);
		printf("%s4:%s Save board to file\n", Highlighter, C_DEF);
		printf("%s0:%s Quit\n", Highlighter, C_DEF);
		printf("\nEnter menu choice> %s", C_CYN);
}

void MenuShow(Board *board) {
	int choice = -1;
	while (choice != 0) {
		//printResistorList(&board->resistors);
		printf("\n");
		printBoard(board);
		printf("\n");
		printMenu();
		scanf("%d", &choice);
		ClearBuffer();
		printf(C_DEF);

		switch (choice) {
			case 1:
				AddResistor(board);
				break;
			case 2:
				RemoveResistor(board);
				break;
			case 3:
				TestConnection(board);
				break;
			case 4:
				SaveBoard(board);
				break;
		}
	}	
}
