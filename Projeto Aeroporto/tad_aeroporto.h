struct aviao{
int comb,temp,id;
struct aviao* prox;
};

struct fila{
int tam;
struct aviao* ini;
struct aviao* fim;
};

struct fila* fila_cria (); ////funcao que cria uma  fila
void fila_insere(struct fila* f,struct aviao* av);  ////funcao de inserir aviao em uma fila
int fila_retira(struct fila* f);    ////funcao de retirar aviao em uma fila
int fila_vazia (struct fila* f);
struct aviao* gera_aviao(int a);   ////funcao que um aviao randomizado
void incrementa_temp(struct fila* fi); ////funcao que incrementa o tempo de espera de todos os avioes de uma fila
void decrementa_comb(struct fila* fi);////funcao que decrementa o combustivel de todos os avioes de uma fila
void ler_fila(struct fila* fi);     ////funcao que imprime todos os componentes de uma  fila
struct fila* menor_lista_ate (struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4);  ////funcao que retorna a menor fila de ate
struct fila* menor_lista_dec (struct fila* fila1,struct fila* fila2,struct fila* fila3);     ////funcao que retorna a menor fila de dec
int retira_especial(struct fila* fi,struct aviao* av);  ////funcao que retira um elemento  da fila da mesma forma que uma lista
int proc_tragedia(struct fila* fi);      ////funcao que se encontra uma tragedia ele retira o elemento da fila
int proc_emerg(struct fila* fi);         ////funcao que verifica se existe uma emergencia em uma fila
struct fila* maior_lista_dois (struct fila* fila1,struct fila* fila2);   ////funcao que retorna a maior de 2 filas
struct fila* maior_lista_ate_total (struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4);  ////funcao que retorna a maior de todas as filas de ate
struct fila* maior_lista (struct fila* fila1,struct fila* fila2,struct fila* fila3);        ////funcao que retorna a maior de todas as filas de dec
int soma_avi_ate(struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4);
int soma_avi_dec(struct fila* fila1,struct fila* fila2,struct fila* fila3);
int soma_tempo_dec(struct fila* fila1,struct fila* fila2,struct fila* fila3);
int soma_tempo_ate(struct fila* fila1,struct fila* fila2,struct fila* fila3,struct fila* fila4);
int ajud_emerg(struct fila* fi);  ////funcao que retira o aviao em emergencia

