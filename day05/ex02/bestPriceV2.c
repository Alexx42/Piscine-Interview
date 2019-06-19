#include "header.h"
#include <string.h>

void optimizedBestPriceRec(double *prices, int size, int total, double price, double *res)
{
    for (int i = 0; i <= total; i++)
    {
        if (i == size)
        {
            if (res[i] < price)
                res[i] = price;
            break ;
        }
    }
    if (total == size)
        return ;
    if (res[size] == price)
    {
        for (int i = 1; i <= total - size; i++)
        {
            optimizedBestPriceRec(prices, size + i, total, price + prices[i], res);
        }
    }
}

double optimizedBestPrice(int pizzaSize, double *prices) {
    double res[pizzaSize + 1];

    memset(res, 0, (pizzaSize + 1) * sizeof(double));
    optimizedBestPriceRec(prices, 0, pizzaSize, 0, res);
    return (res[pizzaSize]);
}