#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"
#include "visualizacao.h"

#define COMPLEMENTO "--complemento"
#define OUTPUT "--output"

void converterParaTxt(AFD afd, char *nomeArquivo) {
    FILE *arquivoTxt;
    arquivoTxt = fopen(nomeArquivo, "w");

    fprintf(arquivoTxt, "%d\n", afd.quantidades[0]);
    for(int i = 0; i < afd.quantidades[0]; i++) {
        fputs(afd.estados[i], arquivoTxt);
    }

    fprintf(arquivoTxt, "%d\n", afd.quantidades[1]);
    for(int i = 0; i < afd.quantidades[1]; i++) {
        fputs(afd.alfabeto[i], arquivoTxt);
    }

    fprintf(arquivoTxt, "%d\n", afd.quantidades[2]);
    for(int i = 0; i < afd.quantidades[2]; i++) {
        fputs(afd.transicoes[i], arquivoTxt);
    }

    fputs(afd.estadoInicial, arquivoTxt);

    fprintf(arquivoTxt, "%d\n", afd.quantidades[0] - afd.quantidades[3]);
    for(int i = 0; i < afd.quantidades[0]; i++) {
      int existe = 0;
      for (int j = 0; j < afd.quantidades[3]; j++) {

        if (strcmp(strtok(afd.estados[i], "\n"), strtok(afd.estadosFinais[j], "\n")) == 0) {
        printf("ESTADO FINAL ==> %s %s\n", afd.estadosFinais[j], afd.estados[i]);
          existe = 1;
        }
      }
      if(existe == 0) {
        fputs(afd.estados[i], arquivoTxt);
      }
    }

    fclose(arquivoTxt);

};

void complemento(int argc, char *argv[]) {
    if(argc < 5) {
        printf("Numero de argumentos invalido!");
        return;
    }
    char *arquivoEntrada = NULL;
    char *arquivoSaida = NULL;

    if(strcmp(argv[1], COMPLEMENTO) == 0){
        arquivoEntrada = argv[2];
    } else {
        exit(1);
    }
    if(strcmp(argv[3], OUTPUT) == 0){
        arquivoSaida = argv[4];
    } else {
        exit(1);
    }

    AFD afd = lerArquivo(arquivoEntrada);
    converterParaTxt(afd, arquivoSaida);
}