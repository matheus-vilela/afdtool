#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "afd.h"
#include "reconhecer.h"

#define RECONHECER "--reconhecer"
#define OUTPUT "--output"


PALAVRAS lerArquivoPalavras(char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de palavras!\n");
        exit(1);
    }

    PALAVRAS palavras;


    char linha[50];

    //Lendo quantidade e palavras
    int i = 0;
    while(fgets(linha, 50, arquivo) != NULL){
        strcpy(palavras.palavras[i], strtok(linha, " \n"));
        i++;
    }
    palavras.quantidade = i;

    fclose(arquivo);
    return palavras;
}

int reconhecerPalavra(AFD afd, char *palavra){
    char *estadoInicial = malloc(sizeof(char) * 50);
    estadoInicial = afd.estadoInicial;

    int quantidadeDeSimbolos = strlen(palavra);
    printf("\n\nPALAVRA RECEBIDA: %s\n", palavra);
    printf("Quantidade de simbolos: %d\n\n", quantidadeDeSimbolos);

    TRANSICAO transicaoDividida;
    
    for(int i = 0; i < quantidadeDeSimbolos; i++){
        printf("SIMBOLO: %c\n", palavra[i]);

        for(int j = 0; j < afd.quantidades[2]; j++){

            char transicao[50];
            strcpy(transicao, afd.transicoes[j]);

            transicaoDividida = dividirTransicao(transicao);
            
            if(strcmp(strtok(estadoInicial, "\n"), strtok(transicaoDividida.entrada, "\n")) == 0 && palavra[i] == transicaoDividida.simbolo[0]){
                printf("Lendo %s ==> DESTINO %s", transicaoDividida.simbolo, transicaoDividida.saida);
                strcpy(estadoInicial, transicaoDividida.saida);
                printf("NOVO ESTADO FINAL: %s\n", estadoInicial);
                j = afd.quantidades[2];
            }
        }

    }
    
    for(int i = 0; i < afd.quantidades[3]; i++){
        if(strcmp(strtok(estadoInicial, "\n"), strtok(afd.estadosFinais[i], "\n")) == 0){
            printf("RECONHECIDA!\n");

            return 1;
        }
    }

    printf("NÃO RECONHECIDA!\n");
    return 0;
}

void conhecerPalavra(char *nomeArquivo, PALAVRAS palavras, AFD afd){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de saida!\n");
        exit(1);
    }

    for(int i =0; i < palavras.quantidade; i++){
        if(reconhecerPalavra(afd, palavras.palavras[i])){
            fprintf(arquivo, "1\n");
        }else{
            fprintf(arquivo, "0\n");
        }
    }

    fclose(arquivo);
}

void reconhecer(int argc, char *argv[]) {
    if(argc < 6) {
        printf("Numero de argumentos invalido!");
        return;
    }
    char *arquivoEntrada = NULL;
    char *arquivoPalavra = NULL;
    char *arquivoSaida = NULL;

    if(strcmp(argv[1], RECONHECER) == 0){
        arquivoEntrada = argv[2];
        arquivoPalavra = argv[3];
    } else {
        exit(1);
    }
    if(strcmp(argv[4], OUTPUT) == 0){
        arquivoSaida = argv[5];
    } else {
        exit(1);
    }

    AFD afd = lerArquivo(arquivoEntrada);
    PALAVRAS palavras = lerArquivoPalavras(arquivoPalavra);

    conhecerPalavra(arquivoSaida, palavras, afd);
   


}