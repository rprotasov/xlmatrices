#include "matrix.h"
#include "unity.h"
#include "unity_fixture.h"

#define M 4
#define N 2

TEST_GROUP(Matrix);

static struct matrix_t matrix = (struct matrix_t) {
	.m = M,
	.n = N,
	.coefficients = (void *) & (int[M][N]) {
		{4, 5},
		{8, 7},
		{5, 4},
		{1, 7}
	}
};

TEST_SETUP(Matrix)
{

}

TEST_TEAR_DOWN(Matrix)
{

}

TEST(Matrix, Rows_FillsBufferWithCorrectRowValues)
{
	TEST_ASSERT_EQUAL(0, 0);
}
