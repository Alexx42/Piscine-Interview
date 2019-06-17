#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char *getAnd(char *a, char *b) {
	char	*res = malloc(sizeof(char) * 4);
	int i = 0;
	int idx = 0;
	if (a[0] == '~') {
		for (i = 1; a[i]; i++) {
			if (a[i] == '0')
				a[i - 1] = '1';
			else
				a[i - 1] = '0';
		}
		a[i - 1] = '\0';
	}
	if (b[0] == '~') {
		for (i = 1; b[i]; i++) {
			if (b[i] == '0')
				b[i - 1] = '1';
			else
				b[i - 1] = '0';
		}
		b[i - 1] = '\0';
	}
	printf("b = %s\n", b);
	for (int i = 0; a[i] && b[i]; i++) {
		if (a[i] == '0' || b[i] == '0') {
			res[idx++] = '0';
		} else {
			res[idx++] = '1';
		}
	}
	res[idx] = '\0';
	return res;
}


char *getOr(char *a, char *b) {
	char	*res = malloc(sizeof(char) * 4);
	int i = 0;
	int idx = 0;
	if (a[0] == '~') {
		for (i = 1; a[i]; i++) {
			if (a[i] == '0')
				a[i - 1] = '1';
			else
				a[i - 1] = '0';
		}
		a[i - 1] = '\0';
	}
	if (b[0] == '~') {
		for (i = 1; b[i]; i++) {
			if (b[i] == '0')
				b[i - 1] = '1';
			else
				b[i - 1] = '0';
		}
		b[i - 1] = '\0';
	}
	for (int i = 0; a[i] && b[i]; i++) {
		if (a[i] == '0' && b[i] == '0') {
			res[idx++] = '0';
		} else {
			res[idx++] = '1';
		}
	}
	res[idx] = '\0';
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