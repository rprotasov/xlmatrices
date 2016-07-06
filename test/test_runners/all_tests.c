#include "unity_fixture.h"

static void
RunAllTests(void)
{
	RUN_TEST_GROUP(Matrix);
	RUN_TEST_GROUP(Multiply);
}

int
main(int argc, const char **argv)
{
	return UnityMain(argc, argv, RunAllTests);
}
