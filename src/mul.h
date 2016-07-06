#ifndef mul_h
#define mul_h

#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

int mul(struct matrix_t *a, struct matrix_t *b, struct matrix_t *c);

#endif /* mul */
