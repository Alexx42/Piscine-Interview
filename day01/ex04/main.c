#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *q = queueInit();
	printf("is empty = %d\n", isEmpty(q));
	enqueue(q, "Hello");
	enqueue(q, "How");
	enqueue(q, "Are");
	enqueue(q, "You");
	enqueue(q, "?");
	printf("is empty = %d\n", isEmpty(q));
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", peek(q));
		printf("%s\n", dequeue(q));
	}
		printf("is empty = %d\n", isEmpty(q));
	return (0);
}



// Function used for the test
// Don't go further :)

