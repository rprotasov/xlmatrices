#include "matrix.h"
#include "mul.h"
#include "unity.h"
#include "unity_fixture.h"

#define M 4
#define N 2

TEST_GROUP(Multiply);

static int aCoefficients[M][N] = {
	{4, 5},
	{8, 7},
	{5, 4},
	{1, 7}
};
static int bCoefficients[N][M] = {
	{3, 8, 0, 7},
	{6, 7, 8, 3}
};

static struct matrix_t
a = (struct matrix_t) {
	.m = M,
	.n = N,
},
b = (struct matrix_t) {
	.m = N,
	.n = M,
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
