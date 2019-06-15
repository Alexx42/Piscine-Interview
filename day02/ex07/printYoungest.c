#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a > b ? b : a)

static int divideConqueur(int *ages, int l, int r) {
	int ret = ages[l];
	for (int i = l + 1; i < r; i++) {
		ret = MIN(ret, ages[i]);
	}
	return ret;
}

void printYoungest(int *ages, int length) {
	int ret = ages[0];
	for (int i = 0; i < length; i++) {
		int tmp = length / 2;
		int tmp1 = divideConqueur(ages, 0, tmp - 1);
		int tmp2 = divideConqueur(ages, tmp + 1, length);
		ret = MIN(ret, MIN(tmp1, tmp2));
	}
	printf("%d\n", ret);
}