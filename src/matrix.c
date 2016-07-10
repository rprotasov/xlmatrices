#include "matrix.h"
#include "stdio.h"

#define MAX_MATRIXES 100

typedef struct {
	unsigned    m;
	unsigned    n;
	xlmTypes_t  coefficient_type;
	void *      coefficients;
	unsigned    id;
	char        dirty;
} xlmmhb_t;

void debug_matrix(xlmmhb_t *);

char fetch_block(xlmmhb_t *, xlmmatrix_t);
size_t _sizeof_matrix(xlmmhb_t *);

static xlmmhb_t matrices[MAX_MATRIXES];
static unsigned matrices_id_counter = 0;

char
xlminit(xlmmatrix_t *matrix, unsigned m, unsigned n, xlmTypes_t coefficient_type, void * coefficients)
{
	unsigned coefficients_sz;
	xlmmhb_t *block;

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

	block->coefficients = (void *) malloc(coefficients_sz);

	if (coefficients <= 0) {
		block->m = block->n = 0;
		block->coefficients = (void *) 0;
		return 0;
	}

	block->id = matrices_id_counter++;
	*matrix = block->id;

	if (coefficients && !xlmsetcoefficients(*matrix, coefficients)) {
		block->m = block->n = 0;
		free(block->coefficients);
		block->coefficients = 0;
		matrices_id_counter--;
		return 0;
	}

	return 1;
}

char
xlmsetcoefficients(xlmmatrix_t m, void *coefficients)
{
	char *mcp, *cp;
	size_t size;
	xlmmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	size = _sizeof_matrix(&block);

	if (size != 0) {
		mcp = (char *) block.coefficients;
		cp = (char *) coefficients;

		while (size--) {
			*(mcp++) = *(cp++);
		}
	}

	return 1;
}

char
fetch_block(xlmmhb_t *block, xlmmatrix_t m)
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
xlmsizeof_type(xlmTypes_t type)
{
	switch (type) {
		case xlmChar:
			return sizeof(char);
			break;
		case xlmInt:
			return sizeof(int);
			break;
		case xlmFloat:
			return sizeof(float);
			break;
		case xlmDouble:
			return sizeof(double);
			break;
		case xlmUnsigned:
			return sizeof(unsigned);
			break;
		case xlmLong:
			return sizeof(long);
			break;
		default:
			return 0;
			break;
	}
}

void
xlmclear(int sz, ...)
{
	va_list list;
	xlmmatrix_t m;
	xlmmhb_t block;

	va_start(list, sz);

	if (sz == 0) {
		return;
	}

	while (sz--)
	{
		m = va_arg(list, xlmmatrix_t);

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
xlmfree(int sz, ...)
{
	va_list list;
	xlmmatrix_t m;
	xlmmhb_t block;

	va_start(list, sz);

	if (sz == 0) {
		return;
	}

	while (sz--)
	{
		m = va_arg(list, xlmmatrix_t);

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
xlmgettype(xlmmatrix_t m, xlmTypes_t *type)
{
	return 1;
}

char
xlmrows_fill(xlmmatrix_t m, unsigned row, void *buf)
{
	xlmmhb_t block;
	size_t offset, col_length, data_size;
	char *src, *dest;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	data_size = xlmsizeof_type(block.coefficient_type);
	col_length = block.n * data_size;
	offset = row * col_length;

	src = (char *) block.coefficients;
	src += offset;

	dest = (char *) buf;

	if (!col_length) {
		return 1;
	}

	while (col_length--) {
		*(dest++) = *(src++);
	}

	return 1;
}

char
xlmcols_fill(xlmmatrix_t m, unsigned col, void *buf)
{
	xlmmhb_t block;
	size_t stride, row_length, data_size, offset, cnt;
	char *src, *dest;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	data_size = xlmsizeof_type(block.coefficient_type);
	row_length = block.m * data_size;

	if (!row_length) {
		return 1;
	}

	offset = col * data_size;
	stride = block.n * data_size;

	src = (char *) block.coefficients;
	src += offset;

	dest = (char *) buf;

	cnt = 0;

	while (row_length--) {
		*(dest++) = *(src + cnt);

		cnt++;

		if (!(cnt ^ data_size)) {
			src += stride;
			cnt = 0;
		}
	}

	return 1;
}

size_t
xlmsizeof_matrix(xlmmatrix_t m)
{
	xlmmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	return _sizeof_matrix(&block);
}

size_t
_sizeof_matrix(xlmmhb_t *m)
{
	return m->m * m->n * xlmsizeof_type(m->coefficient_type);
}

size_t
xlmsizeof_rows(xlmmatrix_t m)
{
	xlmmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	return block.m;
}

size_t
xlmsizeof_cols(xlmmatrix_t m)
{
	xlmmhb_t block;

	if (!fetch_block(&block, m)) {
		return 0;
	}

	return block.n;
}

void
debug_matrix(xlmmhb_t *m)
{
	int *local_coefficients, local_m, local_n;

	local_m = m->m;
	local_n = m->n;
	local_coefficients = (int *) m->coefficients;

	printf("\n");

	while (local_m--)
	{
		printf("[");
		while (local_n--)
		{
			printf("%3d", *(local_coefficients++));
			if (local_n != 0) {
				printf(", ");
			}
		}
		printf("]\n");
		local_n = m->n;
	}
}
