#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "tad_aeroporto.h"

int main()
{
    srand(time(NULL));
    system("MODE con cols=120 lines=120");

    int i,a,cont,trag,emerg=0,pista1=0,pista2=0,pista3=0,ciclo1=0,ciclo2=0,ciclo3=0,ciclo4=0,somaavate=0,somaavdec=0,somatempate=0,somatempdec=0,armzate=0,armzdec=0,cont2=0,contemerg=0,conttemp=1;
    float medate,meddec;
    struct fila* ate1;
    struct fila* ate2;
    struct fila* ate3;
    struct fila* ate4;

    struct fila* dec1;
    struct fila* dec2;
    struct fila* dec3;

    struct fila* aux;
    struct aviao* av1;


    ate1=fila_cria ();
    ate2=fila_cria ();
    ate3=fila_cria ();
    ate4=fila_cria ();

    dec1=fila_cria ();
    dec2=fila_cria ();
    dec3=fila_cria ();


    while(1)
    {
        system("cls");


        printf("Primeira parte da passagem de tempo:(Depois dos avioes recem gerados serem encaixados nas suas respectivas filas)\n\n");


        a=0;
        cont=rand()%4;  //// gera os aviaoes de aterrissagem  e os insere nas suas respectivas filas
        for(i=0; i<cont; i++)
        {
            av1=gera_aviao(a);
            aux=menor_lista_ate(ate1,ate2,ate3,ate4);
            fila_insere(aux,av1);
        }

        a=1;
        cont=rand()%4;   //// gera os aviaoes de decolagem e os insere nas suas respectivas filas
        for(i=0; i<cont; i++)
        {
            av1=gera_aviao(a);
            aux=menor_lista_dec(dec1,dec2,dec3);
            fila_insere(aux,av1);
        }
        printf("Fila de aterrissagem:\n");
        printf("ATE1:");
        ler_fila(ate1);
        printf("\n\n");
        printf("ATE2:");
        ler_fila(ate2);
        printf("\n\n");
        printf("ATE3:");
        ler_fila(ate3);
        printf("\n\n");
        printf("ATE4:");
        ler_fila(ate4);
        printf("\n\n");
        printf("----------------------------------------------------------");


        printf("\n\n");
        printf("Fila de decolagem:\n");
        printf("DEC1:");
        ler_fila(dec1);
        printf("\n\n");
        printf("DEC2:");
        ler_fila(dec2);
        printf("\n\n");
        printf("DEC3:");
        ler_fila(dec3);
        printf("\n\n");




        printf("----------------////////////////////////////////----------------\n");




        printf("Segunda parte da passagem de tempo:(Depois das operacoes das pistas (aterrissagem ou decolagem) serem feitas)");

        do   //// procura por tres emergencias nas 4 filas de aterrissagem
        {

            if(proc_emerg(ate1)!=0)
            {
                emerg=emerg+1;
                somatempate=somatempate+ajud_emerg(ate1);   ////armazena o tempo de espera dos avioes que aterrissaram
                somaavate++;
                contemerg++;
                if(emerg==1)
                {
                    pista3=1;
                }
                else if(emerg==2)
                {
                    pista1=1;
                }
                else if(emerg==3)
                {
                    pista2=1;
                }
            }
            else
            {
                ciclo1=1;
            }
            if(emerg==3)
            {
                break;
            }
            if(ciclo1!=0 && ciclo2!=0 && ciclo3!=0 && ciclo4!=0)
            {
                break;
            }


            if(proc_emerg(ate2)!=0)
            {
                emerg=emerg+1;
                somatempate=somatempate+ajud_emerg(ate2);
                somaavate++;
                contemerg++;
                if(emerg==1)
                {
                    pista3=1;
                }
                else if(emerg==2)
                {
                    pista1=1;
                }
                else if(emerg==3)
                {
                    pista2=1;
                }
            }
            else
            {
                ciclo2=1;
            }
            if(emerg==3)
            {
                break;
            }
            if(ciclo1!=0 && ciclo2!=0 && ciclo3!=0 && ciclo4!=0)
            {
                break;
            }


            if(proc_emerg(ate3)!=0)
            {
                emerg=emerg+1;
                somatempate=somatempate+ajud_emerg(ate3);
                somaavate++;
                contemerg++;
                if(emerg==1)
                {
                    pista3=1;
                }
                else if(emerg==2)
                {
                    pista2=1;
                }
                else if(emerg==3)
                {
                    pista1=1;
                }
            }
            else
            {
                ciclo3=1;
            }
            if(emerg==3)
            {
                break;
            }
            if(ciclo1!=0 && ciclo2!=0 && ciclo3!=0 && ciclo4!=0)
            {
                break;
            }



            if(proc_emerg(ate4)!=0)
            {
                emerg=emerg+1;
                somatempate=somatempate+ajud_emerg(ate4);
                somaavate++;
                contemerg++;
                if(emerg==1)
                {
                    pista3=1;
                }
                else if(emerg==2)
                {
                    pista2=1;
                }
                else if(emerg==3)
                {
                    pista1=1;
                }
            }
            else
            {
                ciclo4=1;
            }
            if(emerg==3)
            {
                break;
            }
            if(ciclo1!=0 && ciclo2!=0 && ciclo3!=0 && ciclo4!=0)
            {
                break;
            }
        }
        while(emerg<3);


        if(emerg==0)   ////inicia o ciclo de aterrissagens e decolagem dependendo do numero de emergencias
        {

            aux=maior_lista(ate1,ate2,dec1);
            if(aux == ate1 || aux==ate2)
            {
            somatempate=somatempate+fila_retira(aux);
            somaavate++;
            }
            else if(aux==dec1)
            {
            somatempdec=somatempdec+fila_retira(aux);
            somaavdec++;
            }
            aux=maior_lista(ate3,ate4,dec2);
            if(aux == ate3 || aux==ate4)
            {
            somatempate=somatempate+fila_retira(aux);
            somaavate++;
            }
            else if(aux==dec2)
            {
            somatempdec=somatempdec+fila_retira(aux);
            somaavdec++;
            }
            fila_retira(dec3);

        }
        else if(emerg==1)
        {
            if(pista3==1)
            {
            aux=maior_lista(ate1,ate2,dec1);
            if(aux == ate1 || aux==ate2)
            {
            somatempate=somatempate+fila_retira(aux);
            somaavate++;
            }
            else if(aux==dec1)
            {
            somatempdec=somatempdec+fila_retira(aux);
            somaavdec++;
            }
            aux=maior_lista(ate3,ate4,dec2);
            if(aux == ate3 || aux==ate4)
            {
            somatempate=somatempate+fila_retira(aux);
            somaavate++;
            }
            else if(aux==dec2)
            {
            somatempdec=somatempdec+fila_retira(aux);
            somaavdec++;
            }
            }
        }
        else if(emerg==2)
        {
            if(pista1==1)
            {
            aux=maior_lista(ate3,ate4,dec2);
            if(aux == ate3 || aux==ate4)
            {
            somatempate=somatempate+fila_retira(aux);
            somaavate++;
            }
            else if(aux==dec2)
            {
            somatempdec=somatempdec+fila_retira(aux);
            somaavdec++;
            }
            }
            else if(pista2==1)
            {
            aux=maior_lista(ate1,ate2,dec1);
            if(aux == ate1 || aux==ate2)
            {
            somatempate=somatempate+fila_retira(aux);
            somaavate++;
            }
            else if(aux==dec1)
            {
            somatempdec=somatempdec+fila_retira(aux);
            somaavdec++;
            }
            }
        }

        emerg=0;
        pista1=0;
        pista2=0;
        pista3=0;
        ciclo1=0;
        ciclo2=0;
        ciclo3=0;
        ciclo4=0;



        printf("\n\nTragedia:\n");   //// verifica se algum aviao caiu
        do
        {
            trag=proc_tragedia(ate1);
            if(trag!=-1)
            {
                printf("ID:%i\n",trag);
                system("color 40");

                system("color 07");
            }
        }
        while(trag!=-1);

        do
        {
            trag=proc_tragedia(ate2);
            if(trag!=-1)
            {
                printf("ID:%i\n",trag);
                system("color 40");

                system("color 07");
            }
        }
        while(trag!=-1);

        do
        {
            trag=proc_tragedia(ate3);
            if(trag!=-1)
            {
                printf("ID:%i\n",trag);
                system("color 40");

                system("color 07");
            }
        }
        while(trag!=-1);


        do
        {
            trag=proc_tragedia(ate4);
            if(trag!=-1)
            {
                printf("ID:%i\n",trag);
                system("color 40");

                system("color 07");
            }
        }
        while(trag!=-1);


        printf("\n\n");

        printf("Fila de aterrissagem:\n");
        printf("ATE1:");
        ler_fila(ate1);
        printf("\n\n");
        printf("ATE2:");
        ler_fila(ate2);
        printf("\n\n");
        printf("ATE3:");
        ler_fila(ate3);
        printf("\n\n");
        printf("ATE4:");
        ler_fila(ate4);
        printf("\n\n");

        if(somaavate==0||somatempate==0)  ////faz a media do tempo de espera dos avioes que sairam
        {
            medate=0;
        }
        else
        {
            medate=somatempate/somaavate;
        }
        if(medate==0)
        {
            medate=armzate;
        }
        if(cont2==1)
        {
            if(medate!=0)
            {
             medate=(armzate+medate)/conttemp;
            }
            else
            {
                medate=armzate;
            }

        }
        armzate=medate;

        printf("Media do tempo de espera de aterrissagem:%.2f \n",medate);

        printf("----------------------------------------------------------");


        printf("\n\n");
        printf("Fila de decolagem:\n");
        printf("DEC1:");
        ler_fila(dec1);
        printf("\n\n");
        printf("DEC2:");
        ler_fila(dec2);
        printf("\n\n");
        printf("DEC3:");
        ler_fila(dec3);
        printf("\n\n");


        if(somaavdec==0||somatempdec==0)  ////faz a media do tempo de espera dos avioes que sairam
        {
            meddec=0;
        }
        else
        {
            meddec=somatempdec/somaavdec;
        }
        if(meddec==0)
        {
            meddec=armzdec;
        }
        if(cont2==1)
        {
            if(meddec!=0)
            {
             meddec=(armzdec+meddec)/conttemp;
            }
            else
            {
                meddec=armzdec;
            }

        }
        armzdec=meddec;

        printf("Media do tempo de espera de decolagem:%.2f \n",meddec);
        printf("\nQuantidade de avioes em estado de emergencia:%i",contemerg);




        if(cont2==0)
        {
            cont2++;
        }
        somaavate=0;
        somaavdec=0;
        somatempate=0;
        somatempdec=0;

        contemerg=0;
        conttemp++;





        decrementa_comb(ate1);//// decrementa comb e tempo
        decrementa_comb(ate2);
        decrementa_comb(ate3);
        decrementa_comb(ate4);

        incrementa_temp(ate1);
        incrementa_temp(ate2);
        incrementa_temp(ate3);
        incrementa_temp(ate4);

        incrementa_temp(dec1);
        incrementa_temp(dec2);
        incrementa_temp(dec3);


        getch();
    }
    return 0;
}
