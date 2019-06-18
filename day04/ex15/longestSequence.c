#include "header.h"

int longestSequence(unsigned int parkingRow) {
	int count = 0;
	while (parkingRow) {
		parkingRow = (parkingRow + parkingRow) & parkingRow;
		count++;
	}
	return count;
}