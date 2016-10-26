/* 
 * File:   ProcessoUsuarioSuspenso.h
 * Author: Gustavo
 *
 * Created on 23 de Abril de 2014, 21:34
 */

#ifndef PROCESSOUSUARIOSUSPENSO_H
#define	PROCESSOUSUARIOSUSPENSO_H

#include "FilaProcesso.h"


#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct TProcessoUsuarioSuspenso {
        TFilaProcesso **processos;
    } TPUS;

    TPUS*criaUS();
    void insereUS(TPUS *filaUS, TProcesso*processo);
    void insereNoUS(TPUS*filaUS, TFilaProcesso*noProcesso);
    TFilaProcesso* retiraMenorPrioridadeUS(TPUS*filaUS) ;
    TFilaProcesso* retiraSuspensoUS(TPUS*filaUS);
    void liberaUS(TPUS*filaUS);

#ifdef	__cplusplus
}
#endif

#endif	/* PROCESSOUSUARIOSUSPENSO_H */

