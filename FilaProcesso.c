#include "FilaProcesso.h"

TFilaProcesso* criaLP() {
    return NULL;
}

TFilaProcesso* adicionaNoLP(TFilaProcesso*filaExistente, TFilaProcesso*nova) {
    if (!filaExistente)return nova;
    TFilaProcesso*atual = filaExistente, *ant;

    while (atual->proximo != NULL) {
        ant = atual;
        atual = atual->proximo;
    }

    atual->proximo = nova;
    return filaExistente;
}

void imprimeLP(TFilaProcesso*filaExistente){
    TFilaProcesso *atual=filaExistente;
    while(atual){
        TProcesso*processo=atual->processo;
        printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n",processo->id,processo->cDs,processo->endereco,processo->estaMP
               ,processo->impressoras,processo->modems,processo->prioridade,processo->scanners,processo->tamanho
               ,processo->tempoChegada,processo->tempoProcessamento,processo->tempoRestante,processo->vezesNaCPU);
        atual=atual->proximo;
    }
}

TFilaProcesso* adicionaLP(TFilaProcesso*filaExistente, TProcesso *processo) {
    TFilaProcesso*novo = (TFilaProcesso*) malloc(sizeof (TFilaProcesso));
    novo->processo = processo;
    novo->proximo = NULL;
    filaExistente=adicionaNoLP(filaExistente, novo);
    return filaExistente;
}

void liberaLP(TFilaProcesso*filaExistente) {
    free(filaExistente->processo);
    free(filaExistente);
}

TFilaProcesso* retiraInicioLP(TFilaProcesso*filaExistente) {
    if (!filaExistente)return filaExistente;
    return filaExistente->proximo;
    //liberaLP(filaExistente);Fiz isso porque só faz sentido acabar com processo quando ele terminar de executar.
}

TFilaProcesso* buscaUltimoLP(TFilaProcesso*filaExistente) {
    if (!filaExistente)return filaExistente;
    TFilaProcesso*atual;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    return atual;
}

TFilaProcesso* retiraFimLP(TFilaProcesso*filaExistente) {
    if (!filaExistente)return filaExistente;
    TFilaProcesso*atual = filaExistente, *ant;
    while (atual->proximo != NULL) {
        ant = atual;
        atual = atual->proximo;
    }
    if (!ant) {
        liberaLP(atual);
        return NULL;
    }
    ant->proximo = NULL;
    //liberaLP(atual);Fiz isso porque só faz sentido acabar com processo quando ele terminar de executar.
    return filaExistente;
}
