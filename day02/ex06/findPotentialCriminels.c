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

static int getSize(struct s_criminal **c) {
	int i;
	for (i = 0; c[i]; i++)
		;
	return i;
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

static int binarySearch(struct s_criminal **criminals, int l, int r, int key) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (criminals[mid]->description == key) {
			return mid;
		} else if (criminals[mid]->description < key) {
			return binarySearch(criminals,  mid + 1, r, key);
		} else {
			return binarySearch(criminals, l, mid - 1, key);
		}
	}
	return -1;
}

void sortCriminals(struct s_criminal **criminals) {
	int i = getSize(criminals);
	radixSort(criminals, i);
	return ;	
}

int getDescription(struct s_info *info) {
	int	*tmp = (int *)info;
	int res = 0;
	int length = 7;
	int i;
	for (i = 0; i < length &&  tmp[i] == 0; i++)
		;
	for (; i >= 0; i--)
		length--;
	for (i = 0; i < length; i++) {
		if (tmp[i]) {
			res = res * 10 + tmp[i];
		} else {
			res = res * 10;
		}
	}
	return (res);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {
	int i;
	int des = getDescription(info);
	int size = getSize(criminals);
	int mid = binarySearch(criminals, 0, size - 1, des);
	if (mid == -1)
		return NULL;
	int left = mid;
	int right = mid;
	for (; criminals[left] && criminals[left]->description == criminals[mid]->description; left--)
		;
	for (; criminals[right] && criminals[right]->description == criminals[mid]->description; right++)
		;
	struct s_criminal **res = malloc(sizeof(struct s_criminal) * (right - left - 1));
	for (i = 0; i < right - left - 1; i++) {
		res[i] = criminals[left + i + 1];
	}
	res[i] = NULL;
	return res;
}