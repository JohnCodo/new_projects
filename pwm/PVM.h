
#include "stdio.h"

#define TASK_10ms	10
#define Perioada 10

#define TEST_PASSED	1
#define TEST_FAILED	0

#define TEST_COMMONS 	unsigned int TestResult = TEST_PASSED;\
	unsigned int TimeInMiliseconds=0;\
	unsigned int TestDurationInMiliseconds=2000; \
	printf("-------------------------------------------------- StartOfTest %s \n", __func__);

#define AT_TEST_TIME(value) if (value == TimeInMiliseconds)

#define PERIODIC_EXECUTION_START while (TimeInMiliseconds<=TestDurationInMiliseconds) {

#define PERIODIC_EXECUTION_END 	TimeInMiliseconds++;	}	PrintTestResult(TestResult,__func__);

#define RUN_IN_TASK(Task) if (0 == TimeInMiliseconds % Task )

#define CHECK_OUTPUT_EQUALS(Output,Value) if ( Value != Output) \
			{ \
				printf("  At time %d: Output value is: %d, however %d expected \n",TimeInMiliseconds, Output, Value); \
				TestResult = TEST_FAILED; \
			}


void PrintTestResult(unsigned int TestResult, const char* TestName);
void PrintTestResult(unsigned int TestResult, const char* TestName)
{
	printf("End of test: %s                          Status: ",TestName);
	if (TEST_FAILED == TestResult )
	{
		printf("FAILED");
	}
	else
	{
		printf("PASSED");
	}
	printf("\n-------------------------------------------------- \n");
}
