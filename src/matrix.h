#ifndef matrix_h
#define matrix_h

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef enum {
	mChar,
	mInt,
	mFloat,
	mDouble,
	mUnsigned,
	mLong
} mTypes_t;

typedef unsigned mmatrix_t;

char minit(mmatrix_t *, unsigned, unsigned, mTypes_t);
void mfree(int sz, ...);
void mclear(int sz, ...);

char mgettype(mmatrix_t, mTypes_t *);

char msetcoefficients(mmatrix_t, void *);

size_t msizeof_rows(mmatrix_t);
size_t msizeof_cols(mmatrix_t);
size_t msizeof_type(mTypes_t);
size_t msizeof_matrix(mmatrix_t);

char mrows_fill(mmatrix_t, unsigned, void *);
char mcols_fill(mmatrix_t, unsigned, void *);

#endif /* matrix */
