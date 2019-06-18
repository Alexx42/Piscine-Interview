#include "header.h"

int occupiedPlaces(unsigned int parkingRow) {
	int count = 0;
	while (parkingRow > 0) {
		count++;
		parkingRow &= parkingRow - 1;
	}
	return count;
}
