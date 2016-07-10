#include "matrix.h"
#include "unity.h"
#include "unity_fixture.h"

#define M 4
#define N 2

TEST_GROUP(Matrix);

static xlmmatrix_t matrix;

TEST_SETUP(Matrix)
{

}

TEST_TEAR_DOWN(Matrix)
{

}

TEST(Matrix, Constructor_InitStruct)
{
	int coefficients[M][N] = {
		{1, 2},
		{2, 3},
		{4, 5},
		{6, 7}
	};

	xlminit(&matrix, M, N, xlmInt, (void *) coefficients);
}

TEST(Matrix, Rows_FillsBufferWithCorrectRowValues)
{
	int buf[M], i;
	int coefficients[N][M] = {
		{0, 1, 2, 3},
		{0, 1, 2, 3}
	};

	xlminit(&matrix, N, M, xlmInt, (void *) coefficients);

	xlmrows_fill(matrix, 0, (void *) buf);

	for (i = 0; i < M; i++) {
		TEST_ASSERT_EQUAL(i, buf[i]);
	}

	buf[0] = buf[1] = buf[2] = buf[3] = 0;

	xlmrows_fill(matrix, 0, (void *) buf);

	for (i = 0; i < M; i++) {
		TEST_ASSERT_EQUAL(i, buf[i]);
	}
}

TEST(Matrix, Cols_FillsBufferWithCorrectColumnValues)
{
	int buf[M], i;
	int coefficients[M][N] = {
		{0, 0},
		{1, 1},
		{2, 2},
		{3, 3}
	};

	xlminit(&matrix, M, N, xlmInt, (void *) coefficients);

	xlmcols_fill(matrix, 0, (void *) buf);

	for (i = 0; i < M; i++) {
		TEST_ASSERT_EQUAL(i, buf[i]);
	}

	buf[0] = buf[1] = buf[2] = buf[3] = 0;

	xlmcols_fill(matrix, 0, (void *) buf);

	for (i = 0; i < M; i++) {
		TEST_ASSERT_EQUAL(i, buf[i]);
	}
}
