#ifndef matrix_h
#define matrix_h

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

struct matrix_t {
	unsigned m;
	unsigned n;
	void * coefficients;
};

void init_matrices(int sz, ...);
void clear_matrices(int sz, ...);
void free_matrices(int sz, ...);
size_t sizeof_matrix(struct matrix_t *);

#endif /* matrix */
