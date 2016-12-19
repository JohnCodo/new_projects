
#define CHOISE_TABLE 2 // select table that you want

#if   (CHOISE_TABLE==1)
#define TABLE_DIM	7
#define VALUE_MAX_TABLE 200
unsigned long	tableValues[TABLE_DIM] = {5,20,50,90,100,130,139};
#elif  (CHOISE_TABLE==2)
#define TABLE_DIM	4
unsigned long	tableValues[TABLE_DIM] = {6,15,20,25};
#define VALUE_MAX_TABLE 30
#elif  (CHOISE_TABLE==3)
#define TABLE_DIM	2
unsigned long	tableValues[TABLE_DIM] = {1000,2000};
#define VALUE_MAX_TABLE 3000
#else

    #error

#endif