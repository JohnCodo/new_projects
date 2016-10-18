// #include "FileUnderTest.c"
#include "PVM.h"

int TestedCode(int in)
{
	return in+1;
}

unsigned int up_down(unsigned int up, unsigned int down)
{
    static unsigned int DC=1;
    unsigned int counter=0;
    if((up==1)&&(down==0))
    {
     while(counter<Perioada)
     {counter++;}
     if(DC<100)
    {DC++;}
    }
    else if((up==0)&&(down==1))
    {
      while(counter<Perioada)
      {counter++;}
      if(DC>0){
       DC--;}
    }
return DC;
}


void Test1(void);
void Test1(void)
{
	TEST_COMMONS;
	TestDurationInMiliseconds = 500;

	// test specific inputs and outputs
	unsigned int Input_1=0, Input_2=0;
	unsigned int Output_1 =0;

	PERIODIC_EXECUTION_START

		// SET inputs
        AT_TEST_TIME(100)  			{Input_1 =1; Input_2 =0;}
		AT_TEST_TIME(200)   		{Input_1 =0; Input_2 =0;}
		AT_TEST_TIME(300)  			{Input_1 =0; Input_2 =1;}
		AT_TEST_TIME(400)  			{Input_1 =1; Input_2 =1;}


		// EXECUTE your code
		RUN_IN_TASK(TASK_10ms) 		Output_1 = up_down(Input_1,Input_2);
		RUN_IN_TASK(TASK_10ms)		printf("   Time=%d  Up=%d   Down=%d   PWM Output=%d \n", TimeInMiliseconds, Input_1,Input_2,Output_1 );


		// CHECK the result
		AT_TEST_TIME(30) 			CHECK_OUTPUT_EQUALS(Output_1, 1)


	PERIODIC_EXECUTION_END
}


void main (void);
void main (void)
{
	Test1();
}


