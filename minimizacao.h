#ifndef __MINIMIZACAO_H__
#define __MINIMIZACAO_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct colecao {
  GRUPOS palavras[50];
  int quantidade;
} COLECAO;

typedef struct grupos {
  char palavras[50][50];
} GRUPOS;

void minimizacao(int argc, char *argv[]);

#endif