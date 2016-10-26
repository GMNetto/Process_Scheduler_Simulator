#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS  4
#include "Processo.h"
#include "FilaProcessoTempoReal.h"
#include "MemoriaPrincipal.h"
#include "Arquivo.h"

int     number= 0;
int     count = 0;
int     thread_ids[2] = {0,1};
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;
pthread_mutex_t bloqueiaProcessoClock;
pthread_cond_t controlaProcessoClock;
pthread_mutex_t bloqueiaFE;
int contadorCiclos=0;
MP*memoria1;
MP*memoria2;
TFilaProcesso*FE=NULL;

void imprimeCiclos(){
    printf("o ciclo que simula um processo desse tipo já ocorreu: %d\n",contadorCiclos);
}

void*processoDependente(void *t){
    while(1){
        pthread_mutex_lock(&bloqueiaProcessoClock);
        pthread_cond_wait(&controlaProcessoClock,&bloqueiaProcessoClock);
        pthread_mutex_unlock(&bloqueiaProcessoClock);
        contadorCiclos++;
    }
}

void*lerArquivo(void*arq){

    FE=criaLP();
    FE=proximoProcesso(FE,"file.txt");
}

void*lerFE(void*t){
    if(!FE)return NULL;
    TFilaProcesso*aux=FE;
    FE=retiraInicioLP(FE);
    do{
        while(aux&&aux->processo->tempoChegada<=13){
            aux->proximo=NULL;
            if(memoria1->ocupacao<=memoria2->ocupacao){
                memoria1=insereMP(memoria1,aux->processo);
            }else{
                memoria2=insereMP(memoria2,aux->processo);
            }
            aux=FE;
            FE=retiraInicioLP(FE);
        }
    }while(FE);
    imprimeMP(memoria1);
    imprimeMP(memoria2);
    pthread_exit(NULL);
    return NULL;
}


void *usuario(void *t)
{
    int i;
    long my_id = (long)t;

    while(1)
    {
        scanf("%d",&number);
        int a;
        imprimeCiclos();
        scanf("%d",&a);
        number=0;
        pthread_mutex_lock(&count_mutex);
        if (!number)
        {
            pthread_cond_signal(&count_threshold_cv);
        }
        pthread_mutex_unlock(&count_mutex);
    }
    pthread_exit(NULL);
}

void *relogio(void *t)
{
    long my_id = (long)t;
    while(1)
    {
        printf("%d\n",count);
        count++;
        sleep(1);

        pthread_mutex_lock(&bloqueiaProcessoClock);
        pthread_cond_signal(&controlaProcessoClock);
        pthread_mutex_unlock(&bloqueiaProcessoClock);
        pthread_mutex_lock(&count_mutex);
        if (number)
        {
            pthread_cond_wait(&count_threshold_cv, &count_mutex);

        }
        pthread_mutex_unlock(&count_mutex);
    }
    pthread_exit(NULL);
}

int main()
{

    int i, rc;
    long t1=1, t2=2, t3=3,t4=4;
    pthread_t threads[4];
    pthread_attr_t attr;
    memoria1=criaMP();
    memoria2=criaMP();
    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init (&count_threshold_cv, NULL);
    pthread_mutex_init(&bloqueiaProcessoClock,NULL);
    pthread_cond_init(&controlaProcessoClock,NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    //pthread_create(&threads[0], &attr, relogio, (void *)t1);
    //pthread_create(&threads[1], &attr, usuario, (void *)t2);
    //pthread_create(&threads[2], &attr, lerArquivo, (void*)t3);
    lerArquivo(NULL);
    pthread_create(&threads[3], &attr, lerFE, (void*)t4);
    imprimeMP(memoria1);
    imprimeMP(memoria2);
    for (i=0; i<NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threshold_cv);
    pthread_exit(NULL);


    return 0;
}









