#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value) {
	parkingRow &= ~(1 << pos);
	parkingRow |= (value << pos);
	return parkingRow;
}