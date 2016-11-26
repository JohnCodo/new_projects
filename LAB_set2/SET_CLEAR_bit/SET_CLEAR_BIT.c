
/*2. Scrieti un macro care seteaza un bit dintr-o variabila: setbit (pozitieBit, var)
Scrieti un macro care reseteaza un bit dintr-o variabila: clearbit (pozitieBit, var)*/


#include<stdio.h>


#define POZ_BIT_SET 24
#define POZ_BIT_CLEAR 0
#define NUMBER_TO_CONVERT 0xff

#define SET_BIT( POZ_BIT_SET,  NUMBER_TO_CONVERT)   (  NUMBER_TO_CONVERT | (1<<POZ_BIT_SET) )
#define CLEAR_BIT( POZ_BIT_CLEAR ,NUMBER_TO_CONVERT) ( NUMBER_TO_CONVERT & (~(1<<POZ_BIT_CLEAR )))


void print_Binary( unsigned long );
void functionToSET_BIT();
void functionToCLEAR_BIT();

int main()
{

    functionToSET_BIT();
    functionToCLEAR_BIT();

    return 0;
}


void functionToSET_BIT(){
    printf("NUMBER BEFORE SET  ");
    print_Binary(   NUMBER_TO_CONVERT  );
    printf("NUMBER AFTER SET  ");
    printf("Setting pozition  %d   on NUMBER = %d ", POZ_BIT_SET, NUMBER_TO_CONVERT );
    print_Binary( SET_BIT(POZ_BIT_SET,NUMBER_TO_CONVERT) );
    printf("*****************************************************************************************\n");
}

void functionToCLEAR_BIT(){
    printf("NUMBER BEFORE CLEAR  ");
    print_Binary(   NUMBER_TO_CONVERT  );
    printf("NUMBER AFTER CLEAR  ");
    printf("Setting pozition  %d   on NUMBER = %d ", POZ_BIT_CLEAR, NUMBER_TO_CONVERT );
    print_Binary( CLEAR_BIT(POZ_BIT_CLEAR,NUMBER_TO_CONVERT) );
    printf("*****************************************************************************************\n");
}

void print_Binary(unsigned long num){
char i=0, tablou[32],contor_0=0,contor_1=0;

printf("\nNumber in decimal is %lu \n",num);
printf("Number in HEXAdecimal is 0x%lx \n",num);
printf("Number in binary is ");
for(i=31;i>=0;i--){
    tablou[i]=(num>>i)&1;
    if( (tablou[i]) == 0 ){
        contor_0++;}
    else{
        contor_1++;}
    printf("%d ",tablou[i]);
}
printf("\n");
printf("The number has contor_0=%d   contor_1=%d \n",contor_0,contor_1);
}