#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Matrix)
{
	RUN_TEST_CASE(Matrix, Rows_FillsBufferWithCorrectRowValues);
}
