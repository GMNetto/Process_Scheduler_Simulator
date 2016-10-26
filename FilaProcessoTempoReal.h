/*
 * File:   FilaProcessoTempoReal.h
 * Author: Gustavo
 *
 * Created on 23 de Abril de 2014, 17:51
 */

#ifndef FILAPROCESSOTEMPOREAL_H
#define	FILAPROCESSOTEMPOREAL_H

#include "FilaProcesso.h"
#include "FilaProcessoUsuario.h"


#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct FilaProcessoTempoReal {
        TFilaProcesso*processos;
    } TTR;

    void imprimeFTR(TTR*filaTR);
    TTR*criaFTR();
    void insereFTR(TTR *filaTR, TProcesso*processo);
    void insereNoFTR(TTR*filaTR, TFilaProcesso*noProcesso);
    TFilaProcesso* retiraMenorPrioridadeFTR(TTR*filaTR);
    TFilaProcesso* retiraSuspensoFTR(TTR*filaTR);
    void liberaTR(TTR*filaTR);


#ifdef	__cplusplus
}
#endif

#endif	/* FILAPROCESSOTEMPOREAL_H */

