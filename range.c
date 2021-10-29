#include "range.h"

int RangeContains(Range *aRange, int p) {
	if (p >= aRange->start && p <= aRange->end) return 1;
	return 0;
}

int RangeIntersects(Range *r1, Range *r2) {
	if (RangeContains(r2, r1->start)) return 1;
	if (RangeContains(r2, r1->end)) return 1;
	if (RangeContains(r1, r2->start)) return 1;
	//if (RangeContains(r2->end, r1)) return 1; /* unnecessary, if the two first if statements were not met, then either r1 contains r2 or they do not intersect */
	return 0;
}

