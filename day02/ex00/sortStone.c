#include "header.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_item {
	int				val;
	struct s_item	*next;
}					t_item;

typedef struct 		s_chunk {
	t_item			**item;
}					t_chunk;

static void appendChunk(t_chunk *chunk, int val, int index) {
	t_item *newItem = malloc(sizeof(t_item));
	newItem->val = val;
	newItem->next = NULL;
	if (chunk->item[index] == NULL) {
		chunk->item[index] = newItem;
		return ;
	}
	struct s_item *tmp = chunk->item[index];
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newItem;
}

t_chunk		*initChunck(struct s_stone *stone) {
	t_chunk *chunk = malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	size_t index = 0;
	struct s_stone *tmp = stone;
	int	tmpVal = tmp->size;
	chunk->item = malloc(sizeof(t_item *));
	chunk->item[0] = NULL;
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->size != tmpVal) {
			index += 1;
			chunk->item = realloc(chunk->item, sizeof(t_item *) * (index + 2));
			chunk->item[index] = NULL;
		}
		appendChunk(chunk, tmp->size, index);
		tmpVal = tmp->size;
	}
	chunk->item[index + 1] = NULL;
	return chunk;
}

void sortStones(struct s_stone **stone) {
	t_chunk *chunk = initChunck(*stone);
	for (int i = 0; chunk && chunk->item[i]; i++) {
		for (int j = i; chunk && chunk->item[j]; j++) {
			if (chunk->item[i]->val > chunk->item[j]->val) {
				t_item *tmp = chunk->item[i];
				chunk->item[i] = chunk->item[j];
				chunk->item[j] = tmp;
			}
		}
	}
	
	free(*stone);
	*stone = NULL;
	for (int i = 0; chunk->item[i]; i++) {
		struct s_item *tmp = chunk->item[i];
		for (; tmp != NULL; tmp = tmp->next) {
			if (tmp->next == NULL && chunk->item[i + 1]) {
				tmp->next = chunk->item[i + 1];
				break ;
			}
		}		
	}
	*stone = (struct s_stone *)chunk->item[0];
}