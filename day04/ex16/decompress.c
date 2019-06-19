#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **pianoDecompress(struct s_bit *bit, int l) {
	int		**res = malloc(sizeof(int *) * bit->n);
	int i;
	int j;
	(void)bit;
	for (i = 0; i < bit->n; i++)
		res[i] = malloc(sizeof(int) * l);
	for (i = 0; i < bit->n; i++) {
		int count = 0;
		for (j = 0; count < bit->arr[i]; j++) {
			res[i][j] = 0;
			count += pow(2, j);
		}
		res[i][j - 1] = 1;
		for (; j < l; j++) {
			res[i][j] = 0;
		}
	}
	res[i] = NULL;
	return res;
}