typedef struct _strcol{
char ** str;
int cbloco,cstring;
}Strcol;



void inic_string(Strcol *p);
void insere_string(Strcol *p,char *temp);
void imprime_string(Strcol *p);
void remove_string(Strcol *p);

