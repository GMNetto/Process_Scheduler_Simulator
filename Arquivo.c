#include "Arquivo.h"
#include <windows.h>

FILE* abreArquivo(char*nome) {
    FILE*arquivo = fopen(nome, "rt");
    return arquivo;
}

TProcesso* proximoProcesso(TFilaProcesso*fila,char*nome) {
    FILE*arquivo = fopen(nome, "rt");
    char pVirg[2];
    int a;
    int resultadoLeitura;
    do{
        TProcesso*processo = (TProcesso*) malloc(sizeof (TProcesso));
        resultadoLeitura = fscanf(arquivo,"%d, %d, %d, %d, %d, %d, %d, %d",&processo->tempoChegada, &processo->prioridade, &processo->tempoProcessamento
            , &processo->tamanho, &processo->impressoras, &processo->scanners, &processo->modems, &processo->cDs);

        processo->tempoRestante = 0;
        processo->vezesNaCPU = 0;
        //printf("%d\n",resultadoLeitura);
        if(resultadoLeitura==8)
            fila=adicionaLP(fila,processo);
        //imprimeLP(fila);
    }while(resultadoLeitura==8);

    fclose(arquivo);
    return fila;

}

void fechaArquivo(FILE*arquivo) {
    fclose(arquivo);
}
