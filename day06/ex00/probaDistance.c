#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double probaDistance(int dist, int *locations, int n) {
	double count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(locations[i] - locations[j]) > dist)
				count++;
		}
	}
	return (count / (n * (n - 1)));
}