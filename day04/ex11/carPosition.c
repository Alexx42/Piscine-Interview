#include "header.h"
#include <math.h>
#include <stdio.h>
int occupiedPlaces(unsigned int parkingRow) {
	int count = 0;
	while (parkingRow > 0) {
		count++;
		parkingRow &= parkingRow - 1;
	}
	return count;
}

int carPosition(unsigned int parkingRow) {
	int check = occupiedPlaces(parkingRow);
	if (check == 0 || check >= 2) {
		return -1;
	}
	int val = 0;
	int count = 0;
	while (!(parkingRow & val)) {

		count++;
		val = pow(2, val);
	}
	return count;
}