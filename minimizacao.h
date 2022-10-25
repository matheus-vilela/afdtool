#ifndef __MINIMIZACAO_H__
#define __MINIMIZACAO_H__

#include <stdlib.h>
#include <stdio.h>


typedef struct palavras {
  char palavras[50][50];
} PALAVRAS;

typedef struct conjuntos {
  PALAVRAS palavras[50];
  int quantidade;
} CONJUNTOS;



void minimizacao(int argc, char *argv[]);

#endif