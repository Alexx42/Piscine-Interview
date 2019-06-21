#include "header.h"
#include <math.h>
#include <stdio.h>

int minPersons(int elements, int minPercentage) {
	double i = 1;
	double tmp = 1;
	for (; i <= elements; i++)
	{
		tmp = tmp * ((elements - i) / elements);
		if ((1 - tmp) * 100 >= minPercentage)
			break ;
	}
	return i + 1;
}