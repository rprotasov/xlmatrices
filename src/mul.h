#ifndef mul_h
#define mul_h

#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

int xlmmul(xlmmatrix_t *a, xlmmatrix_t *b, xlmmatrix_t *c);

#endif /* mul */
