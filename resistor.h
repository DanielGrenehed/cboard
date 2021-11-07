#ifndef RESISTOR_H
#define RESISTOR_H
#include "range.h"

typedef struct {
	Range position;
	int row, resistance;
} Resistor;

typedef struct ResistorNode {
	struct ResistorNode *next;
	Resistor resistor;
} ResistorNode;

typedef struct ResistorList {
	ResistorNode *start;
} ResistorList;

/* Allocates space for and adds resistor to list */
void ResistorListAddResistor(ResistorList *list, Resistor r);

/* Removes(deallocates) first resistor covering point */
void ResistorListRemoveResistor(ResistorList *list, int row, int col);

/* Deallocates all elements in list */
void ResistorListClear(ResistorList *list);

/* Returns the column the other leg of the resistor is connected to, -1 if col not conncetd to resistor */
int ResistorGetOtherEndpoint(Resistor *aResistor, int col);

/* Returns 0 if no resistor at point, 1 if resistor covers point, 2 if a resistor starts
 * at point and 3 if resistor ends at point */
int ResistorListContainsPoint(ResistorList *list, int row, int col);

/* Returns 0 if no resistor intersects aResistor and 1 if one or more does */
int ResistorListOverlapsResistor(ResistorList *list, Resistor *aResistor); 

/* Calculates the size of the list */
int ResistorListSize(ResistorList *list);

/* Resistor factory */
Resistor CreateResistor(int row, int col1, int col2);

#endif /* ifndef RESISTOR_H */
