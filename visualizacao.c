#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"
#include "visualizacao.h"

#define DOT "--dot"
#define SAIDA "--output"


void converterParaDot(AFD afd, char *nomeArquivo) {
  FILE *arquivoDot;
  arquivoDot = fopen(nomeArquivo, "w");

  fputs("digraph finite_state_machine {\n", arquivoDot);
  fputs("\trankdir=LR;\n", arquivoDot);
  fputs("\tsize=\"8,5\"\n", arquivoDot);
  fputs("\tnode [shape = doublecircle]; ", arquivoDot);

  for (int i = 0; i < afd.quantidades[3]; i++) {
    fprintf(arquivoDot, "%s", afd.estadosFinais[i]);
  }

  fputs(";\n", arquivoDot);
  fputs("\tnode [shape = circle];\n", arquivoDot);

  char *inicial;
  char *simbolo;
  char *destino;

  for (int j = 0; j < afd.quantidades[2]; j++) {
    inicial = strtok(afd.transicoes[j], " ");
    simbolo = strtok(NULL, " ");
    destino = strtok(NULL, "\n");

    fprintf(arquivoDot, "\t%s -> %s [ label = \"%s\" ];\n", inicial, destino, simbolo);
  }

  fputs("}", arquivoDot);

  fclose(arquivoDot);
}

void visualizacao(int argc, char *argv[]) {
    if(argc < 5) {
        printf("Numero de argumentos invalido!");
        return;
    }
    char *arquivoEntrada = NULL;
    char *arquivoSaida = NULL;

    if(strcmp(argv[1], DOT) == 0){
        arquivoEntrada = argv[2];
    } else {
        exit(1);
    }
    if(strcmp(argv[3], SAIDA) == 0){
        arquivoSaida = argv[4];
    } else {
        exit(1);
    }

    printf("Arquivo de entrada: %s\n", arquivoEntrada);
    printf("Arquivo de saida: %s\n", arquivoSaida);

    AFD afd = lerArquivo(arquivoEntrada);
    converterParaDot(afd, arquivoSaida);

    // return 0;
}