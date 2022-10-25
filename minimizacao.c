#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"
#include "minimizacao.h"


#define MINIMIZACAO "--minimizacao"
#define OUTPUT "--output"

void calcularMinimizacao(AFD afd, char *nomeArquivo) {
    FILE *arquivoTxt;
    arquivoTxt = fopen(nomeArquivo, "w");

    CONJUNTOS minimizacao;

   

    fclose(arquivoTxt);

};

void minimizacao(int argc, char *argv[]) {
    if(argc < 5) {
        printf("Numero de argumentos invalido!");
        return;
    }
    char *arquivoEntrada = NULL;
    char *arquivoSaida = NULL;

    if(strcmp(argv[1], MINIMIZACAO) == 0){
        arquivoEntrada = argv[2];
    } else {
        exit(1);
    }
    if(strcmp(argv[4], OUTPUT) == 0){
        arquivoSaida = argv[5];
    } else {
        exit(1);
    }

    AFD afd = lerArquivo(arquivoEntrada);

    calcularMinimizacao( afd, arquivoSaida);
}