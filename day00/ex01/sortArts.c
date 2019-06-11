#include "header.h"
#include <string.h>
#include <stdio.h>
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))
void		sortArts(struct s_art **art) {
	int n = sizeof(*art[0]) * sizeof(art[0]);
	quicksort(art, 0, n);
}

void		quicksort(struct s_art **art, int low, int high) {

	if (low < high) {
		int pi = partition(art, low, high);

		quicksort(art, low, pi - 1);
		quicksort(art, pi + 1, high);
	}
}

int			partition(struct s_art **art, int low, int high) {
	struct s_art	*pivot;
	int				i;
	pivot = art[high];
	i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (strcmp(art[j]->name, pivot->name) < 0) {
			i++;
			swap(&art[i], &art[j]);
		}
	}
	swap(&art[i + 1], &art[high]);
	return (i + 1);
}

void		swap(struct s_art **a, struct s_art **b) {
	struct s_art *art;

	art = *a;
	*a = *b;
	*b = art;
}