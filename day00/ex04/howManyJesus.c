#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int howManyJesus(char *bible, char *jesus) {
	int res = rabinKarpAlgo(bible, jesus);
	return res;
}

int rabinKarpAlgo(char *bible, char *jesus) {
	int M = strlen(jesus);
	int N = strlen(bible);
	int count = 0;
	int i;
	int j;
	int p = 0; // hash pattern
	int t = 0; // hash text
	int h = 1;

	for (i = 0; i < M - 1; i++) {
		h = (h * d) % q;
	}
	for (i = 0; i < M; i++) {
		p = (d * p + jesus[i]) % q;
		t = (d * t + bible[i]) % q;
	}
	for (i = 0; i <= N - M; i++) {
		if (p == t) {
			for (j = 0; j < M; j++) {
				if (bible[i + j] != jesus[j])
					break ;
			}
			if (j == M) {
				count++;
			}
		}
		if (i < N - M) {
			t = (d * (t - bible[i] * h) + bible[i + M]) % q;
			if (t < 0) {
				t += q;
			}
		}
	}
	return count;
}