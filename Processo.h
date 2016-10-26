/* 
 * File:   Processo.h
 * Author: Gustavo
 *
 * Created on 23 de Abril de 2014, 15:09
 */

#ifndef PROCESSO_H
#define	PROCESSO_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdlib.h>

typedef struct EstruturaProcesso{
    int id;
    int prioridade;
    int tempoProcessamento;
    int tamanho;
    int impressoras;
    int scanners;
    int cDs;
    int modems;
    int tempoRestante;
    int vezesNaCPU;
    int tempoChegada;
    int endereco;
    int estaMP;
}TProcesso;

TProcesso* criaProcesso(int id,int prioridade,int tempoProcessamento,int tamanho,int impressoras,int scanners,int cDs,int modems,int tempoRestante);


#ifdef	__cplusplus
}
#endif

#endif	/* PROCESSO_H */

