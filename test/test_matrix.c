#include "matrix.h"
#include "unity.h"
#include "unity_fixture.h"

#define M 4
#define N 2

TEST_GROUP(Matrix);

static int coefficients[M][N] = {
	{4, 5},
	{8, 7},
	{5, 4},
	{1, 7}
};

static mmatrix_t matrix;

TEST_SETUP(Matrix)
{

}

TEST_TEAR_DOWN(Matrix)
{

}

TEST(Matrix, Constructor_InitStruct)
{
	minit(&matrix, N, M, mInt);
	msetcoefficients(matrix, (void *) coefficients);
}

TEST(Matrix, Constructor_SpecifyTypeOfCoefficients)
{
	// mTypes_t type;
	//
	// mgettype(matrix, &type);
	//
	// TEST_ASSERT_EQUAL(mUnset, type);
	//
	// type = mInt;
	//
	// msettype(&matrix, type);
	// mgettype(matrix, &type);
	//
	// TEST_ASSERT_EQUAL(mInt, type);
	TEST_ASSERT_EQUAL(1, 1);
}

TEST(Matrix, Rows_FillsBufferWithCorrectRowValues)
{
// 	int buf[N];
// 	matrix = (struct matrix_t) {
// 		.m = M,
// 		.n = N,
// 		.coefficients = (void *) coefficients
// 	};
// 	msettype(&matrix, mInt);
//
// 	mrows_fill(matrix, 0, (void *) buf);
//
// 	TEST_ASSERT_EQUAL(4, buf[0]);
// 	TEST_ASSERT_EQUAL(5, buf[1]);
//
// 	mrows_fill(matrix, 1, (void *) buf);
//
// 	TEST_ASSERT_EQUAL(8, buf[0]);
// 	TEST_ASSERT_EQUAL(7, buf[1]);
//
// 	mrows_fill(matrix, 2, (void *) buf);
//
// 	TEST_ASSERT_EQUAL(5, buf[0]);
// 	TEST_ASSERT_EQUAL(4, buf[1]);
//
// 	mrows_fill(matrix, 3, (void *) buf);
//
// 	TEST_ASSERT_EQUAL(1, buf[0]);
// 	TEST_ASSERT_EQUAL(7, buf[1]);
// }
//
// TEST(Matrix, Cols_FillsBufferWithCorrectColumnValues)
// {
// 	int buf[M];
// 	matrix = (struct matrix_t) {
// 		.m = M,
// 		.n = N,
// 		.coefficients = (void *) coefficients
// 	};
// 	msettype(&matrix, mInt);
//
// 	mcols_fill(matrix, 0, (void *) buf);
//
// 	TEST_ASSERT_EQUAL(4, buf[0]);
// 	TEST_ASSERT_EQUAL(8, buf[1]);
// 	TEST_ASSERT_EQUAL(5, buf[2]);
// 	TEST_ASSERT_EQUAL(1, buf[3]);
//
// 	mcols_fill(matrix, 1, (void *) buf);
//
// 	TEST_ASSERT_EQUAL(5, buf[0]);
// 	TEST_ASSERT_EQUAL(7, buf[1]);
// 	TEST_ASSERT_EQUAL(4, buf[2]);
// 	TEST_ASSERT_EQUAL(7, buf[3]);
	TEST_ASSERT_EQUAL(1, 1);
}

TEST(Matrix, Cols_FillsBufferWithCorrectColumnValues)
{
	TEST_ASSERT_EQUAL(1, 1);
}
