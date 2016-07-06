#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Multiply)
{
	RUN_TEST_CASE(Multiply, Mul_ReturnsCorrectResult);
}
