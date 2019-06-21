#include "header.h"
#include <string.h>

static void swap(struct s_art **a1, struct s_art **a2) {
	struct s_art *tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

static void heapify(struct s_art **masterpiece, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && strcmp(masterpiece[l]->name, masterpiece[largest]->name) > 0)
		largest = l;
	if (r < n && strcmp(masterpiece[r]->name, masterpiece[largest]->name) > 0)
		largest = r;
	if (largest != i)
	{
		swap(&masterpiece[i], &masterpiece[largest]);
		heapify(masterpiece, n, largest);
	}
}

void heapSort(struct s_art **masterpiece, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(masterpiece, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&masterpiece[0], &masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}