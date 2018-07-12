#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"


void SelectSort(TipoItem *vet, int n) //certo para cresc , decresc e aleat(mandar tam na chamada de função)
{
    int i, j, min;
    TipoItem item;
    for (i = 1; i <= n - 1; i++)
    {
        min = i;
        for (j = i + 1; j <= n-1; j++)
            if (vet[j].chave < vet[min].chave)
                min = j;
        item = vet[min];
        vet[min] = vet[i];
        vet[i] = item;
    }

}


void InsertSort(TipoItem *vet, int n)  //certo para cresc , decresc e aleat(mandar tam-1 na chamada de função)
{
    int i, j;
    TipoItem item;
    for (i = 2; i <= n; i++)
    {
        item = vet[i];
        j = i - 1;
        vet[0] = item;
        while (item.chave < vet[j].chave)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = item;
    }
}

void BubbleSort(TipoItem *vet, int n)    //certo para cresc , decresc e aleat(mandar tam-1 na chamada de função)
{
    int i, j;
    TipoItem item;
    for (i = n; i >= 2; i--)
        for (j = 2; j <= i; j++)
            if (vet[j].chave < vet[j - 1].chave)
            {
                item = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = item;
            }
}


void MergeSort(TipoItem *vet, int n) //certo para cresc , decresc e aleat(mandar tam-1 na chamada de função)
{
    Sort(1, n, vet);
}

void Sort(int ini, int fim, TipoItem *vet)
{
    int i, j, k, meio;
    TipoItem *aux;
    if (ini < fim)
    {
        meio = (ini + fim) / 2;
        Sort(ini, meio, vet);
        Sort(meio + 1, fim, vet);
        Merge(vet, ini, meio, fim);
    }
}

void Merge(TipoItem *vet, int ini, int meio, int fim)
{
    int i = ini;
    int j,k;
    j = meio + 1;
    k = 0;
    TipoItem *aux = (TipoItem *)malloc(sizeof(TipoItem) *(fim - ini + 1));
    while ((i < meio + 1) || (j < fim + 1))
    {
        if (i == meio + 1 )
        {
            aux[k] = vet[j];
            j++;
            k++;
        }
        else
        {
            if (j == fim + 1)
            {
                aux[k] = vet[i];
                i++;
                k++;
            }
            else
            {
                if (vet[i].chave < vet[j].chave)
                {
                    aux[k] = vet[i];
                    i++;
                    k++;
                }
                else
                {
                    aux[k] = vet[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for (i = ini; i <= fim; i++)
        vet[i] = aux[i - ini];
    free(aux);
}


void ShellSort(TipoItem *vet, int n) //certo para cresc , decresc e aleat(mandar tam-1 na chamada de função)
{
    int i, j, h = 1;
    TipoItem item;
    do
        h = h * 3 + 1; //cálculo de h
    while (h < n);
    do
    {
        h /= 3;
        for (i = h + 1; i <= n; i++)
        {
            item = vet[i];
            j = i;
            while (vet[j - h].chave > item.chave)
            {
                vet[j] = vet[j - h];
                j -= h;
                if (j <= h)
                    break;
            }
            vet[j] = item;
        }
    }
    while (h != 1);
}

void Partition(int esq, int dir, int *i, int *j, TipoItem *vet)
{
    TipoItem pivo, item;
    *i = esq;
    *j = dir;
    pivo = vet[(*i + *j) / 2];
    do
    {
        while (pivo.chave > vet[*i].chave) (*i)++;
        while (pivo.chave < vet[*j].chave) (*j)--;
        if (*i <= *j)
        {
            item = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = item;
            (*i)++;
            (*j)--;
        }
    }
    while (*i <= *j);
}

void Sort2(int esq, int dir, TipoItem *vet)
{
    int i, j;
    Partition(esq, dir, &i, &j, vet);
    if (esq < j)
        Sort2(esq, j, vet);
    if (i < dir)
        Sort2(i, dir, vet);
}

void QuickSort(TipoItem *vet, int n)  //certo para cresc , decresc e aleat(mandar tam-1 na chamada de função)
{
    Sort2(1, n, vet);
}

void Construct(TipoItem *vet, int n)
{
    int esq;
    esq = n / 2 + 1;
    while (esq > 1)
    {
        esq--;
        Reconstruct(esq, n, vet);
    }
}

void Reconstruct(int esq, int dir, TipoItem *vet)
{
    int j, i = esq;
    TipoItem item;
    j = i * 2;
    item = vet[i];
    while (j <= dir)
    {
        if (j < dir)
            if (vet[j].chave < vet[j + 1].chave) j++;
        if (item.chave >= vet[j].chave) break;
        else
        {
            vet[i] = vet[j];
            i = j;
            j = i * 2;
        }
    }
    vet[i] = item;
}

void HeapSort(TipoItem *vet, int n)  //certo para cresc , decresc e aleat(mandar tam-1 na chamada de função)
{
    int esq, dir;
    TipoItem item;
    Construct(vet, n);
    esq = 1;
    dir = n;
    while (dir > 1)
    {
        item = vet[1];
        vet[1] = vet[dir];
        vet[dir] = item;
        dir--;
        Reconstruct(esq, dir, vet);
    }

}






























