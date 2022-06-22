#include "cuidador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cuidador
{
    char* nome;
    int posicao[2];
    FILE* arquivo;
};

Cuidador* inicializaCuidador(char* nome){
    Cuidador* aux = (Cuidador*) malloc(sizeof(Cuidador));
    aux->nome = strdup(nome);
    aux->posicao[0] = 0;
    aux->posicao[1] = 0;
    aux->arquivo = NULL;
    return aux;
}
void atualizaCuidador(Cuidador* cuidador, int lat, int lon){
    cuidador->posicao[0] = lat;
    cuidador->posicao[1] = lon;
}
FILE* abreArquivoCuidador(Cuidador* cuidador, char* nomeArquivo){
    FILE* arquivo = fopen(nomeArquivo, "r");
    cuidador->arquivo = arquivo;
    return arquivo;
}
char* getNomeCuidador(Cuidador* cuidador){
    return cuidador->nome;
}
int* getPosicaoCuidador(Cuidador* cuidador){
    return cuidador->posicao;
}
FILE* getArquivoCuidador(Cuidador* cuidador){
    return cuidador->arquivo;
}
void liberaCuidador(Cuidador* cuidador){
    free(cuidador->nome);
    free(cuidador);
}
void fechaArquivoCuidador(Cuidador* cuidador){
    fclose(cuidador->arquivo);
}
