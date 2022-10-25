#ifndef __MINIMIZACAO_H__
#define __MINIMIZACAO_H__

#include <stdlib.h>
#include <stdio.h>


typedef struct estados {
  char palavras[50][50];
} ESTADOS;

typedef struct colecoes {
  ESTADOS estados[50];
  int quantidades[50];
} COLECOES;

void minimizacao(int argc, char *argv[]);

#endif