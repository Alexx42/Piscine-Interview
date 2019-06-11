#include "header.h"
#include <stdio.h>
#include <string.h>

int		searchPrice(struct s_art **art, char *name) {
	for (int i = 0; art[i]; i++) {
		if (!strcmp(art[i]->name, name)) {
			return art[i]->price;
		}
	}
	return (-1);
}