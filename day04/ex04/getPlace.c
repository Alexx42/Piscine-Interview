#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPlace(unsigned int parkingRow, int pos) {
	if (parkingRow & (1 << (pos)))
		return 1;
	return 0;
}