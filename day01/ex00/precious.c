#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void appendList(struct s_node **node, char c) {
	struct s_node *newNode = malloc(sizeof(struct s_node));
	newNode->c = c;
	if (newNode == NULL)
		return ;
	if (!*node) {
		newNode->prev = newNode->next = newNode;
		*node = newNode;
		return ;
	}
	struct s_node *last = (*node)->prev;
	(*node)->prev = newNode;
	newNode->next = *node;
	newNode->prev = last;
	last->next = newNode;
}

static void printList(struct s_node *lst) {
	struct s_node *tmp = lst;
	while (tmp && tmp->next != lst) {
		printf("%c", tmp->c);
		tmp = tmp->next;
	}
	printf("%c\n", tmp->c);
}

char *precious(int *text, int size) {
	struct s_node *lst = NULL;
	int idx = 0;
	char *res = malloc(size + 1);
	for (size_t i = 0; i < strlen(CS); i++) {
		appendList(&lst, CS[i]);
	}
	struct s_node *tmp = lst;
	for (size_t i = 0; i < size; i++) {
		size_t j;
		if (text[i] < 0) {
			for (j = 0; j < -text[i]; j++) {
				tmp = tmp->prev;
			}
			res[idx++] = tmp->c;
		} else {
			for (j = 0; j < text[i] ; j++) {
				tmp = tmp->next;
			}
			res[idx++] = tmp->c;
		}
	}
	res[idx] = '\0';
	return (res);
}