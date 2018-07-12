#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "tad_aeroporto.h"

contidp=0;
contidi=1;

int retira_especial(struct fila* fi,struct aviao* av)
{
    struct aviao* ant=NULL;
    struct aviao* p=fi->ini;
    struct aviao* aux;
    int temp;
    while(p->prox != NULL && p != av )
    {
        ant=p;
        p=p->prox;
    }
    if(p == NULL)
    {
        printf("Não encontrado");
        temp=0;
        return temp;
    }
    else
    {
        if(ant==NULL)
        {
            temp=fi->ini->temp;
            fila_retira(fi);
            return temp;
        }
        else
        {

            ant->prox=p->prox;
            temp=p->temp;

        }
    }
    free(p);
    fi->tam--;
    return temp;
};

struct fila* menor_lista_ate (struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4)
{
    struct fila* aux;
    struct fila* aux2;
    struct fila* aux3;
    if(fila1->tam == fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam > fila2->tam)
    {
        aux=fila2;
    }
    else if(fila1->tam < fila2->tam)
    {
        aux=fila1;
    }
    if(fila3->tam == fila4->tam)
    {
        aux2=fila3;
    }
    else if(fila3->tam > fila4->tam)
    {
        aux2=fila4;
    }
    else if(fila3->tam < fila4->tam)
    {
        aux2=fila3;
    }
    if(aux->tam == aux2->tam)
    {
        aux3=aux;
    }
    else if(aux->tam > aux2->tam)
    {
        aux3=aux2;
    }
    else if(aux->tam < aux2->tam)
    {
        aux3=aux;
    }
    return aux3;
};







struct fila* menor_lista_dec (struct fila* fila1,struct fila* fila2,struct fila* fila3)
{
    struct fila* aux;
    struct fila* aux2;
    if(fila1->tam == fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam > fila2->tam)
    {
        aux=fila2;
    }
    else if(fila1->tam < fila2->tam)
    {
        aux=fila1;
    }
    if(aux->tam == fila3->tam)
    {
        aux2=aux;
    }
    else if (aux->tam > fila3->tam)
    {
        aux2=fila3;
    }
    else if (aux->tam < fila3->tam)
    {
        aux2=aux;
    }

    return aux2;

};

struct aviao* gera_aviao(int a)
{
    struct aviao* novo=(struct aviao*)malloc(sizeof(struct aviao));
    novo->comb=(rand()%20)+1;
    if(a==0)
    {
        novo->id=contidp;
        contidp++;
        contidp++;
    }
    else
    {
        novo->id=contidi;
        contidi++;
        contidi++;
    }
    novo->temp=0;
    return novo;
}




struct fila* fila_cria ()
{
    struct fila* f=(struct fila*) malloc(sizeof(struct fila));
    f->ini=NULL;
    f->fim=NULL;
    f->tam=0;
    return f;
}

void fila_insere(struct fila* f,struct aviao* av)
{
    struct aviao* novo=(struct aviao*)malloc(sizeof(struct aviao));
    novo->comb=av->comb;
    novo->id=av->id;
    novo->temp=av->temp;
    novo->prox=NULL;
    if (f->fim != NULL)
    {
        f->fim->prox = novo;
    }
    else
    {
        f->ini = novo;
    }
    f->fim = novo;
    f->tam++;

}

int fila_retira(struct fila* f)
{

    struct aviao* t;
    int temp;
    if(fila_vazia(f)== 1)
    {
    temp=0;
    return temp;
    }
    else
    {
        t = f->ini;
        temp=f->ini->temp;
        f->ini = t->prox;
        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
        free(t);
        f->tam--;
        return temp;
    }
}

int fila_vazia (struct fila* f)
{
    if(f->ini == NULL)
    {
        return 1;
    }
    return 0;
}


void incrementa_temp(struct fila* fi)
{
    struct aviao* aux;
    for(aux=fi->ini; aux!=NULL; aux=aux->prox)
    {
        aux->temp++;
    }
}

void decrementa_comb(struct fila* fi)
{
    struct aviao* aux;
    for(aux=fi->ini; aux!=NULL; aux=aux->prox)
    {
        aux->comb--;
    }
}


void ler_fila(struct fila* fi)
{
    struct aviao* aux;
    for(aux=fi->ini; aux!=NULL; aux=aux->prox)
    {
        printf("\nID:%i  Combustivel:%i Tempo de Espera:%i",aux->id,aux->comb,aux->temp);
        printf("\n");
    }
}



