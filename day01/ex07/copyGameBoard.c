#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_node *cloneGameBoard(struct s_node *node) {
	struct s_node *cpy = NULL;
	struct s_node *tmp;
	struct s_node *tmpCpy;
	for (tmp = node;tmp != NULL ; tmp = tmp->next->next) {
		struct s_node *n = malloc(sizeof(struct s_node));
		n->value = tmp->value;
		n->next = tmp->next;
		n->random = NULL;
		tmp->next = n;
	}
	for (tmp = node; tmp != NULL;) {
		if (tmp->next) {
			tmp->next->random = tmp->random ? tmp->random->next : tmp->random;
		}
		tmp = tmp->next ? tmp->next->next :  tmp->next;
	}
	cpy = node->next;
	tmpCpy = cpy;
	for (tmp = node; tmp != NULL && cpy != NULL; (tmp = tmp->next) && (cpy = cpy->next)){
		tmp->next = tmp->next ? tmp->next->next : tmp->next;
		cpy->next = cpy->next ? cpy->next->next : cpy->next;
	}
	return tmpCpy;
}