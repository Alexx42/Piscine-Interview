#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int factorial(int n)
{
	if (n == 1)
		return (1);
	return n * (factorial(n - 1));
}

static void swap(char *s1, char *s2)
{
	char tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static void printPermutationRec(char *str, int l, int r, struct s_dict *dict)
{
	if (l == r)
	{
		if (dictSearch(dict, str) == -1)
		{
			dictInsert(dict, str, 0);
			printf("%s\n", str);
		}
	}
	for (int i = l; i <= r; i++)
	{
		swap(str + i, str +l);
		printPermutationRec(str, l + 1, r, dict);
		swap(str + i, str +l);
	}
}

void printUniquePermutations(char *str)
{
	struct s_dict		*dict = dictInit(factorial(strlen(str)));
	if (!str)
		return ;
	printPermutationRec(str, 0, strlen(str) - 1, dict);
}