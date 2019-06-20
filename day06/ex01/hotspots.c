#include <stdio.h>
#include <stdlib.h>
#include "header.h"

static uint8_t is_overlap(struct s_hotspot *a, struct s_hotspot *b)
{
	return a->pos + a->radius > b->pos - b->radius;
}

int selectHotspots(struct s_hotspot **hotspots) {
	int count = 0;
	int i = 0;
	for (i = 0; hotspots[i + 1]; i++)
	{
		if (is_overlap(hotspots[i], hotspots[i + 1]))
		{
			count++;
			if (hotspots[i + 1] && (hotspots[i + 1]->radius > hotspots[i]->radius))
				i++;
		}
	}
	return 1 + i  - count;
}