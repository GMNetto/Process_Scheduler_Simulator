#include "FilaProcessoTempoReal.h"

TTR*criaFTR() {
    TTR*filaTR = (TTR*) malloc(sizeof (TTR));
    filaTR->processos = criaLP();
    return filaTR;
}

void insereFTR(TTR *filaTR, TProcesso*processo) {
    filaTR->processos = adicionaLP(filaTR->processos, processo);
}

void insereNoFTR(TTR*filaTR, TFilaProcesso*noProcesso) {
    filaTR->processos = adicionaNoLP(filaTR->processos, noProcesso);
}

TFilaProcesso* retiraMenorPrioridadeFTR(TTR*filaTR) {
    TFilaProcesso*atual = filaTR->processos;
    filaTR->processos = atual->proximo;
    //retiraInicioLP(filaTR->processos);
    //imprimeLP(filaTR->processos);
    return NULL;
}

TFilaProcesso* retiraSuspensoFTR(TTR*filaTR) {
    TFilaProcesso*atual = buscaUltimoLP(filaTR->processos);
    filaTR->processos = retiraFimLP(filaTR->processos);
    return atual;
}

void imprimeFTR(TTR*filaTR){
    imprimeLP(filaTR->processos);
}

void liberaTR(TTR*filaTR) {
    if (!filaTR)return;
    free(filaTR);
}
