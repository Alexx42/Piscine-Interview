#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void	bestPriceRec(double *prices, int pizzaSize, int total, double *max, double price)
{
	if (pizzaSize == total)
	{
		if (price > *max)
			*max = price;
		return ;
	}
	for (int i = 1; i <= total - pizzaSize; i++)
	{
		bestPriceRec(prices, pizzaSize + i, total, max, price + prices[i]);
	}
}

double bestPrice(int pizzaSize, double *prices) {
	double res = 0;

	bestPriceRec(prices, 0, pizzaSize, &res, 0);
	return res;
}
