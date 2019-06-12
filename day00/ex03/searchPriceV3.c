#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchPrice(struct s_dict *dict, char *name) {
	struct s_art *val = dictSearch(dict, name);
	return val ? val->price : -1;
}

size_t	hash(char *input) {
	size_t hash = 5381;
	for (size_t i = 0; i < strlen(input); i++) {
		hash = ((hash << 5) + hash) + input[i];
	}
	return hash;
}

struct s_dict *dictInit(int capacity) {
	struct s_dict *d = (struct s_dict *)malloc(sizeof(struct s_dict));
	if (d == NULL)
		return NULL;
	
	d->items = (struct s_item **)malloc(sizeof(struct s_item *) * (capacity));
	for (int i = 0; i < capacity; i++) {
		d->items[i] = NULL;
	}
	d->capacity = capacity;
	return d;
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
	struct s_item *newItem = (struct s_item *)malloc(sizeof(struct s_item));
	size_t pos = hash(key);
	struct s_item *item = dict->items[pos % dict->capacity];
	struct s_item *tmp = item;
	while (tmp) {
		if (!strcmp(tmp->key, key)) {
			tmp->value = value;
			return 0;
		}
		tmp = tmp->next;
	}
	newItem->key = key;
	newItem->value = value;
	newItem->next = item;
	dict->items[pos % dict->capacity] = newItem;
	return (0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key) {
	size_t	pos = hash(key);

	struct s_item *item = dict->items[pos % dict->capacity];
	struct s_item *tmp = item;
	while (tmp) {
		if (!strcmp(tmp->key, key)) {
			return tmp->value;
		}
		tmp = tmp->next;
	}
	return NULL;
}