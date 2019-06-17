#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char *getXor(char *a, char *b) {
	char		*res = malloc(strlen(a) + strlen(b));
	int i;
	for (i = 0; a[i] && b[i]; i++) {
		if (a[i] == '1' && b[i] == '1')
			res[i] = '0';
		else if (a[i] == '1' || b[i] == '1')
			res[i] = '1';
		else
			res[i] = '0';
	}
	res[i] = '\0';
	return res;
}

int		toInt(char *bits) {
	int	length = strlen(bits);
	int res = 0;

	for (int i = 0; i < length; i++)
	{
		if (bits[i] == '1') {
			res = res + pow(2, length - i - 1);
		}
	}
	return res;
}