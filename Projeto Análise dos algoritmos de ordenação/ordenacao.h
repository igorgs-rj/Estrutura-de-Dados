typedef struct
{
int chave;
}TipoItem;


void SelectSort(TipoItem *vet, int n);
void InsertSort(TipoItem *vet, int n);
void BubbleSort(TipoItem *vet, int n);
void Merge(TipoItem *vet, int ini, int meio, int fim);
void Sort(int ini, int fim, TipoItem *vet);
void MergeSort(TipoItem *vet, int n);
void ShellSort(TipoItem *vet, int n);
void Partition(int esq, int dir, int *i, int *j, TipoItem *vet);
void Sort2(int esq, int dir, TipoItem *vet);
void QuickSort(TipoItem *vet, int n);
void Construct(TipoItem *vet, int n);
void Reconstruct(int esq, int dir, TipoItem *vet);
void HeapSort(TipoItem *vet, int n);
