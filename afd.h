#ifndef __AFD_H__
#define __AFD_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//==============================================================================
// Estruturas

// quantidades[0] = quantidade de estados
// quantidades[1] = quantidade de simbolos
// quantidades[2] = quantidade de transicao
// quantidades[3] = quantidade de estados finais

//==============================================================================
typedef struct afd {
    char estados[50][50];
    char alfabeto[50][50];
    char transicoes[50][50];
    char estadoInicial[50];
    char estadosFinais[50][50];
    char quantidades[4];
} AFD;

typedef struct transicao {
    char entrada[50];
    char saida[50];
    char simbolo[50];
} TRANSICAO;

AFD lerArquivo(char *afdArquivo);

TRANSICAO dividirTransicao(char *transicao);

#endif