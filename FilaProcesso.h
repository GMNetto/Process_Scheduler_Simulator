/*
 * File:   FilaProcesso.h
 * Author: Gustavo
 *
 * Created on 23 de Abril de 2014, 15:02
 */

#ifndef FILAPROCESSO_H
#define	FILAPROCESSO_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "Processo.h"

    typedef struct noListaProcesso{
        TProcesso *processo;
        struct noListaProcesso *proximo;
    }TFilaProcesso;

    void imprimeLP(TFilaProcesso*filaExistente);
    TFilaProcesso* criaLP();
    TFilaProcesso* adicionaLP(TFilaProcesso*filaExistente, TProcesso *processo);
    TFilaProcesso* adicionaNoLP(TFilaProcesso*filaExistente, TFilaProcesso*nova);
    void liberaLP(TFilaProcesso*filaExistente);
    TFilaProcesso* retiraInicioLP(TFilaProcesso*filaExistente);
    TFilaProcesso* buscaUltimoLP(TFilaProcesso*filaExistente);
    TFilaProcesso* retiraFimLP(TFilaProcesso*filaExistente);
#ifdef	__cplusplus
}
#endif

#endif	/* FILAPROCESSO_H */

