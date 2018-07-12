#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>
#define BLOCOb 5


void inic_string(Strcol *p)
{
   p->str=NULL;
   p->cbloco=0;
   p->cstring=0;

   p->str=(Strcol**)malloc(BLOCOb*sizeof(Strcol*));
   p->cbloco=1;
}

void insere_string(Strcol *p,char *temp)
{
    if( (p->cbloco!=0) && (p->cstring % BLOCOb == 0))
    {
        p->cbloco++;
        p->str=(Strcol**)realloc(p->str,((p->cbloco)*BLOCOb)*sizeof(Strcol*));
    }
    p->str[ p->cstring]=(Strcol*)malloc((strlen(temp)+1)*sizeof(Strcol));
    strcpy(p->str[ p->cstring],temp);
    p->cstring++;

}

void imprime_string(Strcol *p)
{
int i;
if(p->cstring==0)
{
 printf("Agenda Vazia");
 return;
}


for(i=0; i < p->cstring ;i++)
{
    printf("\n");
    printf("%s",p->str[i]);
    printf("\n");

}
}

void remove_string(Strcol *p)
{
int i;
if(p->cstring==0)
{
 printf("Agenda Vazia");
 return;
}

for(i=0; i < p->cstring ;i++)
{
    free(p->str[i]);
}
    free(p->str);
    p->cstring=0;

}





