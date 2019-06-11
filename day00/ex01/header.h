#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(void);
void printArt(struct s_art **art, int s, int e);

/*--------------------------------
  &  your own other function
  --------------------------------*/

void		swap(struct s_art **a, struct s_art **b);
void		quicksort(struct s_art **art, int low, int high);
int			partition(struct s_art **art, int low, int high);

#endif
