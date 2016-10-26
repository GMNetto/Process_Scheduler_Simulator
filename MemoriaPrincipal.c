#include "MemoriaPrincipal.h"

MP*criaMP() {
    MP*novo = (MP*) malloc(sizeof (MP));
    novo->ocupacao = 0;
    novo->processo = NULL;
}

TFilaProcesso*criaNoMP(TProcesso*novo) {
    TFilaProcesso*comeco = (TFilaProcesso*) malloc(sizeof (TFilaProcesso));
    novo->estaMP = 1;
    comeco->processo = novo;
    return comeco;
}

void imprimeMP(MP*memoria){
    imprimeLP(memoria->processo);
}

MP*insereMP(MP*memoria, TProcesso*novo) {
    if (TAMANHO - memoria->ocupacao < novo->tamanho)return NULL;
    if (!memoria->processo) {
        memoria->processo = adicionaLP(memoria->processo, novo);
        novo->endereco = 0;
        novo->estaMP = 1;
        memoria->ocupacao += novo->tamanho;
        return memoria;
    }
    TFilaProcesso*atual = memoria->processo, *ant;
    if (atual->processo->endereco > novo->tamanho) {
        TFilaProcesso*comeco = (TFilaProcesso*) malloc(sizeof (TFilaProcesso));
        novo->endereco = 0;
        novo->estaMP = 1;
        comeco->processo = novo;
        comeco->proximo = atual;
        memoria->processo = comeco;
        memoria->ocupacao += novo->tamanho;
        return memoria;
    }
    if (atual->proximo == NULL) {
        if (TAMANHO - (atual->processo->endereco + atual->processo->tamanho) > novo->tamanho) {
            atual->proximo = criaNoMP(novo);
            atual->proximo->processo->endereco = (atual->processo->endereco + atual->processo->tamanho);
            memoria->ocupacao += novo->tamanho;
            return memoria;
        } else {
            return NULL;
        }
    }
    ant = atual;
    atual = atual->proximo;
    while (atual != NULL && (atual->processo->endereco)-(ant->processo->endereco + ant->processo->tamanho) < novo->tamanho) {
        ant = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        if (TAMANHO - (ant->processo->endereco + ant->processo->tamanho) > novo->tamanho) {
            ant->proximo = criaNoMP(novo);
            ant->proximo->processo->endereco = (ant->processo->endereco + ant->processo->tamanho);
            memoria->ocupacao += novo->tamanho;
            return memoria;
        }
        return NULL;
    }
    ant->proximo = criaNoMP(novo);
    ant->proximo->processo->endereco = (ant->processo->endereco + ant->processo->tamanho);
    memoria->ocupacao += novo->tamanho;
    ant->proximo->proximo = atual;
    return memoria;
}

MP*retiraMP(MP*memoria, TProcesso*processo) {
    if (!memoria->processo)return memoria;
    TFilaProcesso*atual = memoria->processo, *ant = NULL;
    while (atual != NULL & atual != processo) {
        ant = atual;
        atual = atual->proximo;
    }
    if (!ant) {
        memoria->processo = atual->proximo;
        memoria->ocupacao -= atual->processo->tamanho;
        liberaLP(atual);
        return memoria;
    }
    if (!atual)return memoria;
    ant->proximo = atual->proximo;
    memoria->ocupacao -= atual->processo->tamanho;
    liberaLP(atual);
    return memoria;
}

MP*agrupaMP(MP*memoria) {
    int ultimaPosDisponivel = 0;
    TFilaProcesso*atual = memoria->processo;
    while (atual != NULL) {
        atual->processo->endereco = ultimaPosDisponivel;
        ultimaPosDisponivel += atual->processo->tamanho;
        atual = atual->proximo;
    }
    return memoria;
}



