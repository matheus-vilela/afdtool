#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"

TRANSICAO dividirTransicao(char *transicao) {
    TRANSICAO transicaoDividida;
    char *parte = strtok(transicao, " ");
    int i = 0;
    while (parte != NULL) {
        if(i == 0) {
            strcpy(transicaoDividida.entrada, parte);
        } else if(i == 1) {
            strcpy(transicaoDividida.simbolo, parte);
        } else if(i == 2) {
            strcpy(transicaoDividida.saida, parte);
        }
        parte = strtok(NULL, " ");
        i++;
    }

    return transicaoDividida;
}

void imprimirAFD(AFD afd) {
    printf("################################################ \n");
    printf("AFD: \n\n");
    printf("Estados: \n");
    for(int i = 0; i < afd.quantidades[0]; i++) {
        printf("%s", afd.estados[i]);
    }
    printf("\n");

    printf("Alfabeto: \n");
    for(int i = 0; i < afd.quantidades[1]; i++) {
        printf("%s", afd.alfabeto[i]);
    }

    printf("\nTransicoes: \n");
    for(int i = 0; i < afd.quantidades[2]; i++) {
        printf("%s", afd.transicoes[i]);
    }

    printf("\nEstado inicial: \n%s", afd.estadoInicial);

    printf("\nEstados finais: \n");
    for(int i = 0; i < afd.quantidades[3]; i++) {
        printf("%s", afd.estadosFinais[i]);
    }
    printf("\n################################################ \n");
    printf("\n\n");
}

AFD lerArquivo(char *afdArquivo) {
    FILE *arquivo = fopen(afdArquivo, "r");
    if(arquivo == NULL) {
        printf("Erro ao ler o afd => %s\n", afdArquivo);
        exit(1);
    }

    printf("\nLendo estados, alfabeto e transicoes...");
    AFD afd;


    char linha[50];

    //Lendo quantidade e estados
    fgets(linha, 50, arquivo);
    afd.quantidades[0] = atoi(linha);
    for(int i = 0; i < afd.quantidades[0]; i++) {
      fgets(linha, 50, arquivo);
      strcpy(afd.estados[i], linha);
    }

    //Lendo quantidade e alfabeto
    fgets(linha, 50, arquivo);
    afd.quantidades[1] = atoi(linha);
    for(int i = 0; i < afd.quantidades[1]; i++) {
        fgets(linha, 50, arquivo);
        strcpy(afd.alfabeto[i], linha);
    }

    //Lendo quantidade e transicoes
    fgets(linha, 50, arquivo);
    afd.quantidades[2] = atoi(linha);
    for(int i = 0; i < afd.quantidades[2]; i++) {
        fgets(linha, 50, arquivo);
        strcpy(afd.transicoes[i], linha);
    }

    //Lendo estado inicial
    fgets(linha, 50, arquivo);
    strcpy(afd.estadoInicial, linha);

    //Lendo quantidade e estados finais
    fgets(linha, 50, arquivo);
    afd.quantidades[3] = atoi(linha);
    for(int i = 0; i < afd.quantidades[3]; i++) {
        fgets(linha, 50, arquivo);
        strcpy(afd.estadosFinais[i], linha);
    }
    
    printf("\n\n");
    imprimirAFD(afd);
    fclose(arquivo);

    return afd;

}




