#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *rightShift(char *bin, int k) {
	for (int i = 0; i < k; i++) {
		for (size_t j = strlen(bin) - 1; j >= 1; j--) {
			bin[j] = bin[j - 1];
		}
	}
	return bin;
}

char *leftShift(char *bin, int k) {
	for (int i = 0; i < k; i++) {
		for (size_t j = 0; j < strlen(bin) - 1; j++) {
			char tmp = j == 0 ? bin[j] : '0';
			bin[j] = bin[j + 1];
			bin[j + 1] = tmp;
		}
	}
	return bin;
}

int		toInt(char *bits) {
	int	length = strlen(bits);
	int res;
	int		is_neg = bits[0] == '1' ? -1 : 1;
	res = is_neg == -1 ? -pow(2, length - 1) : 0;
	for (int i = 1 ; i < length; i++)
	{
		if (bits[i] == '1' && is_neg == 1) {
			res = res + pow(2, length - i - 1);
		} else if (is_neg == -1 && bits[i] == '1') {
			res = res + pow(2, length - i - 1);
		}

	}
	return res;
}