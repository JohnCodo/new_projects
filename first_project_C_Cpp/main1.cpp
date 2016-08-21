#include <iostream>
#include <implement.h>

using namespace std;

void convertDecToBin(int value)
{
	int i,rez,c=0;
	const int const_value=8;

	cout<<"Value is="<<value<<endl<<"and in binary is = ";
	for(i=(sizeof(value)*const_value)-1 ; i>=0 ; i--)
	 { 
		 rez=value & (1<<i);
		 if(rez)
		 	cout<<"1";
		 else
		 	cout<<"0";
	} 
	 cout << endl;
	 cout<<"number of sizeof is:"<<sizeof(value)*const_value<<endl;
	 cout<<"Rezult for sizeof is: "<<sizeof(int)<<endl;
}
int convertBinToDec(int num)
{   
    int binary_num, decimal_num = 0, base = 1, rem;
    binary_num = num;
    while (num > 0)
    {
        rem = num % 10;
        decimal_num = decimal_num + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
    return decimal_num;
}
int count(long n) {
    int num = 0;
    if (n)
        do num++; while (n &= n - 1);
    return num;
}

 int main()
{
	//function_book();

	//convertDecToBin(15);
	//convertDecToBin(1120);
	cout<<convertBinToDec(1111)<<endl;
	cout<<count(15)<<endl;
	return 0;
}