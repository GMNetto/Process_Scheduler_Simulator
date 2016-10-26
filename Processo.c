#include "Processo.h"

TProcesso* criaProcesso(int id,int prioridade,int tempoProcessamento,int tamanho,int impressoras,int scanners,int cDs,int modems,int tempoRestante){
    TProcesso*processo=(TProcesso*)malloc(sizeof(TProcesso));
    processo->id=id;
    processo->cDs=cDs;
    processo->impressoras=impressoras;
    processo->modems=modems;
    processo->prioridade=prioridade;
    processo->scanners=scanners;
    processo->tamanho=tamanho;
    processo->tempoProcessamento=tempoProcessamento;
    processo->tempoRestante=tempoRestante;
    processo->vezesNaCPU=0;
    processo->endereco=-1;
    processo->estaMP=0;
    return processo;
}