int proc_tragedia(struct fila* fi)
{
    struct aviao* aux;
    int id;
    for(aux=fi->ini; aux!=NULL; aux=aux->prox)
    {
        if(aux->comb==0)
        {
            id=aux->id;
            retira_especial(fi,aux);
            return id;
        }
    }
    id=-1;
    return id;

}


struct fila* maior_lista_dois (struct fila* fila1,struct fila* fila2)
{
    struct fila* aux;
    if(fila1->tam == fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam > fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam < fila2->tam)
    {
        aux=fila2;
    }

    return aux;
};




int ajud_emerg(struct fila* fi)
{
    struct aviao* aux;
    int temp=0;
    for(aux=fi->ini; aux!=NULL; aux=aux->prox)
    {
        if(aux->comb==0)
        {
            temp=retira_especial(fi,aux);
            return temp;
        }
    }
    return temp;

}


int proc_emerg(struct fila* fi)
{
    struct aviao* aux;
    int id;
    for(aux=fi->ini; aux!=NULL; aux=aux->prox)
    {
        if(aux->comb==0)
        {
            return 1;
        }
    }
    return 0;

}




int soma_tempo_ate(struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4)
{
    int soma1=0,soma2=0,soma3=0,soma4=0,soma5;
    struct aviao* aux;
    for(aux=fila1->ini; aux!=NULL; aux=aux->prox)
    {
        soma1=soma1+aux->temp;
    }
    for(aux=fila2->ini; aux!=NULL; aux=aux->prox)
    {
        soma2=soma2+aux->temp;
    }
    for(aux=fila3->ini; aux!=NULL; aux=aux->prox)
    {
        soma3=soma3+aux->temp;
    }
    for(aux=fila4->ini; aux!=NULL; aux=aux->prox)
    {
        soma4=soma4+aux->temp;
    }
    soma5=soma1+soma2+soma3+soma4;
    return soma5;
}

int soma_tempo_dec(struct fila* fila1,struct fila* fila2,struct fila* fila3)
{
    int soma1=0,soma2=0,soma3=0,soma4;
    struct aviao* aux;
    for(aux=fila1->ini; aux!=NULL; aux=aux->prox)
    {
        soma1=soma1+aux->temp;
    }
    for(aux=fila2->ini; aux!=NULL; aux=aux->prox)
    {
        soma2=soma2+aux->temp;
    }
    for(aux=fila3->ini; aux!=NULL; aux=aux->prox)
    {
        soma3=soma3+aux->temp;
    }
    soma4=soma1+soma2+soma3;
    return soma4;
}

int soma_avi_ate(struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4)
{
    int soma=0;
    soma=fila1->tam + fila2->tam + fila3->tam + fila4->tam;
    return soma;

}

int soma_avi_dec(struct fila* fila1,struct fila* fila2,struct fila* fila3)
{
    int soma=0;
    soma=fila1->tam + fila2->tam + fila3->tam;
    return soma;

}


struct fila* maior_lista_ate_total (struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4)
{
    struct fila* aux;
    struct fila* aux2;
    struct fila* aux3;
    if(fila1->tam == fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam > fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam < fila2->tam)
    {
        aux=fila2;
    }


    if(fila3->tam == fila4->tam)
    {
        aux2=fila3;
    }
    else if(fila3->tam > fila4->tam)
    {
        aux2=fila3;
    }
    else if(fila3->tam < fila4->tam)
    {
        aux2=fila4;
    }


    if(aux->tam == aux2->tam)
    {
        aux3=aux;
    }
    else  if(aux->tam > aux2->tam)
    {
        aux3=aux;
    }
    else  if(aux->tam < aux2->tam)
    {
        aux3=aux2;
    }


    return aux3;


}



struct fila* maior_lista (struct fila* fila1,struct fila* fila2,struct fila* fila3)
{
    struct fila* aux;
    struct fila* aux2;
    if(fila1->tam == fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam > fila2->tam)
    {
        aux=fila1;
    }
    else if(fila1->tam < fila2->tam)
    {
        aux=fila2;
    }
    if(aux->tam == fila3->tam)
    {
        aux2=aux;
    }
    else if (aux->tam > fila3->tam)
    {
        aux2=aux;
    }
    else if (aux->tam < fila3->tam)
    {
        aux2=fila3;
    }

    return aux2;

}










