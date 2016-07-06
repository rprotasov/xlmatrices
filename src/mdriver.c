#include <stdio.h>
#include "matrix.h"
#include "mul.h"

#define M 4
#define N 2

void print_matrix(struct matrix_t *);

int
main(int argc, char **argv)
{
	struct matrix_t *a, *b, c;
	int result;
	int aCoefficients[M][N] = {
		{4, 5},
		{8, 7},
		{5, 4},
		{1, 7}
		// {1, -3},
		// {-1, 4}
	};
	int bCoefficients[N][M] = {
		{3, 8, 0, 7},
		{6, 7, 8, 3}
		// {4, 3},
		// {1, 1}
	};

	a = & (struct matrix_t) {
		.m = M,
		.n = N,
		.coefficients = (void *) aCoefficients
	};

	b = & (struct matrix_t) {
		.m = N,
		.n = M,
		.coefficients = (void *) bCoefficients
	};

	result = mul(a, b, &c);

	if (!result) {
		printf("Unable to multiply matrices!\n");
		return -1;
	}

	print_matrix(&c);

	free_matrices(1, &c);
}

void
print_matrix(struct matrix_t *m)
{
	int *local_coefficients, local_m, local_n;

	local_m = m->m;
	local_n = m->n;
	local_coefficients = (int *) m->coefficients;

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
