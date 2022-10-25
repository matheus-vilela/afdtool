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

    ESTADOS naofinais;
    ESTADOS finais;

    int quantidadeFinais = 0;
    int quantidadeNaoFinais = 0;
    for(int i = 0; i < afd.quantidades[0]; i++){
        for(int j = 0; j < afd.quantidades[3]; j++){
            if(strcmp(strtok(afd.estados[i], "\n"), strtok(afd.estadosFinais[j], "\n")) == 0){
                strcpy(finais.palavras[quantidadeFinais], afd.estadosFinais[j]);
                quantidadeFinais++;
            } else {
                strcpy(naofinais.palavras[quantidadeNaoFinais], afd.estados[i]);
                quantidadeNaoFinais++;
            }
        }
    }

    for(int i = 0; i < quantidadeFinais; i++){
        printf("ESTADOS FINAIS %s\n", finais.palavras[i]);
    }

    for(int i = 0; i < quantidadeNaoFinais; i++){
        printf("ESTADOS NAO FINAIS %s\n", naofinais.palavras[i]);
    }

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
    if(strcmp(argv[3], OUTPUT) == 0){
        arquivoSaida = argv[4];
    } else {
        exit(1);
    }

    AFD afd = lerArquivo(arquivoEntrada);

    calcularMinimizacao( afd, arquivoSaida);
}