#ifndef HEADER_H
# define HEADER_H

#define SIZE 5000000

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	int isFinal;
	struct s_node *random;
	struct s_node *next;
};

struct s_elem {
	struct s_node	*n;
	struct s_elem *next;
};

struct s_queue {
  struct s_elem *first;
	struct s_elem *last;
};

struct s_item {
  int           key; //here the key will be the name
  char			*value;
  struct s_item  *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	minimumMoves(struct s_node *begin); //you must return the minimum number of strokes to access to the final

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getBoardFromFile(char *file);

/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_queue *queueInit(void);

struct s_node *dequeue(struct s_queue *queue);

void enqueue(struct s_queue *queue, struct s_node *n);

struct s_node *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);

size_t hash(char *input); //return hash result

struct s_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(struct s_dict *dict, char *key, struct s_art *value); //add one element in the dictionnary, if FAIL return 0, otherwise 1
struct s_art *dictSearch(struct s_dict *dict, char *key); //find one element in the dictionnary, if not found, return NULL



#endif
