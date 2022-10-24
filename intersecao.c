#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"
#include "visualizacao.h"

#define INTERSECAO "--intersecao"
#define OUTPUT "--output"

void calcularIntersecao(AFD afd, AFD afd2, char *nomeArquivo) {
    FILE *arquivoTxt;
    arquivoTxt = fopen(nomeArquivo, "w");

    int quantidadeTotalEstados = afd.quantidades[0] + afd2.quantidades[0];

    //Calcula a intersecao dos estados finais
    fprintf(arquivoTxt, "%d\n", quantidadeTotalEstados);
    for(int i = 0; i < afd.quantidades[0]; i++) {
        for(int j = 0; j < afd2.quantidades[0]; j++) {
          char *estado1 = strtok(afd.estados[i], "\n");
          char *estado2 = strtok(afd2.estados[j], "\n");
          fprintf(arquivoTxt, "%s%s\n", afd.estados[i], afd2.estados[j]);
        }
    }

    //Calcula a intersecao do alfabeto
    fprintf(arquivoTxt, "%d\n", afd.quantidades[1]);
    for(int i = 0; i < afd.quantidades[1]; i++) {
        fputs(afd.alfabeto[i], arquivoTxt);
    }

    //Calcula a quantidade das transicoes
    fprintf(arquivoTxt, "%d\n", afd.quantidades[1] * quantidadeTotalEstados);
    

    //Calcula a intersecao das transicoes
    char initial, simbolo, destino;
    char *transicao;
    char initial2, simbolo2, destino2;
    char *transicao2;
    for (int i = 0; i < afd.quantidades[2]; i++) {
      transicao = strtok(afd.transicoes[i], "\n");
      initial = transicao[0];
      simbolo = transicao[2];
      destino = transicao[4];

      for(int j = 0; j < afd2.quantidades[2]; j++) {
        transicao2 = strtok(afd2.transicoes[j], "\n");
        initial2 = transicao2[0];
        simbolo2 = transicao2[2];
        destino2 = transicao2[4];

        if (simbolo == simbolo2) {
          fprintf(arquivoTxt, "%c%c %c %c%c\n", initial, initial2, simbolo, destino, destino2);
        }

      }
    }

    //Calcula a intersecao do estado inicial
    char estadoInicial, estadoInicial2;
    estadoInicial = afd.estadoInicial[0];
    estadoInicial2 = afd2.estadoInicial[0];
    fprintf(arquivoTxt, "%c%c\n", estadoInicial, estadoInicial2);
    

    //Calcula a intersecao dos estados finais
    int quantidadeEstadosFinais = 0;
    for(int i = 0; i < afd.quantidades[3]; i++) {
      for(int j = 0; j < afd2.quantidades[3]; j++) {
        quantidadeEstadosFinais++;
      }
    }
    fprintf(arquivoTxt, "%d\n", quantidadeEstadosFinais);
    
    
    //Calcula a intersecao dos estados finais
    char estadoFinal, estadoFinal2;
    for(int i = 0; i < afd.quantidades[3]; i++) {
      for(int j = 0; j < afd2.quantidades[3]; j++) {
        estadoFinal = afd.estadosFinais[i][0];
        estadoFinal2 = afd2.estadosFinais[j][0];
        fprintf(arquivoTxt, "%c%c\n", estadoFinal, estadoFinal2);
      }
    }

    fclose(arquivoTxt);

};

void intersecao(int argc, char *argv[]) {
    if(argc < 6) {
        printf("Numero de argumentos invalido!");
        return;
    }
    char *arquivoEntrada = NULL;
    char *arquivoEntrada2 = NULL;
    char *arquivoSaida = NULL;

    if(strcmp(argv[1], INTERSECAO) == 0){
        arquivoEntrada = argv[2];
        arquivoEntrada2 = argv[3];
    } else {
        exit(1);
    }
    if(strcmp(argv[4], OUTPUT) == 0){
        arquivoSaida = argv[5];
    } else {
        exit(1);
    }

    AFD afd = lerArquivo(arquivoEntrada);
    AFD afd2 = lerArquivo(arquivoEntrada2);


    calcularIntersecao( afd, afd2, arquivoSaida);
}