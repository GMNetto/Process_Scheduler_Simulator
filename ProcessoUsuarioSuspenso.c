#include "ProcessoUsuarioSuspenso.h"

TPUS*criaUS() {
    TPUS*filaUS = (TPUS*) malloc(sizeof (TPUS));
    filaUS->processos = (TFilaProcesso**) malloc(sizeof (TFilaProcesso)*3);
    int i;
    for (i = 0; i < 3; i++) {
        filaUS->processos[i] = criaLP();
    }
    return filaUS;
}

void insereUS(TPUS *filaUS, TProcesso*processo) {
    if (!processo)return;
    int indice;
    switch (processo->prioridade) {
        case 2:indice = 1;
            break;
        case 3:indice = 2;
            break;
        default:indice = 0;
    }
    adicionaLP(filaUS->processos[indice], processo);
}

void insereNoUS(TPUS*filaUS, TFilaProcesso*noProcesso) {
    TProcesso *processo = noProcesso->processo;
    int indice;
    switch (processo->prioridade) {
        case 2:indice = 1;
            break;
        case 3:indice = 2;
            break;
        default:indice = 0;
    }
    adicionaNoLP(filaUS->processos[indice], noProcesso);
}

TFilaProcesso* retiraMenorPrioridadeUS(TPUS*filaUS) {
    TFilaProcesso*atual = NULL;
    int i = 0;
    while (i < 4 && filaUS->processos[i] == NULL) {
        i++;
    }
    if (i == 4)return NULL;
    atual = filaUS->processos[i];
    filaUS->processos[i] = retiraInicioLP(filaUS->processos[i]);
}

TFilaProcesso* retiraSuspensoUS(TPUS*filaUS) {
    TFilaProcesso*atual = NULL;
    int i = 2;
    while (i>-1 && filaUS->processos[i] == NULL) {
        i--;
    }
    if (i == -1)return NULL;
    atual = buscaUltimoLP(filaUS->processos[i]);
    filaUS->processos[i] = retiraFimLP(filaUS->processos[i]);
}

void liberaUS(TPUS*filaUS) {
    if (!filaUS)return;
    int i;
    free(filaUS->processos);
    free(filaUS);
}

