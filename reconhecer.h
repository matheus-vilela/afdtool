#ifndef __RECONHECER_H__
#define __RECONHECER_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct palavras {
    char palavras[50][50];
    int quantidade;

} PALAVRAS;

void reconhecer(int argc, char *argv[]);

#endif