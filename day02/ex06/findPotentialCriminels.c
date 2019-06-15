#include "header.h"
#include <stdio.h>
#include <stdlib.h>

static int getMax(struct s_criminal **criminals) {
	int i;
	int max = criminals[0]->description;
	for (i = 1; criminals[i]; i++) {
		if (criminals[i]->description > max) {
			max = criminals[i]->description;
		}
	}
	return max;
}

static void countSort(struct s_criminal **criminals, int n, int p) {
	struct s_criminal *output[n];
	int i;
	int count[10] = {0};
	for (i = 0; i < n; i++) {
		count[(criminals[i]->description / p) % 10]++;
	}
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	 for (i = n - 1; i >= 0; i--) 
    {
        output[count[(criminals[i]->description / p) % 10 ] - 1] = criminals[i]; 
        count[ (criminals[i]->description / p) % 10 ]--; 
    }
	for (i = 0; i < n; i++) {
		criminals[i] = output[i];
	}
}

static void radixSort(struct s_criminal **criminals, int n) {
	int m = getMax(criminals);
	
	for (int p = 1; m / p > 0; p *= 10) {
		countSort(criminals, n, p);
	}
}

void sortCriminals(struct s_criminal **criminals) {
	int i;
	for (i = 0; criminals[i]; i++)
		;
	radixSort(criminals, i);
	return ;	
}

int getDescription(struct s_info *info) {
	(void)info;
	int res = 0;
	if (info->gender) {
		res = (res + 1);
	}
	return (res);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {
	(void)criminals;
	int val = getDescription(info);
	printf("val = %d\n", val);
	return NULL;
}