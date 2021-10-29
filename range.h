#ifndef RANGE_H
#define RANGE_H

typedef struct {
	int start, end; /* start should be smaller or equal to end */
} Range;

/* Returns 1 if p is a number in aRange, else 0 */
int RangeContains(Range *aRange, int p);

/* Returns 1 if r1 intersects with r2 else 0*/
int RangeIntersects(Range *r1, Range *r2);

#endif /* ifndef RANGE_H */
