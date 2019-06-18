#include "header.h"
#include <math.h>

int occupiedPlaces(unsigned int parkingRow) {
	int count = 0;
	while (parkingRow > 0) {
		count++;
		parkingRow &= parkingRow - 1;
	}
	return count;
}

int rightmostCar(unsigned int parkingRow) {
	int pos = 0;
	if (occupiedPlaces(parkingRow) == 0)
		return -1;
	while (!(parkingRow & (1 << pos))) {
		pos++;
	}
	return pos;
}