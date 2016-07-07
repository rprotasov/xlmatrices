#include "matrix.h"

#define MAX_MATRIXES 100

typedef struct {
	unsigned m;
	unsigned n;
	mTypes_t coefficient_type;
	void * coefficients;
	unsigned id;
	char dirty;
} mmhb_t;

char fetch_block(mmhb_t *, mmatrix_t);
size_t _sizeof_matrix(mmhb_t *);

static mmhb_t matrices[MAX_MATRIXES];
static unsigned matrices_id_counter = 0;

char
minit(mmatrix_t *matrix, unsigned m, unsigned n, mTypes_t coefficient_type)
{
	void *coefficients;
	unsigned coefficients_sz;
	mmhb_t *block;

	if (matrices_id_counter >= MAX_MATRIXES) {
		/**
		 * TODO possibly remove matrices
		 * which are good to go
		 */
		return 0;
	}

	block = matrices + matrices_id_counter;

	block->m = m;
	block->n = n;
	block->coefficient_type = coefficient_type;
	block->dirty = 0;

	coefficients_sz = _sizeof_matrix(block);

	coefficients = (void *) malloc(coefficients_sz);

	if (coefficients <= 0) {
		block->m = block->n = 0;
		return 0;
	}

	block->coefficients = coefficients;
	block->id = matrices_id_counter;

	*matrix = block->id;

	matrices_id_counter++;

	return 1;
}

char
fetch_block(mmhb_t *block, mmatrix_t m)
{
	unsigned matrix_id;
	char belowBounds, aboveBounds;

	matrix_id = (unsigned) m;

	belowBounds = 0 > (int) matrix_id;
	aboveBounds = matrix_id >= matrices_id_counter;

	if (belowBounds || aboveBounds) {
		return 0;
	}

	*block = *(matrices + matrix_id);

	return 1;
}

size_t
msizeof_type(mTypes_t type)
{
	switch (type) {
		case mChar:
			return sizeof(char);
			break;
		case mInt:
			return sizeof(int);
			break;
		case mFloat:
			return sizeof(float);
			break;
		case mDouble:
			return sizeof(double);
			break;
		case mUnsigned:
			return sizeof(unsigned);
			break;
		case mLong:
			return sizeof(long);
			break;
		default:
			return 0;
			break;
	}
}

void
mclear(int sz, ...)
{
	va_list list;
	mmatrix_t m;
	mmhb_t block;

	va_start(list, sz);

	if (sz == 0) {
		return;
	}

	while (sz--)
	{
		m = va_arg(list, mmatrix_t);

		if (!fetch_block(&block, m)) {
			continue;
		}

		/**
		 * TODO refresh additional memory
		 */

		block.m = 0;
		block.n = 0;
	}

	va_end(list);
}

void
mfree(int sz, ...)
{
	va_list list;
	mmatrix_t m;
	mmhb_t block;

	va_start(list, sz);

	if (sz == 0) {
		return;
	}

	while (sz--)
	{
		m = va_arg(list, mmatrix_t);

		if (!fetch_block(&block, m)) {
			continue;
		}

		/**
		 * TODO clean up additional memory
		 */

		block.m = 0;
		block.n = 0;
	}

	va_end(list);
}

char
mgettype(mmatrix_t m, mTypes_t *type)
{
	return 1;
}

char
mrows_fill(mmatrix_t m, unsigned row, void *buf)
{
	return 1;
}

char
mcols_fill(mmatrix_t m, unsigned col, void *buf)
{
	return 1;
}

size_t
msizeof_matrix(mmatrix_t m)
{
	mmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	return _sizeof_matrix(&block);
}

size_t
_sizeof_matrix(mmhb_t *m)
{
	return m->m * m->n * msizeof_type(m->coefficient_type);
}

size_t
msizeof_rows(mmatrix_t m)
{
	mmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	return block.m;
}

size_t
msizeof_cols(mmatrix_t m)
{
	mmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	return block.n;
}

char
msetcoefficients(mmatrix_t m, void *coefficients)
{
	return 1;
}
