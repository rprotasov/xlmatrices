#include "matrix.h"

void loop(void (*func)(struct matrix_t *), int sz, ...);

void
loop(void (*func)(struct matrix_t *), int sz, ...)
{
	va_list list;
	int i;
	struct matrix_t *matrix;

	va_start(list, sz);

	for (i = 0; i < sz; i++)
	{
		matrix = va_arg(list, struct matrix_t *);
		func(matrix);
	}

	va_end(list);
}

void
init_matrices(int sz, ...)
{
	va_list list;
	int i, matrix_sz;
	struct matrix_t *m;

	va_start(list, sz);

	for (i = 0; i < sz; i++)
	{
		m = va_arg(list, struct matrix_t *);
		matrix_sz = sizeof_matrix(m);
		m->coefficients = malloc(matrix_sz);
	}

	va_end(list);
}

void
clear_matrices(int sz, ...)
{
	va_list list;
	int i, matrix_sz;
	struct matrix_t *m;

	va_start(list, sz);

	for (i = 0; i < sz; i++)
	{
		m = va_arg(list, struct matrix_t *);
		matrix_sz = sizeof_matrix(m);
		memset(m->coefficients, 0, matrix_sz);
		m->m = 0;
		m->n = 0;
	}

	va_end(list);
}

void
free_matrices(int sz, ...)
{
	va_list list;
	int i;
	struct matrix_t *m;

	va_start(list, sz);

	for (i = 0; i < sz; i++)
	{
		m = va_arg(list, struct matrix_t *);
		free(m->coefficients);
		m->m = 0;
		m->n = 0;
	}

	va_end(list);
}

size_t
sizeof_matrix(struct matrix_t *m)
{
	return sizeof(int) * m->m * m->n;
}
