#include <stdio.h>
#include <stdlib.h>

/*
8. Intr-un alt fisier decat "main.c", scrieti o functie care returneaza
pozitia unei chei in cadrul unui tablou unidimensional cu elemente sortate descrescator.
 Sa se scrie 2 variante (nerecursive) de implementare, una dintre ele mai rapida (cautare binara),
daca se cunoaste la compilare care
metoda se vrea a fi folosita (codul executabil nu trebuie sa contina ambele implementari).

*/
#define LUNG_TAB 11

int a[12]={10,9,8,7,6,12,5,4,3,2,1};

int pozitie(int cheie);
int BinarySearch(int x);
int main()
{   int x,y;
    x= pozitie(5);



    printf("%d\n",x);

    y=BinarySearch(5);
    printf(" bla bla %d\n",y);
    return 0;
}

int BinarySearch(int x){
int li,lf,k,find=0;
li=1;
lf=LUNG_TAB;

while(li<=lf)
{
    k=(li+lf)/2;

    if(x==a[k])
       { find=k;}
    else
    {if(x<a[k])
        lf=k-1;
    else
        lf=k+1;}
}

return find;
}




int pozitie(int cheie)
{
    int i,j,aux,poz;
    for(i=0;i<LUNG_TAB;i++)
    {
        for(j=i+1;j<LUNG_TAB;j++)
        {
            if(a[i]<a[j])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }

    for(i=0;i<LUNG_TAB;i++)
        {printf("%d\t",a[i]);}
    printf("\n");
    for(i=0;i<LUNG_TAB;i++)
    {
        if(a[i]==cheie)
           poz=i;
    }
    return poz;
}
