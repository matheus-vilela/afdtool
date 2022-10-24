#ifndef __AFD_H__
#define __AFD_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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