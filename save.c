#include "save.h"
#include <stdio.h>

/*
 *	width, height, numResistors
 *	resistors[numResistors]
 * */

void writeResistors(FILE *file, ResistorNode *node) {
	if (node->next != NULL) writeResistors(file, node->next);
	fwrite(&node->resistor, sizeof(Resistor), 1, file);
}

int SaveBoardToFile(char *filename, Board *board) {
	FILE *file = fopen(filename, "wb");
	int res = 0;
	int header[] = {board->width, board->height, ResistorListSize(&board->resistors)};
	if (fwrite(header, sizeof(int), 3, file)) {
		writeResistors(file, board->resistors.start);
		res = 1;
	} 
	fclose(file);
	return res;
}

Board LoadBoardFromFile(char *filename, int *success) {
	FILE *file = fopen(filename, "rb");
	int header[3];
	Board b;
	if (fread(header, sizeof(int), 3, file)) {
		b = CreateBoard(header[0], header[1]);
		printf("int1 %d int2 %d int3 %d\n", header[0], header[1], header[2]);
		for (int i = 0; i < header[2]; i++) {
			Resistor r;
			fread(&r, sizeof(Resistor), 1, file);
			ResistorListAddResistor(&b.resistors, r);
		}
		*success = 1;
	} else *success = 0;
	fclose(file);
	return b;
}
