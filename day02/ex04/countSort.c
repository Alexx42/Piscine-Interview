#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define RANGE 15

void countSort(unsigned char *utensils, int n) {
	char output[n];
	int count[RANGE + 1];
	int i ;
	memset(count, 0, sizeof(count));
	for (i = 0; utensils[i]; i++)
		++count[utensils[i]];
	for (i = 1; i <= RANGE; i++) {
		count[i] += count[i - 1];
	}
	for (i = 0; utensils[i]; i++) {
		output[count[utensils[i]] - 1] = utensils[i];
		--count[utensils[i]];
	}
	for (i = 0; utensils[i]; i++) {
		utensils[i] = output[i];
	}
}
