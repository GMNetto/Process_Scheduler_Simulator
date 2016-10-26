
/*
 * File:   MemoriaPrincipal.h
 * Author: Gustavo
 *
 * Created on 24 de Abril de 2014, 18:46
 */

#ifndef MEMORIAPRINCIPAL_H
#define	MEMORIAPRINCIPAL_H

#include "FilaProcesso.h"


#ifdef	__cplusplus
extern "C" {
#endif
#define  TAMANHO 1024

    typedef struct MemoriaPrincipal {
        TFilaProcesso*processo;
        int ocupacao;
    } MP;

    MP*criaMP();
    MP*insereMP(MP*memoria, TProcesso*novo);
    MP*retiraMP(MP*memoria,TProcesso*processo);
    MP*agrupaMP(MP*memoria);
    MP*trocaMP(MP*origem,MP*destino,TProcesso*processo);
    void imprimeMP(MP*memoria);
#ifdef	__cplusplus

#endif

#endif	/* MEMORIAPRINCIPAL_H */

