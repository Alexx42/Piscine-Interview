#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int clearBits(unsigned int parkingRow, int n) {
	int val = 0;
	for (int i = 0; i < n; i++) {
		val += pow(2, i);
	}
	return parkingRow & ~val;
}