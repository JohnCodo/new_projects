#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functionImplementation.h"

// for the moment exist some comment in romanian , these will be deleted in another commit
node *findNode(node *p, float inf)
{
	for(;p!=NULL && p->info <inf; p=p->urm);
	if(p!=NULL && inf==p->info)
		return p;
	return NULL;
}
//show all list
void displayNode(node *p)
{
	printf("One node has %zu bytes, the pointer to nod has %zu bytes\n",sizeof(*p),sizeof(p));
	printf("THE LIST IS :\n");
	for(;p!=NULL;p=p->urm)
		{printf("(adr=%p) | %6g | %p | \n", p,p->info, p->urm);
		//printf("%10g",p->info);
	}
}
//adding a new element in list
node *addNode(node *base, float newInfo)
{

    node  *new, *p;
    if ((new=(node*)malloc(sizeof(node))) == NULL)
    {
   /*if the memory is not enoght, then printf a error*/
         printf("Error: the memory is missing\n");
         return NULL;
    }
    new->info=newInfo;    /* save newInfo in the curent node */
    new->urm=NULL;
        if (base==NULL)   // NULL list
         base=new;
    else
         if (p->info > newInfo){   // added to begining
             new->urm=base;
             base=new;
         }
         else{  
            for(p=base; p->urm!=NULL && p->urm->info < newInfo;  p=p->urm);
            new->urm=p->urm;
            p->urm=new;
         }
         return base;
}

node *deleteNode(node *base, float info)
{
    node *aux, *p;
    if (base==NULL){  // null list
         printf("Error: The list is NULL\n");
         return NULL;
    }
    else
         if (base->info==info){   // deleting the first element
               aux=base;
               base=base->urm;
               free(aux);
               return base;
         }
         else{
            for(p=base; p->urm!=NULL && p->urm->info < info; p=p->urm);
            if (p->urm != NULL  && p->urm->info==info) // the node exists
            {
               aux=p->urm;
               p->urm=aux->urm;  // it's about p->urm=p->urm->urm;
               free(aux);
            }
            else
               printf("Error: This node %f doesn't appear in list\n", info);
            return base;
         }
}

void meniuInterfation()
{
	char o;
    float val;
    node *baseList=NULL, *p;
	puts("");
	         /* show meniu for this program */
	         puts("a : ADD a new NODE");
	         puts("s : FIND a node and print on the screen ");
	         puts("d : DELETE a node from the list");
	         puts("l : PRINT all list");
	         puts("e : exit from this program: ");
	         printf("\n Choose the option :  ");

	         while(isspace(o=getchar()) );
	         puts("");
	         switch (tolower(o))
	         {

	         case 'a': {  printf("adding  nr=");
	                scanf("%f", &val);
	                baseList=addNode(baseList, val);
	             break;}

	         case 's': {  puts("finding a node and print");
	                printf("nr=");
	                scanf("%f", &val);
	                if ((p=findNode(baseList, val))!=NULL) /* cauta nodul in lista */
	                  printf(" The value:%f\n", p->info);
	                else
	                  printf("Error: The value is not defined\n");
	             break;
	         }

	         case 'd':{   printf("deleting  nr=");
	                scanf("%f", &val);
	             baseList=deleteNode(baseList, val); /* sterge nodul din lista */
	             break;}

	         case 'l':{  puts("printing");
	             displayNode(baseList);
	             break;}

	         case 'e':
	        	 puts("----------EXIT----------\n\n");
	             //return 0;
	             exit(1);
	         default:
	             printf("Error : The command doesn't exist\n");
	         }
}
