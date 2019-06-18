#include "header.h"

int occupiedPlaces(unsigned int parkingRow) {
	int count = 0;
	while (parkingRow > 0) {
		count++;
		parkingRow &= parkingRow - 1;
	}
	return count;
}

unsigned int clearPlace(unsigned int parkingRow, int pos) {
	if (parkingRow & (1 << pos))
		parkingRow ^= (1 << pos);
	return (parkingRow);
}

int leftmostCar(unsigned int parkingRow) {
	int m = occupiedPlaces(parkingRow);
	if (m == 0)
		return -1;
	int pos = 0;
	while (parkingRow) {
		parkingRow = clearPlace(parkingRow, pos);
		if (parkingRow)
			pos++;
	}
	return pos;
}