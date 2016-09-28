#include <stdio.h>
#include <stdlib.h>
#include "tablou.h"

#define TRUE 1
#define FALSE 0

/*4. Scrieti un program care citeste dintr-un tablou de numere: tab_numere[LUNGIME_N]
Fiecare valoare citita este stocata intr-unul din cele 3 tablouri:

tab_nrPrimePozitive[LUNGIME_PP]             //tablou de numere prime pozitive
tab_nrNonPrimePozitive[LUNGIME_NPP]    //tablou de numere pozitive care nu sunt prime
tab_nrNegative[LUNGIME_NN]                     //tablou de numere negative

tablourile si lungimile sunt definite intr-un fisier: tablou.h.
Intr-un alt fisier (decat cel care contine functia main,
scrieti functia care depisteaza daca un numar este prim sau nu).


Programul se opreste in momentul in care unul din cele trei tablouri
a fost umplut sau cand tabloul de numere a fost citit in totalitate dar
nici unul din cele trei tablouri nu a fost umplut.
Folositi facilitatea de “debug” oferit de CodeBlocks pentru a vizualiza tablourile.*/

unsigned long counter_pp=0,counter_npp=0,counter_nn=0;

 void displayArray(unsigned long array[],unsigned long lung)
{
int i,c=0;
printf("Elements for table is :");
for(i=0;i<lung;i++)
{
    printf(" %d  ",array[i]);
    c++;

if( (c>LUNGIME_PP) | (c>LUNGIME_NN) | (c>LUNGIME_NPP) | (c>LUNGIME_N) )
{
printf("error \n");
break;
}

}
 printf(" aa  %d ",c);
 printf("\n");
}

int functionPrim(unsigned long a)
{
 int i,b;
 int flag=1;
 for(i=2;(i<=a-1)&&(flag==1);i++)
 {
     if(a%i==0)
     {
        flag=0;
     }
 }
 return flag;
}

void checkTable(signed long array[])
{
int i=0;
for(i=0;i<LUNGIME_N;i++)
{
if(array[i]>=0)
{
    if(functionPrim(array[i]))
    {
    tab_nrPrimePozitive[counter_pp]=array[i];
    counter_pp++;
    printf("%d \n",counter_npp);
    }
    else
    {
    tab_nrNonPrimePozitive[counter_npp]=array[i];
    counter_npp++;
    printf("%d \n",counter_npp);
    }
}
else
{
  tab_nrNegative[counter_nn]=array[i];
  counter_nn++;
}
}
}



int main()
{

displayArray(tab_numere,LUNGIME_N);

checkTable(tab_numere);
displayArray(tab_nrPrimePozitive,counter_pp);
displayArray(tab_nrNonPrimePozitive,counter_npp);
displayArray(tab_nrNegative,counter_nn);



    return 0;
}
