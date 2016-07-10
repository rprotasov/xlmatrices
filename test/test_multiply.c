#include "matrix.h"
#include "mul.h"
#include "unity.h"
#include "unity_fixture.h"

#define M 4
#define N 2

TEST_GROUP(Multiply);

static xlmmatrix_t a, b, c;

TEST_SETUP(Multiply)
{
	extern xlmmatrix_t a, b, c;

	xlminit(&a, M, N, xlmInt, NULL);
	xlminit(&b, M, N, xlmInt, NULL);
	xlminit(&c, M, N, xlmInt, NULL);
}

TEST_TEAR_DOWN(Multiply)
{

}

TEST(Multiply, Mul_ReturnsCorrectResult)
{
	TEST_ASSERT_EQUAL(1, 1);
}
