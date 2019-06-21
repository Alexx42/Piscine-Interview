#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double	probaRec(double firstDollarsBet, double dollarsWanted, int nbGame) {
	if (firstDollarsBet >= dollarsWanted)
		return (1.0);
	if (nbGame == 0)
		return (0);
	double tmp = (18.0 / 37.0) * probaRec(firstDollarsBet * 2, dollarsWanted, nbGame - 1);
	double tmp2 = (1.0 / 37.0) * probaRec(firstDollarsBet / 2, dollarsWanted, nbGame - 1);
	return (tmp + tmp2);
}


double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame) {
	return (probaRec(firstDollarsBet, dollarsWanted, nbGame));
}