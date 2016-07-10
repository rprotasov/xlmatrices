#ifndef matrix_h
#define matrix_h

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef enum {
	xlmChar,
	xlmInt,
	xlmFloat,
	xlmDouble,
	xlmUnsigned,
	xlmLong
} xlmTypes_t;

typedef unsigned xlmmatrix_t;

char xlminit(xlmmatrix_t *, unsigned m, unsigned n, xlmTypes_t, void *);
void xlmfree(int sz, ...);
void xlmclear(int sz, ...);

char xlmgettype(xlmmatrix_t, xlmTypes_t *);

char xlmsetcoefficients(xlmmatrix_t, void *);

size_t xlmsizeof_rows(xlmmatrix_t);
size_t xlmsizeof_cols(xlmmatrix_t);
size_t xlmsizeof_type(xlmTypes_t);
size_t xlmsizeof_matrix(xlmmatrix_t);

char xlmrows_fill(xlmmatrix_t, unsigned, void *);
char xlmcols_fill(xlmmatrix_t, unsigned, void *);

#endif /* matrix */
