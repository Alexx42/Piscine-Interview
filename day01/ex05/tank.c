#include "header.h"
#include <stdlib.h>
#include <stdio.h>

static struct s_stack *initStack(int energy) {
	struct s_stack *s = malloc(sizeof(struct s_stack));
	if (s == NULL)
		return NULL;
	s->elem = malloc(sizeof(struct s_elem));
	s->sum = energy;
	s->elem->next = NULL;
	s->elem->energy = energy;
	return s;
}

void printStack(struct s_tank *tank) {
	for (int i = 0; i < tank->n + 1; i++) {
		struct s_elem *tmp = tank->stacks[i]->elem;
		i == 0 ? printf("-------normal-------\n") : printf("-------nitro[%d]-------\n", i);
		while (tmp != NULL) {
			printf("%d-", tmp->energy);
			tmp = tmp->next;
		}
		printf("\nsum = %d\n", tank->stacks[i]->sum);
		printf("\n");
	}
}

struct s_tank *initTank(void) {
	struct s_tank *t = malloc(sizeof(struct s_tank));
	if (t == NULL)
		return NULL;
	t->n = 0;
	t->stacks = malloc(sizeof(struct s_stack));
	t->stacks[0] = NULL;
	return t;
}

void tankPush(struct s_tank *tank, int energy) {
	struct s_elem *tmp = NULL;
	if (tank->stacks[tank->n] == NULL) {
		// If no stacks
		tank->stacks[tank->n] = initStack(energy);
		return ;
	}
	if (tank->stacks[tank->n]->sum + energy > 1000) {
		// Create another stack -- full
		tank->n++;
		tank->stacks[tank->n] = initStack(energy);
	} else {
		// Append to the current one
		struct s_elem *newElem = malloc(sizeof(struct s_elem));
		tmp = tank->stacks[tank->n]->elem;
		newElem->energy = energy;
		newElem->next = tmp;
		tank->stacks[tank->n]->sum += energy;
		tank->stacks[tank->n]->elem = newElem;
	}
}

int tankPop(struct s_tank *tank) {
	int content = 0;
	struct s_elem *elem = tank->stacks[tank->n] ? tank->stacks[tank->n]->elem : NULL;
	if (elem != NULL) {
		content = elem->energy;
		tank->stacks[tank->n]->elem = elem->next;
		tank->stacks[tank->n]->sum -= content;
		if (tank->stacks[tank->n]->sum == 0) {
			free(tank->stacks[tank->n]);
			tank->stacks[tank->n] = NULL;
			tank->n--;
		}
		free(elem);
	}
	return content;
}