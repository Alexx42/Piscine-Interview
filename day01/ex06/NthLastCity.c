#include "header.h"
#include <stdlib.h>
#include <stdio.h>

char *NthLastCity(struct s_city *city, int n) {
	struct s_stack *stack = initStack();
	for (; city != NULL; city = city->next) {
		push(stack, city->name);
	}
	for (int i = 0; stack != NULL && i < n; i++) {
		pop(stack);
	}
	return stack->item->str;
}

struct s_stack *initStack(void)
{
	struct s_stack *n = malloc(sizeof(struct s_stack));
	if (n == NULL) {
		return NULL;
	}
	n->item = NULL;
	return n;
}

char	*pop(struct s_stack *stack) {
	char *content = 0;
	struct s_item *item = stack->item;
	if (stack->item)
	{
		content = item->str;
		stack->item = item->next;
		free(item);
		item = NULL;
	}
	return content;
}

void push(struct s_stack *stack, char *name) {
	struct s_item *newItem = malloc(sizeof(struct s_item));
	newItem->next = stack->item ? stack->item : NULL;
	newItem->str = name;
	stack->item = newItem;
}