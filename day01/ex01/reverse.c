#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void printReverse(struct s_node *lst) {
	if (lst == NULL)
		return ;
	printReverse(lst->next);
	printf("%s ", lst->word);
}