#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static char *reverseArray(char *arr) {
	int len = strlen(arr);

	for (int i = 0; i < len / 2; i++) {
		char tmp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = tmp;
	}
	return arr;
}

char	*getSum(char *a, char *b) {
	char *result = malloc(sizeof(char) * strlen(a) + strlen(b));
	int s = 0;
	int i = strlen(a) - 1;
	int j = strlen(b) - 1;
	int idx = 0;
	while (i >= 0 || j >= 0 || s == 1)
	{
		s += ((i >= 0) ? a[i] - '0' : 0);
		s += ((j >= 0) ? b[j] - '0' : 0);
		result[idx++] = (char)(s % 2 + '0');
		s /= 2;
		i--;
		j--;
	}
	result[idx] = '\0';
	reverseArray(result);
	return result;
}

int		toInt(char *bits) {
	int	length = strlen(bits);
	int res = 0;

	for (int i = 0; i < length; i++)
	{
		if (bits[i] == '1') {
			res =  res + pow(2, length - i - 1);
		}
	}
	return res;
}