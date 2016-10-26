#include "FilaProcessoUsuario.h"

TFU*criaFU() {
    TFU*filaFU = (TFU*) malloc(sizeof (TFU));
    int i;
    filaFU->processos = (TFilaProcesso**) malloc(sizeof (TFilaProcesso*)*9);
    for (i = 0; i < 9; i++) {
        filaFU->processos[i] = criaLP();
    }
    return filaFU;
}

void imprimeFU(TFU* filaFU){
}

void insereFU(TFU *filaFU, TProcesso*processo) {
    if (!processo)return;
    int indice;
    switch (processo->prioridade) {
        case 2:indice = 1;
            break;
        case 3:indice = 2;
            break;
        default:indice = 0;
    }
    adicionaLP(filaFU->processos[indice + 3 * processo->vezesNaCPU], processo);
}

void insereNoFU(TFU*filaFU, TFilaProcesso*noProcesso) {
    TProcesso *processo = noProcesso->processo;
    int indice;
    switch (processo->prioridade) {
        case 2:indice = 1;
            break;
        case 3:indice = 2;
            break;
        default:indice = 0;
    }
    adicionaNoLP(filaFU->processos[indice + 3 * (processo->vezesNaCPU)], noProcesso);
}

TFilaProcesso* retiraMenorPrioridadeFU(TFU*filaFU) {
    TFilaProcesso*atual = NULL;
    int i = 0;
    while (i < 10 && filaFU->processos[i] == NULL) {
        i++;
    }
    if (i == 10)return NULL;
    atual = filaFU->processos[i];
    filaFU->processos[i] = retiraInicioLP(filaFU->processos[i]);
}

TFilaProcesso* retiraSuspensoFU(TFU*filaFU) {
    TFilaProcesso*atual = NULL;
    int i = 8;
    while (i>-1 && filaFU->processos[i] == NULL) {
        i--;
    }
    if (i == -1)return NULL;
    atual = buscaUltimoLP(filaFU->processos[i]);
    filaFU->processos[i] = retiraFimLP(filaFU->processos[i]);
}

void liberaFU(TFU*filaFU) {
    if (!filaFU)return;
    int i;
    free(filaFU->processos);
    free(filaFU);
}
