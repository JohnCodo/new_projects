#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
 int i=0;
//1. BOOK ,printf on the screen.  
class book
{
	public:
	char name[40];
	char autor1[40];
	char autor2[40];
	int nrpag;
	double price;
	void read_book(char *nameBook,char *autorbook1,char *autorbook2,int *np, double *p);
	void printf_book();
};
void book::read_book(char *nameBook,char *autorbook1,char *autorbook2,int *np, double *p)
{
	strcpy(name,nameBook);
	strcpy(autor1,autorbook1);
	strcpy(autor2,autorbook2);
	nrpag=*np;
	price=*p;
}
void book::printf_book()
{
	cout<<"\n Book name= "<<i<<":"<<name<<endl;
	cout<<"\n The first autor = "<<autor1<<endl;
	cout<<"\n The second autor ="<<autor2<<endl;
	cout<<"\n nr pag is ="<<nrpag<<endl;
	cout<<"\n the price is ="<<price<<endl;
}
void function_book()
{
    	book bookacitita;
	char wname[40],wautor1[40],wautor2[40];
	int wnrpag;
	double wprice;
	char r;
	r='d';
	while(r=='d')
	{
           printf("\n Den of book-->");
           fgets(wname,sizeof(wname),stdin);
           printf("\n First autor -->");
           fgets(wautor1,sizeof(wautor1),stdin);
           printf("\n Second autor -->");
           fgets(wautor2,sizeof(wautor2),stdin); 
           cout<<"\n nr. pag -->";
           cin>>wnrpag;
           cout<<"\n price -->";
           cin>>wprice;
           bookacitita.read_book(wname,wautor1,wautor2,&wnrpag,&wprice);
           bookacitita.printf_book();
           cout<<"\n Do you to continue?(y/n):";
           cin>>r;
	}
}



