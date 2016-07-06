#include "matrix.h"
#include "mul.h"
#include "unity.h"
#include "unity_fixture.h"

#define M 4
#define N 2

TEST_GROUP(Multiply);

static struct matrix_t
a = (struct matrix_t) {
	.m = M,
	.n = N,
	.coefficients = (void *) & (int[M][N]) {
		{4, 5},
		{8, 7},
		{5, 4},
		{1, 7}
	}
},
b = (struct matrix_t) {
	.m = N,
	.n = M,
	.coefficients = (void *) & (int[N][M]) {
		{3, 8, 0, 7},
		{6, 7, 8, 3}
	}
}, c;

TEST_SETUP(Multiply)
{

}

TEST_TEAR_DOWN(Multiply)
{

}

TEST(Multiply, Mul_ReturnsCorrectResult)
{
	TEST_ASSERT_EQUAL(0, 0);
}
