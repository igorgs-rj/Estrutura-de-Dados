#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>
#include <conio.h>


     typedef struct _contato
    {
        char nome[51];
        Strcol email;
        Strcol tel;
    }Contato;

Contato** p;
int Eused=0,Ealocp=10,id;

void iniciar_agenda(void)
{

   p =(Contato**)malloc(Ealocp*sizeof(Contato*));
   if(p == NULL)
   {
      printf("Não foi possivel alocar espaço!");
      getchar();
      return;
   }
   return;
}

void inserir_contato(void)
{
    int aux,i,j,tempm;
    char temp[50];
    Contato* auxtroca;


    if(Eused >Ealocp)
    {
    Ealocp+=10;
    p=(Contato**)realloc(p,Ealocp*sizeof(Contato*));
    }

    p[Eused]=(Contato*)malloc(sizeof(Contato));

    printf("\nDigite o nome\n");
    scanf("%s",p[Eused]->nome);
    fflush(stdin);
    inic_string(&(p[Eused]->email));
    do{
       fflush(stdin);
       printf("\nDigite o email\n");
       gets(temp);
       insere_string(&(p[Eused]->email),temp);
       fflush(stdin);
      printf("\nDeseja inserir outro email?(1-sim 0-nao)\n");
      scanf("%i",&aux);
    }while(aux!=0);

    inic_string(&(p[Eused]->tel));
       do{
       fflush(stdin);
       printf("Digite o telefone\n");
       gets(temp);
       insere_string(&(p[Eused]->tel),temp);
      fflush(stdin);
      printf("\nDeseja inserir outro telefone?(1-sim 0-nao)\n");
      scanf("%i",&aux);
    }while(aux!=0);
    Eused++;


    for(i=0;i<Eused;i++){
        tempm = strlen(p[i]->nome);
            for(j=0;j<tempm;j++){

                    if( (p[i]->nome)[j] >= 97 ){
                        (p[i]->nome)[j] -= 32;
                    }
            }
    }
    if(Eused!=1)
    {
       for(i = 1; i < Eused; i++ ) {
        for(j = i; j > 0; j-- ) {
            if( strcoll(p[j]->nome, p[j-1]->nome) < 0){
              auxtroca= p[j];
              p[j]= p[j-1];
              p[j-1]=auxtroca;}
        }
    }
    }

    printf("\nContato inserido!\n");
    getch();
    return;
}

void listar_contato()
{
  int i,j,tempm;
      for(i=0;i<Eused;i++){
        tempm = (strlen(p[i]->nome)-1);
            for(j=1;j<(tempm+1);j++){

                    if( ((p[i]->nome)[j] >= 65) && ((p[i]->nome)[j] <= 90)  ){
                        (p[i]->nome)[j] += 32;
                    }
            }
    }




      if(Eused == 0){
        printf("\nAgenda Vazia !\n");
        getch();
        return;
    }
  for(i=0;i<Eused;i++)
  {

     printf("Id-> %i :",i);
     printf("%s\n",p[i]->nome);
     printf("telefones:");
     imprime_string(&(p[i]->tel));
     printf("emails:");
     imprime_string(&(p[i]->email));
     printf("---------------\n");

  }

      for(i=0;i<Eused;i++){
        tempm = strlen(p[i]->nome);
            for(j=0;j<tempm;j++){

                    if( (p[i]->nome)[j] >= 97 ){
                        (p[i]->nome)[j] -= 32;
                    }
            }
    }




       getch();
}

void remover_contato()
{
    int id,i;

    if(Eused == 0){
        printf("\nAgenda Vazia !\n");
        getch();
        return;
    }
    printf("\nDigite o indice do contato a ser deletado :");
    fflush(stdin);

    scanf("%i", &id);
    free(p[id]->nome);
    remove_string(&(p[id]->email));
    remove_string(&(p[id]->tel));

    if(id!=Eused)
    {
        for(i=id;i!=Eused;i++)
        {
            p[i]=p[i+1];
        }
    }

    Eused--;


    /*
    if(Eused <(Ealocp-1))
    {
      p=(Contato**)realloc(p,(Eused-1)*sizeof(Contato*));
      Ealocp--;
    }
    */

    printf("\nContato removido!\n");
    getch();

}


void limpar_agenda()
{
   int i;
    if(Eused == 0){
        printf("\nAgenda Vazia !\n");
        getch();
        return;
    }
   for(i=0;i>Eused;i++)
   {
    free(p[i]->nome);
    remove_string(&(p[i]->email));
    remove_string(&(p[i]->tel));
    free(p[i]);

   }
    Ealocp=10;
    Eused=0;
    p=(Contato**)realloc(p,Ealocp*sizeof(Contato*));
    printf("\nAgenda Vazia !\n");
    getch();

}


int main(){


    int escolha,controle=1;
    iniciar_agenda();
    system("color 07");

    while(controle!=0)
    {
        system("cls");
        printf("\n Menu: \n Inserir contato (1) \n Listar contato (2)\n Remover contato (3)\n Limpar todos os contatos (4)\n Fechar a agenda (5) \n");
        scanf(" %i", &escolha);
        switch(escolha)
        {
        case 1:
            system("cls");
            inserir_contato();
            system("cls");
            break;
        case 2:
            system("cls");
            listar_contato();
            system("cls");
            break;
        case 3:
            system("cls");
             remover_contato();
             system("cls");
            break;
        case 4:
            system("cls");
            limpar_agenda();
            system("cls");
            break;
        case 5:
            controle=0;
            break;

        default:
            printf("COMANDO INVALIDO PRESSIONE ENTER.");
            fflush(stdin);
            getchar();
        }

    }

}


