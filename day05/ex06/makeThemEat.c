#include "header.h"
#include <stdio.h>
#include <stdlib.h>
int isPossibleRec(struct s_people **people, int idx, int nbTable, int totalTime, int *arr)
{
	if (!people[idx])
		return (1);
	for (int i = 0; i < nbTable; i++)
	{
		if (arr[i] + people[idx]->time <= totalTime)
		{
			arr[i] += people[idx]->time;
			if (isPossibleRec(people, idx + 1, nbTable, totalTime, arr))
				return (1);
			arr[i] -= people[idx]->time;
		}
	}
	return (0);
}

int isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int		*arr = calloc(nbTable, sizeof(int));
	return (isPossibleRec(people, 0, nbTable, totalTime, arr));
}