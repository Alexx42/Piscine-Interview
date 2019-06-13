#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *ft_strjoin(char *s1, char *s2) {
	char *res = NULL;
	if (!s2)
		return NULL;
	if (!s1)
	{
		res = malloc(sizeof(char) * strlen(s2));
		int i;
		for (i = 0; s2[i]; i++) {
			res[i] = s2[i];
		}
		res[i] = '\0';
	} else {
		res = malloc(sizeof(char) * (strlen(s1) + strlen(s2)));
		strcpy(res, s1);
		strcat(res, s2);
	}
	return res;
}

char *console(void) {
	char	*buff = NULL;
	char	*res = NULL;
	size_t	buffsize = 256;
	struct s_stack *s = initStack();
	buff = malloc(sizeof(char) * buffsize);

	while (1) {
		printf("> ");
		getline(&buff, &buffsize, stdin);
		if (buff[strlen(buff) - 1] == '\n') {
			buff[strlen(buff) - 1] = '\0';
		}
		if (!strcmp(buff, "SEND")) {
			break ;
		} else if (!strcmp(buff, "UNDO")) {
			res[pop(s)] = '\0';
		} else {
			res = ft_strjoin(res, buff);
		}
		printf("%s\n", res);
		push(s, strlen(res) - strlen(buff));
	}
	return res;
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

int	pop(struct s_stack *stack) {
	int content = 0;
	struct s_item *item = stack->item;
	if (stack->item)
	{
		content = item->idx;
		stack->item = item->next;
		free(item);
		item = NULL;
	}
	return content;
}

void push(struct s_stack *stack, int idx) {
	struct s_item *newItem = malloc(sizeof(struct s_item));
	newItem->next = stack->item ? stack->item : NULL;
	newItem->idx = idx;
	stack->item = newItem;
}