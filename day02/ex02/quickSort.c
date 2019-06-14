#include "header.h"
#include <stdio.h>
#include <stdlib.h>

static void swap(struct s_player **p1, struct s_player **p2) {
	struct s_player *tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static int partition(struct s_player **player, int low, int high) {
	struct s_player *pivot = player[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (player[j]->score > pivot->score) {
			i++;
			swap(&player[j], &player[i]);
		}
	}
	swap(&player[i + 1], &player[high]);
	return (i + 1);
}

static void quickSortHelp(struct s_player **players, int low, int high) {
	if (low < high) {
		int pi = partition(players, low, high);
		quickSortHelp(players, low, pi - 1);
		quickSortHelp(players, pi + 1, high);
	}
}

void quickSort(struct s_player **players) {
	int i ;
	for (i = 0; players[i]; i++)
		;
	quickSortHelp(players, 0, i - 1);
}