#include "header.h"
#include <stdlib.h>


static void merge(struct s_player **players, int l, int h, int r) {
	int i, j, k;
	int n1 = h - l + 1;
	int n2 = r - h;

	struct s_player *L[n1];
	struct s_player *R[n2];
	for (i = 0; i < n1; i++) {
		L[i] = players[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = players[h + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i]->score >= R[j]->score) {
			players[k] = L[i];
			i++;
		} else {
			players[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		players[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		players[k] = R[j];
		j++;
		k++;
	}
}

static struct s_player **mergeSortHelp(struct s_player **players, int l, int r) {
	if (l < r)
	{
		int h = (l + r) / 2; // half
		mergeSortHelp(players, l, h);
		mergeSortHelp(players, h + 1, r);
		merge(players, l, h, r);
	}
	return players;
}

// Stable for timeStamp, compare time
struct s_player **mergeSort(struct s_player **players) {
	int i ;
	for (i = 0; players[i]; i++)
		;
	players = mergeSortHelp(players, 0, i - 1);
	return players;
}