#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_queue *queueInit(void) {
	struct s_queue *q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return q;
}

char *dequeue(struct s_queue *queue) {
	char *content = NULL;
	struct s_node *n = queue->first;
	if (queue->first) {
		content = n->message;
		queue->first = n->next;
		queue->last = queue->first ? queue->last : NULL;
		free(n);
	}
	return content;
}

void enqueue(struct s_queue *queue, char *message) {
	struct s_node *n = malloc(sizeof(struct s_node));
	n->message = message;
	n->next = queue->last;
	if (queue->first == NULL) {
		queue->first = queue->last = n;
		return ;
	}
	queue->last->next = n;
	queue->last = n;
}

char *peek(struct s_queue *queue) {
	return (queue->first ? queue->first->message : NULL);
}

int isEmpty(struct s_queue *queue) {
	return (!queue->first);
}