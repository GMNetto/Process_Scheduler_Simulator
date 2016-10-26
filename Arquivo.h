/*
 * File:   Arquivo.h
 * Author: Gustavo
 *
 * Created on 23 de Abril de 2014, 20:53
 */

#ifndef ARQUIVO_H
#define	ARQUIVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Processo.h"
#include "FilaProcesso.h"
#include <stdio.h>

    FILE* abreArquivo(char*nome);
    TProcesso* proximoProcesso(TFilaProcesso*lista,char*nome);
    void fechaArquivo(FILE*arquivo);


#ifdef	__cplusplus
}
#endif

#endif	/* ARQUIVO_H */

