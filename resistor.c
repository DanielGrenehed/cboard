#include "resistor.h"
#include <stdlib.h>

void ResistorListAddResistor(ResistorList *list, Resistor r) {
	ResistorNode *node = malloc(sizeof(ResistorNode));
	node->resistor = r;
	if (list->start != NULL) {
		node->next = list->start;
		list->start = node;
	} else {
		list->start = node;
	}

}

int ResistorContainsPoint(Resistor *r, int row, int col) {
	if (r->row == row) {
		if (r->position.start == col) return 2;
		if (r->position.end == col) return 3;
		if (RangeContains(&r->position, col)) return 1;
	}
	return 0;
}


void ResistorListRemoveResistor(ResistorList *list, int row, int col) {
	ResistorNode *prev = NULL;
	for (ResistorNode *it = list->start; it != NULL; it = it->next) {
		if (ResistorContainsPoint(&it->resistor, row, col)) {
			if (prev == NULL) {
				if (it->next == NULL) list->start = NULL;
				else list->start = it->next;
			} else {
				if (it->next == NULL) prev->next = NULL;
				else prev->next = it->next;
			}
			free(it);
			return;
		}
		prev = it;
	}
}

void RemoveTail(ResistorNode *list) {
	if (list->next != NULL) RemoveTail(list->next);
	free(list);
}

void ResistorListClear(ResistorList *list) {
	if (list->start != NULL) RemoveTail(list->start);
}

int ResistorGetOtherEndpoint(Resistor *aResistor, int col) {
	if (aResistor->position.start == col) return aResistor->position.end;
	if (aResistor->position.end == col) return aResistor->position.start;
	return -1;
}

int ResistorListContainsPoint(ResistorList *list, int row, int col) {
	for (ResistorNode *it = list->start; it != NULL; it=it->next) {
		int ans = ResistorContainsPoint(&it->resistor, row, col);
		if (ans > 0) return ans;
	}
	return 0;
}


int ResistorListOverlapsResistor(ResistorList *list, Resistor *aResistor) {
	for (ResistorNode *it = list->start; it != NULL; it = it->next) {
		if (it->resistor.row == aResistor->row) {
			if (RangeIntersects(&it->resistor.position, &aResistor->position)) return 1;
		}
	} 	
	return 0;
} 

int ResistorListSize(ResistorList *list) {
	int count = 0;
	for (ResistorNode *it = list->start; it != NULL; it = it->next) count++;
	return count;
}

Resistor CreateResistor(int row, int col1, int col2) {
	Range range = (Range){.start = col1 < col2 ? col1 : col2, .end = col1 > col2 ? col1 : col2};
	Resistor result = (Resistor){.position = range, .row = row, .resistance = 0};
	return result;
}
