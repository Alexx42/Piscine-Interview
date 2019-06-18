#include <stdio.h>

int carPosition(unsigned int parkingRow) {
	int count = 0;
	unsigned int tmp = parkingRow;
	while (parkingRow > 0) {
		count++;
		parkingRow &= parkingRow - 1;
	}
	if (count == 0 || count >= 2) {
		return -1;
	}
	parkingRow = tmp;
	count = 0;
	while (!(parkingRow & 1)) {
		count++;
		parkingRow = parkingRow >> 1;
	}
	return count;
}