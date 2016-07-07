#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Matrix)
{
	RUN_TEST_CASE(Matrix, Cols_FillsBufferWithCorrectColumnValues);
	RUN_TEST_CASE(Matrix, Rows_FillsBufferWithCorrectRowValues);
	RUN_TEST_CASE(Matrix, Constructor_SpecifyTypeOfCoefficients);
	RUN_TEST_CASE(Matrix, Constructor_InitStruct);
}
