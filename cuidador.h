#ifndef CUIDADOR_H
#define CUIDADOR_H

typedef struct cuidador Cuidador;

#include <stdio.h>

Cuidador* inicializaCuidador(char* nome);
void atualizaCuidador(Cuidador* cuidador, int lat, int lon);
FILE* abreArquivoCuidador(Cuidador* cuidador, char* nomeArquivo);
char* getNomeCuidador(Cuidador* cuidador);
int* getPosicaoCuidador(Cuidador* cuidador);
FILE* getArquivoCuidador(Cuidador* cuidador);
void liberaCuidador(Cuidador* cuidador);
void fechaArquivoCuidador(Cuidador* cuidador);

#endif // CUIDADOR_H