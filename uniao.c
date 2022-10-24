#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"
#include "visualizacao.h"
#include "uniao.h"

#define UNIAO "--uniao"
#define OUTPUT "--output"

void calcularUniao(AFD afd, AFD afd2, char *nomeArquivo) {
    FILE *arquivoTxt;
    arquivoTxt = fopen(nomeArquivo, "w");
    
    AFD afd3;
    afd3.quantidades[3] = 0;
    int quantidadeTotalEstados = afd.quantidades[0] + afd2.quantidades[0];
    char estadoFinal, estadoFinal2, compare, compare2;
    fprintf(arquivoTxt, "%d\n", quantidadeTotalEstados);
    for(int i = 0; i < afd.quantidades[0]; i++) {
        for(int j = 0; j < afd2.quantidades[0]; j++) {
          char *estado1 = strtok(afd.estados[i], "\n");
          char *estado2 = strtok(afd2.estados[j], "\n");
          fprintf(arquivoTxt, "%s%s\n", afd.estados[i], afd2.estados[j]);
          for (int k = 0; k < afd.quantidades[3]; k++) {
          for (int l = 0; l < afd2.quantidades[3]; l++) {
            estadoFinal = afd.estadosFinais[k][0];
            estadoFinal2 = afd2.estadosFinais[l][0];
            compare = afd.estados[i][0];
            compare2 = afd2.estados[j][0];
            if (estadoFinal == compare || estadoFinal == compare || estadoFinal2 == compare2) {
              //Concat compare and compare2
              char *estadoConcat = malloc(2);
              estadoConcat[0] = compare;
              estadoConcat[1] = compare2;
              estadoConcat[2] = '\0';
              afd3.estadosFinais[afd3.quantidades[3]][0] = estadoConcat[0];
              afd3.estadosFinais[afd3.quantidades[3]][1] = estadoConcat[1];
              printf("ESTADO FINAL ==> %s\n", afd3.estadosFinais[afd3.quantidades[3]]);
              afd3.quantidades[3]++;

            }
          }
        }
        }
    }
    fprintf(arquivoTxt, "%d\n", afd.quantidades[1]);
    for(int i = 0; i < afd.quantidades[1]; i++) {
        fputs(afd.alfabeto[i], arquivoTxt);
    }

    fprintf(arquivoTxt, "%d\n", afd.quantidades[1] * quantidadeTotalEstados);
    
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

    char estadoInicial, estadoInicial2;
    estadoInicial = afd.estadoInicial[0];
    estadoInicial2 = afd2.estadoInicial[0];
    fprintf(arquivoTxt, "%c%c\n", estadoInicial, estadoInicial2);
    
    int quantidadeEstadosFinais = 0;
    
    for(int i = 0; i < afd.quantidades[3]; i++) {
      for(int j = 0; j < afd2.quantidades[3]; j++) {
        quantidadeEstadosFinais++;
      }
    }


    // char estadoFinal, estadoFinal2;
    //Print afd3 estadosFinais
    // for(int i = 0; i < afd.quantidades[0]; i++) {
    //   for(int j = 0; j < afd2.quantidades[0]; j++) {
        
    //   }
    // }
    fprintf(arquivoTxt, "%d\n", afd3.quantidades[3]);
    for(int i = 0; i < afd3.quantidades[3]; i++) {
      fprintf(arquivoTxt, "%s\n", afd3.estadosFinais[i]);
    }


    fclose(arquivoTxt);

};

void uniao(int argc, char *argv[]) {
    printf("UNIAO");

    if(argc < 6) {
        printf("Numero de argumentos invalido!");
        return;
    }
    char *arquivoEntrada = NULL;
    char *arquivoEntrada2 = NULL;
    char *arquivoSaida = NULL;

    if(strcmp(argv[1], UNIAO) == 0){
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

    printf("UNIAO");
    calcularUniao( afd, afd2, arquivoSaida);
}