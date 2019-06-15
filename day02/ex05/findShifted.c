#include "header.h"
#include <stdio.h>
#include <stdlib.h>

static int findPivot(int *rocks, int low, int high) {
	if (high < low)
		return -1;
	if (high == low)
		return low;
	int mid = (low + high) / 2;
	if (mid < high && rocks[mid] > rocks[mid + 1])
		return mid;
	if (mid > low && rocks[mid] < rocks[mid - 1]) 
		return (mid-1);
	if (rocks[low] >= rocks[mid])
   		return findPivot(rocks, low, mid-1); 
   return findPivot(rocks, mid + 1, high);
}

static int binarySearch(int *rocks, int low, int high, int value) {
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (rocks[mid] == value)
		return mid;
	if (value > rocks[mid])
		return binarySearch(rocks, (mid + 1), high, value);
	return binarySearch(rocks, low, (mid - 1), value);
}

static int pivotedBinarySearch(int *rocks, int length, int value) {
	int pivot = findPivot(rocks, 0, length - 1);
	if (pivot == -1) {
		return binarySearch(rocks, 0, length - 1, value);
	}
	if (rocks[pivot] == value)
		return pivot;
	if (rocks[0] <= value)
		return binarySearch(rocks, 0, pivot - 1, value);
	return binarySearch(rocks, pivot + 1, length - 1, value);
}

int	searchShifted(int *rocks, int length, int value) {
	int res = pivotedBinarySearch(rocks, length, value);
	if (res != -1 || res != 0) {
		int val = rocks[res];
		while (res > 0 && rocks[res] == val) {
			res--;
			val = rocks[res - 1];
		}
	}
	return res;
}