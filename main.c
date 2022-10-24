#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "visualizacao.h"
#include "complemento.h"
#include "intersecao.h"
#include "uniao.h"
#include "reconhecer.h"

#define VISUALIZACAO "--dot"
#define UNIAO "--uniao"
#define INTERSECAO "--intersecao"
#define COMPLEMENTO "--complemento"
#define MINIMIZACAO "--minimizacao"
#define RECONHECER "--reconhecer"

int main(int argc, char *argv[]){

  char *operacao = NULL;

  if(argc < 2){
    printf("Numero de argumentos invalido!");
    return 1;
  }

  if(strcmp(argv[1], VISUALIZACAO) == 0){
    visualizacao(argc, argv);
    operacao = "visualizacao";
  } else if(strcmp(argv[1], COMPLEMENTO) == 0){
    complemento(argc, argv);
    operacao = "complemento";
  } else if(strcmp(argv[1], INTERSECAO) == 0){
    intersecao(argc, argv);
    operacao = "intersecao";
  } else if(strcmp(argv[1], UNIAO) == 0){
    uniao(argc, argv);
    operacao = "uniao";
  } else if(strcmp(argv[1], MINIMIZACAO) == 0){
    // minimizacao(argc, argv);
    operacao = "minimizacao";
  } else if(strcmp(argv[1], RECONHECER) == 0){
    reconhecer(argc, argv);
    operacao = "reconhecer";
  } else {
    printf("Operacao invalida!\n");
    return 1;
  }


    return 0;
}