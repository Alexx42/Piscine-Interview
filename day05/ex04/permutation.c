#include "header.h"
#include <string.h>
#include <stdio.h>

static void swap(char *s1, char *s2)
{
	char tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static void printPermutationRec(char *str, int l, int r)
{
	if (l == r)
	{
		printf("%s\n", str);
	}
	for (int i = l; i <= r; i++)
	{
		swap(str + i, str +l);
		printPermutationRec(str, l + 1, r);
		swap(str + i, str +l);
	}
}

void		printPermutations(char *str)
{
	if (!str)
		return ;
	printPermutationRec(str, 0, strlen(str) - 1);
}