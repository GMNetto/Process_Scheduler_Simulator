/*
 * File:   FilaProcessoUsuario.h
 * Author: Gustavo
 *
 * Created on 23 de Abril de 2014, 15:42
 */

#ifndef FILAPROCESSOUSUARIO_H
#define	FILAPROCESSOUSUARIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "FilaProcesso.h"

    typedef struct TFilaProcessoUsuario{
        TFilaProcesso **processos;
    }TFU;

    TFU*criaFU();
    void imprimeFU(TFU* filaFU);
    void insereFU(TFU *filaFU, TProcesso*processo);
    void insereNoFU(TFU*filaFU, TFilaProcesso*noProcesso);
    TFilaProcesso* retiraMenorPrioridadeFU(TFU*filaFU);
    TFilaProcesso* retiraSuspensoFU(TFU*filaFU);
    void liberaFU(TFU*filaFU);
#ifdef	__cplusplus
}
#endif

#endif	/* FILAPROCESSOUSUARIO_H */

