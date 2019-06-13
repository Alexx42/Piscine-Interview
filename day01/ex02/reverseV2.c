#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void printReverseV2(struct s_node *lst) {
	struct s_stack *s = stackInit();
	while (lst) {
		push(s, lst->word);
		lst = lst->next;
	}
	while (s->item != NULL)
	{
		printf("%s", pop(s));
		if (s->item != NULL) {
			putc(' ', stdout);
		}
	}
}

struct s_stack *stackInit(void)
{
	struct s_stack *n = malloc(sizeof(struct s_stack));
	if (n == NULL) {
		return NULL;
	}
	n->item = NULL;
	return n;
}

void *pop(struct s_stack *stack) {
	void *content = NULL;
	struct s_item *item = stack->item;
	if (stack->item)
	{
		content = item->word;
		stack->item = item->next;
		free(item);
		item = NULL;
	}
	return content;
}

void push(struct s_stack *stack, char *word) {
	struct s_item *newItem = malloc(sizeof(struct s_item));
	newItem->next = stack->item ? stack->item : NULL;
	newItem->word = word;
	stack->item = newItem;
}