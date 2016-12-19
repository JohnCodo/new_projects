
/*3. Avand urmatoarea sectiune de program (intr-un fisier main.h):

#define TABLE_DIM	7
unsigned long	tableValues[TABLE_DIM] = {5,20,50,90,100,130,139};

Scrieti o functie (intr-un fisier main.c) care primeste printr-un argument
 de tip unsigned long o valoare (ex: valViteza) si printr-un alt argument -
  tablel de intervale. Functia retureaza position valori valViteza in cadrul tablelui,
   ca in urmatorul exemplu:

valViteza < 5 – functia returneaza 0
valViteza in intervalul [5,20) – functia returneaza 1
valViteza in intervalul [20,50) – functia returneaza 2
...
valViteza >= 139 – functia returneaza 7

Nota 1: Functia trebuie sa ruleze corect daca se modifica TABLE_DIM si 
             tableValues. Folositi directive de preprocesare pentru a alege 
             din mai multe variante 
             de tableri.

Nota 2: tableValues contine valori strict crescatoare.
*/

#include <stdio.h>
#include "table.h"


int getPosition(unsigned long ,unsigned long []);
void printTableElem();
void printAllTablePositions();

int main()
{
    
    printTableElem();

    printAllTablePositions();
    
    return 0;
}

// shows all elem from tableValues which is in table.h
void printTableElem(){
    int i;
    printf("Elements of table are : ");
    for(i=0;i<TABLE_DIM;i++){
        printf(" %lu ",tableValues[i]);
    }
}
// shows all values up to the max value
void printAllTablePositions(){
    int i;
    printf("\nPosition for each value :\n");
    for(i=0;i<VALUE_MAX_TABLE;i++){
            printf("Elem from table %d = %d \n",i,getPosition(i,tableValues));
    }
}
//return position for elem of table
int getPosition(unsigned long valViteza,unsigned long table[])
{
  static  int position = 0, i;
    for( i = 0; i < TABLE_DIM ; i++ ){

        if( valViteza <= table[0] ){ position = 0; }
        else if( (valViteza >= table[i] ) && ( valViteza < table[i+1] ) ){ position=i+1; }
    }
    return position;
}