#include <stdio.h>
#include <stdlib.h>
#include "board.h"


#include "colors.h"

void printBoard(Board *board) {
	for (int y = 0; y < board->height; y++) {
		printf("\t");
		for (int x = 0; x < board->width; x++) {
			int o = ResistorListContainsPoint(&board->resistors, y ,x);
			switch(o) {
				case 1:
					printf("--");
					break;
				case 2: // start 
					printf("%sX-", C_YLW);
					break;
				case 3: // end
					printf("X %s", C_DEF);
					break;
				default:
					printf("| ");
			}
		}
		printf("\n");
	}
}


int BoardIsObstructed(Board *board, Resistor *r) {
	return ResistorListOverlapsResistor(&board->resistors, r);
} 

int BoardPlaceResistor(Board *board, Resistor r) {
	if (!BoardIsObstructed(board, &r)) {
		ResistorListAddResistor(&board->resistors, r);
		return 1;
	}
	return 0;
}

void BoardRemoveResistor(Board *board, int row, int col) {
	ResistorListRemoveResistor(&board->resistors, row, col);	
}

/*
 * queue for points connected function
 *
 * */

/* assume positive integer */
typedef struct qnode {
	struct qnode *next;
	int value;
} QueueNode;

typedef struct Queue {
	QueueNode *start, *end;
} Queue;

int QueueIsEmpty(Queue *q) {
	return (q->start == NULL);
}

/* Will only accept positive integers */
void QueueEnqueue(Queue *q, int value) {
	if (value < 0) return;
	QueueNode *node = malloc(sizeof(QueueNode));
	node->value = value;
	if (QueueIsEmpty(q)) {
		q->start = node;
		q->end = node;
	} else {
		q->end->next = node;
		q->end = node;
	}
}

int QueueDequeue(Queue *q) {
	if (QueueIsEmpty(q)) return -1;
	int result = q->start->value;
	QueueNode *pop = q->start;
	if (q->start->next != NULL) q->start = q->start->next;
	else q->start = NULL;
	free(pop);
	return result;
}

void QueueClearQueue(Queue *q) {
	while (QueueDequeue(q) != -1);
}



int BoardArePointsConnected(Board *board, int p1, int p2) {
	if (p1 == p2) return 1;
	int *visited = malloc(sizeof(int) * (board->width));
	int found = 0;

	//printf("Searching for connection between col %d and %d\n", p1, p2);
	Queue q = (Queue){.start = NULL, .end = NULL};
	QueueEnqueue(&q, p1);
	visited[p1] = 1;
	//printf("Queue created.\n");

	while (!QueueIsEmpty(&q)) {
		int col = QueueDequeue(&q);
		
		//printf("Searching column %d!\n", col);
		//visited[col] = 2
		for (ResistorNode *node = board->resistors.start; node != NULL; node = node->next) {
			int connected_col = ResistorGetOtherEndpoint(&node->resistor, col);
			if (connected_col != -1) {
				if (connected_col == p2) {
					found = 1;
					//printf("Column %d found!\n", p2);
				} else if (visited[connected_col] < 1) {
					visited[connected_col] = 1;
					//printf("Added column %d to queue!\n", connected_col);
					QueueEnqueue(&q, connected_col);
				} else {
					//printf("Connected to column %d but you already knew that.\n", connected_col);
			
				}
			}
			if (found > 0) break;
		}
		if (found > 0) break;
	}

	QueueClearQueue(&q);
	free(visited);
	return found;
}

void ClearBoard(Board *board) {
	ResistorListClear(&board->resistors);
}

Board CreateBoard(int width, int height) {
	return (Board){.resistors= (ResistorList){.start=NULL}, .width=width, .height=height};
}
