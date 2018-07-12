#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#define TAM 5000

int c;

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordem_crescente(TipoItem *vet, int tamanho)
{
    int i;
    for (i=1; i <= tamanho; i++)
    {
        vet[i].chave = i;
    }
}

void ordem_aleatoria(TipoItem *vet, int tamanho)
{
    int i, j;
    srand((unsigned)time(NULL));
    ordem_crescente(vet, tamanho);
    for (i = tamanho; i > 0; i--)
    {
        int j = 1 + (rand() % (i + 1));

        trocar(&vet[i].chave, &vet[j].chave);
    }
}


int main(void)
{
    srand(time(NULL));
    int i,aux1=1,aux2,j,z=0,a=0,b=0,d=0,f,g,k;
    int vetb;
    int status;
    int valido=0;
    int invalido=1;
    int tamanhovet=TAM;
    int escolha,controle=1;
    double tempcresc[21];
    double tempdecresc[21];
    double tempalea[21];
    TipoItem* vetcresc;
    TipoItem* vetdecresc;
    TipoItem* vetalea1;

    clock_t inicio, fim;

    while(controle!=0)
    {
        system("cls");
        printf("\n Menu: \n SelectSort (1) \n InsertSort  (2)\n BubbleSort (3)\n MergeSort (4)\n ShellSort (5) \n QuickSort (6) \n HeapSort (7) \n Sair (8) \n");
        scanf(" %i", &escolha);
        switch(escolha)
        {
        case 1:
            system("cls");


            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                SelectSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }

            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                SelectSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }

            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    SelectSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }
            getch();
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                InsertSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }


            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                InsertSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }

            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    InsertSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }

            getch();
            system("cls");
            break;
        case 3:
            system("cls");

            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                BubbleSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }
            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                BubbleSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }
            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    BubbleSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }
            getch();
            system("cls");
            break;
        case 4:
            system("cls");
            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                MergeSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }
            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                MergeSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }
            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    MergeSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }
            getch();
            system("cls");
            break;
        case 5:
            system("cls");
            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                ShellSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }
            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                ShellSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }
            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    ShellSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }
            getch();
            system("cls");
            break;
        case 6:
            system("cls");
            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                QuickSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }
            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                QuickSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }
            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    QuickSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }
            getch();
            system("cls");
            break;
        case 7:
            system("cls");
            printf("Melhor Caso:\n");
            for(i=1; i<21; i++)
            {
                aux1=1;
                c=(tamanhovet*i);
                vetcresc=(TipoItem*)malloc((c+1)*sizeof(TipoItem));
                for(j=1; j<c+1; j++)
                {
                    vetcresc[j].chave=aux1;
                    aux1++;
                }
                inicio = clock();
                HeapSort(vetcresc,c);
                fim = clock();
                tempcresc[i]= (fim - inicio) / (float)CLOCKS_PER_SEC;
                printf("Quantidade : %i  tempo: %f \n",i*5000, tempcresc[i]);
                free(vetcresc);
            }
            printf("Pior Caso:\n");
            for(a=1; a<21; a++)
            {
                f=(tamanhovet*a)+1;
                vetdecresc=(TipoItem*)malloc(f*sizeof(TipoItem));
                for(j=1; j<f; j++)
                {
                    vetdecresc[j].chave=(f-j);
                }
                inicio = clock();
                HeapSort(vetdecresc,f);
                fim = clock();
                tempdecresc[a]= ((fim - inicio) / (float)CLOCKS_PER_SEC);
                printf("Quantidade : %i  tempo: %f \n",a*5000, tempdecresc[a]);
                free(vetdecresc);
            }
            printf("Caso Médio:\n");
            for(b=1; b<21; b++)
            {
                tempalea[b]=0;
                c=(tamanhovet*b);
                f=(tamanhovet*b);
                vetalea1=(TipoItem*)malloc((f+1)*sizeof(TipoItem));
                for(k=1; k<=5; k++)
                {
                    ordem_aleatoria(vetalea1,f);
                    inicio = clock();
                    HeapSort(vetalea1,f+1);
                    fim = clock();
                    tempalea[b]+=((fim - inicio) / (double)CLOCKS_PER_SEC);
                }
                free(vetalea1);
                printf("Quantidade : %i  tempo: %f \n",b*5000, tempalea[b]/5);
            }
            getch();
            system("cls");
            break;
        case 8:
            controle=0;
            break;
        default:
            printf("COMANDO INVALIDO PRESSIONE ENTER.");
            fflush(stdin);
            getchar();
        }

    }

}


