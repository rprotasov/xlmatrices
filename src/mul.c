#include "mul.h"

// void * dot_product(void *);
//
// struct helpers_t {
// 	struct args_t {
// 		struct matrix_t *a;
// 		struct matrix_t *b;
// 		int i;
// 		int j;
// 		int result;
// 	} args;
// 	pthread_t tid;
// 	void *status;
// };

int
xlmmul(xlmmatrix_t *a, xlmmatrix_t *b, xlmmatrix_t *c)
{
	return 1;
	// struct helpers_t *helpers, *local_helpers;
	// int
	// 	cannotBeMultiplied,
	// 	elements_sz,
	// 	*local_coefficients;
	// unsigned
	// 	local_m,
	// 	local_n,
	// 	i,
	// 	j;
	//
	// cannotBeMultiplied = a->n != b->m || a->m != b->n;
	//
	// if (cannotBeMultiplied) {
	// 	return 0;
	// }
	//
	// c->m = local_m = a->m;
	// c->n = local_n = b->n;
	//
	// elements_sz = local_m * local_n;
	//
	// helpers = local_helpers = (struct helpers_t *) malloc(sizeof(struct helpers_t) * elements_sz);
	//
	// i = j = 0;
	//
	// while (elements_sz--) {
	// 	local_helpers->args = (struct args_t) {
	// 		.a = a,
	// 		.b = b,
	// 		.i = i,
	// 		.j = j
	// 	};
	//
	// 	pthread_create(
	// 		&local_helpers->tid,
	// 		NULL,
	// 		dot_product,
	// 		(void *) (&local_helpers->args)
	// 	);
	//
	// 	local_helpers++;
	//
	// 	j++;
	//
	// 	if (j >= c->n) {
	// 		j = 0;
	// 		i++;
	// 	}
	// }
	//
	// elements_sz = local_m * local_n;
	//
 // 	c->coefficients = (void *) malloc(sizeof(int) * elements_sz);
	//
	// local_coefficients = (int *) c->coefficients;
	//
	// local_helpers = helpers;
	//
	// while (elements_sz--) {
	// 	pthread_join(
	// 		local_helpers->tid,
	// 		&local_helpers->status
	// 	);
	//
	// 	*(local_coefficients++) = local_helpers->args.result;
	//
	// 	local_helpers++;
	// }
	//
	// return 1;
}

// void *
// dot_product(void *args)
// {
// 	int _dot_product(struct matrix_t *, struct matrix_t *, unsigned, unsigned);
// 	struct args_t *casted_args;
//
// 	casted_args = (struct args_t *) args;
//
// 	casted_args->result = _dot_product(
// 		casted_args->a,
// 		casted_args->b,
// 		casted_args->i,
// 		casted_args->j
// 	);
//
// 	pthread_exit(args);
// }
//
// int
// _dot_product(struct matrix_t *a, struct matrix_t *b, unsigned i, unsigned j)
// {
// 	int
// 		*a_coefficients, *b_coefficients,
// 		width,
// 		product,
// 		counter,
// 		a_offset,b_offset,
// 		_a, _b;
//
// 	width = a->n;
//
// 	a_coefficients = (int *) a->coefficients;
// 	b_coefficients = (int *) b->coefficients;
//
// 	product = counter = 0;
//
// 	while (counter < width)
// 	{
// 		a_offset = (i * width) + counter;
// 		b_offset = (counter * width) + j;
//
// 		_a = *(a_coefficients + a_offset);
// 		_b = *(b_coefficients + b_offset);
//
// 		product += _a * _b;
// 		counter++;
// 	}
//
// 	return product;
// }
