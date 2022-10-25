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

    TRANSICAO transicao1; 
    TRANSICAO transicao2;

    for (int i = 0; i < afd.quantidades[2]; i++) {
      char transicao_1[50];
      strcpy(transicao_1, afd.transicoes[i]);
      transicao1 = dividirTransicao(transicao_1);

      for(int j = 0; j < afd2.quantidades[2]; j++) {
        char transicao_2[50];
        strcpy(transicao_2, afd2.transicoes[j]);
        transicao2 = dividirTransicao(transicao_2);

        if (strcmp(strtok(transicao1.simbolo, "\n"), strtok(transicao2.simbolo, "\n")) == 0) {
          fprintf(arquivoTxt, "%s%s %s %s%s\n", strtok(transicao1.entrada, "\n"), strtok(transicao2.entrada, "\n"), strtok(transicao1.simbolo, "\n"), strtok(transicao1.saida, "\n"), strtok(transicao2.saida, "\n"));
        }

      }
    }

    //Calcula a intersecao do estado inicial
    fprintf(arquivoTxt, "%s%s\n", strtok(afd.estadoInicial, "\n"), strtok(afd2.estadoInicial, "\n"));
    

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
        fprintf(arquivoTxt, "%s%s\n", strtok(afd.estadosFinais[i], "\n"), strtok(afd2.estadosFinais[j], "\n"));
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