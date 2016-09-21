
/*.11. Fie o variabila EMIOS_CCR pe 16 biti (unsigned short) care
impacheteaza urmatoarele campuri (valori pozitive): FREN, ODIS, ODISSL, UCPRE, UCPREN, DMA, IF, FCK si FEN.
Initializati aceste campuri cu valori furnizate de voi.
Verificati valoarea lui EMIOS_CCR in urma initializarii.
Afisati valorile campurilor. Modificati valoarea lui EMIOS_CCR si afisati din nou valorile campurilor.
Folositi operatii pe biti si masti.
Inainte de afisare, stocati valoarea intr-o variabila.*/


#include <stdio.h>
#include <stdlib.h>
#include "definePIN.h"

#define TR_BY_TSIZ_PINS 0
#define TR_BY_SIZE_FIELDS !TR_BY_TSIZ_PINS

#define TR_32_BIT       0
#define TR_BYTE         1
#define TR_16_BIT       2
#define RESERVED        3
#define EARP_VALUE      3

unsigned short EMIOS_CCR=0xffff;
unsigned long EBI_MCR=0xff1030AB;

void function(unsigned long val)
{
    int i,a[40];
    for(i=15;i>=0;i--)
    {
        printf("a[%d] = %d \n", i, (val&(1<<i))>>i);
    }
}

int main()
{
    function(EMIOS_CCR);

// FEN
    unsigned short FEN=(EMIOS_CCR&(1<<PIN1));
    printf("FEN value is = %d   \n",FEN>>PIN1);
    FEN=0;
     // clear the bit field
    EMIOS_CCR&=(~(1<<PIN1));
    // set a new value for FEN
    EMIOS_CCR=(EMIOS_CCR|(FEN<<PIN1));


// FCK
    unsigned short FCK=(EMIOS_CCR&(1<<PIN2));
    printf("FCK value is = %d   \n",FCK>>PIN2);
    FCK=0;
     // clear the bit field
    EMIOS_CCR&=(~(1<<PIN2));
    // set a new value for FCK
    EMIOS_CCR=(EMIOS_CCR|(FCK<<PIN2));

// IF
unsigned short  IF1=(EMIOS_CCR&(1<<PIN3)),IF2=(EMIOS_CCR&(1<<PIN4));
unsigned short  IF3=(EMIOS_CCR&(1<<PIN5)),IF4=(EMIOS_CCR&(1<<PIN6)),VAL_IF=5;
printf("Value for SIZE is %d %d %d %d \n",IF1>>PIN3,IF2>>PIN4,IF3>>PIN5,IF4>>PIN6);
  // clear the bit field
EMIOS_CCR&=(~(1<<PIN3)); EMIOS_CCR&=(~(1<<PIN4)),EMIOS_CCR&=(~(1<<PIN5)); EMIOS_CCR&=(~(1<<PIN6));
//set a new value for IF
EMIOS_CCR=(EMIOS_CCR|(VAL_IF<<PIN3));

// DMA
    unsigned short DMA=(EMIOS_CCR&(1<<PIN8));
    printf("DMA value is = %d   \n",DMA>>PIN8);
    DMA=0;
     // clear the bit field
    EMIOS_CCR&=(~(1<<PIN8));
    // set a new value for DMA
    EMIOS_CCR=(EMIOS_CCR|(DMA<<PIN8));

// UCPREN
    unsigned short UCPREN=(EMIOS_CCR&(1<<PIN9));
    printf("UCPREN value is = %d   \n",UCPREN>>PIN9);
    UCPREN=0;
     // clear the bit field
    EMIOS_CCR&=(~(1<<PIN9));
    // set a new value for UCPREN
    EMIOS_CCR=(EMIOS_CCR|(UCPREN<<PIN9));

// UPCRE
unsigned short  UPCRE1=(EMIOS_CCR&(1<<PIN10)),UPCRE2=(EMIOS_CCR&(1<<PIN11)),VAL_UPCRE=2;

printf("Value for UPCRE is %d %d \n",UPCRE1>>PIN10,UPCRE2>>PIN11);
  // clear the bit field
EMIOS_CCR&=(~(1<<PIN10)); EMIOS_CCR&=(~(1<<PIN11));
// set a new value for UPCRE
EMIOS_CCR=(EMIOS_CCR|(VAL_UPCRE<<PIN10));


// ODISSL
unsigned short  ODISSL1=(EMIOS_CCR&(1<<PIN12)),ODISSL2=(EMIOS_CCR&(1<<PIN13)),VAL_ODISSL=1;

printf("Value for ODISSL is %d %d \n",ODISSL1>>PIN12,ODISSL2>>PIN13);
  // clear the bit field
EMIOS_CCR&=(~(1<<PIN12)); EMIOS_CCR&=(~(1<<PIN13));
//sset a new value for ODISSL
EMIOS_CCR=(EMIOS_CCR|(VAL_ODISSL<<PIN12));

// ODIS
    unsigned short ODIS=(EMIOS_CCR&(1<<PIN14));
    printf("ODIS value is = %d   \n",ODIS>>PIN14);
    ODIS=0;
     // clear the bit field
    EMIOS_CCR&=(~(1<<PIN14));
    // set a new value for ODIS
    EMIOS_CCR=(EMIOS_CCR|(ODIS<<PIN14));


    // FREN
    unsigned short FREN=(EMIOS_CCR&(1<<PIN15));
    printf("FREN value is = %d   \n",FREN>>PIN15);
    FREN=0;
     // clear the bit field
    EMIOS_CCR&=(~(1<<PIN15));
    // set a new value for FREN
    EMIOS_CCR=(EMIOS_CCR|(FREN<<PIN15));


/*
unsigned long SIZE1=(EBI_MCR &(1<<PIN25)), SIZE2=(EBI_MCR &(1<<PIN24));
printf("Value for SIZE is %d %d \n",SIZE1>>PIN25,SIZE2>>PIN24);
  // clear the bit field
EBI_MCR&=(~(1<<PIN25)); EBI_MCR&=(~(1<<PIN24));
//set transfer with 16bitpai
EBI_MCR=(EBI_MCR|(TR_16_BIT<<PIN24));



    unsigned long SIZEN=(EBI_MCR &(1<<PIN26));
    //printf the bit value for SIZEN
    printf("SIZEN value is = %d   \n",SIZEN>>PIN26);
    SIZEN=TR_BY_TSIZ_PINS;
    // EBI_MCR=(EBI_MCR^(SIZEN<<26));
    // clear the bit field
    EBI_MCR&=(~(1<<PIN26));
    //change bit value  for SIZEN
    EBI_MCR=(EBI_MCR|(SIZEN<<PIN26));
*/

    printf("\n %x \n",EMIOS_CCR);




    function(EMIOS_CCR);
}
