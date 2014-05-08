/**
 * Implementation of the software paging unit.
*/
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}
/*
* logical-to-physical paged memory address translation.
*/
int getPhysical(int logical) {
    // JD: There are TAAAAAABBBBBS below this line...NOOOOOOOOO.........
	/**
	 * The left most 4 bits and the right most four bits.
	*/
	int leftMostBits = ((logical & PAGEMASK) >> PAGEBITS);
    // JD: ^^^Note, bitwise-"&" is not necessary due to right shift.
	int rightMostBits = (logical & PAGESIZE);

    // JD: The maximum value check can be unhardcoded by using the #define's
    //     in the .h file.
	if (logical < 0 || logical >= 256) {
        return ERR_OUT_OF_RANGE;
    }

	if (ptr[leftMostBits].valid == 0) {
		return ERR_INVALID;
	}
    return (((ptr[leftMostBits].frame) << PAGEBITS) + rightMostBits);
}