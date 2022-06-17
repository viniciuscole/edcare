#include "cuidador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cuidador
{
    char* nome;
    int posicao[2];
};

Cuidador* inicializaCuidador(char* nome){
    Cuidador* aux = (Cuidador*) malloc(sizeof(Cuidador));
    aux->nome = strdup(nome);
    aux->posicao[0] = 0;
    aux->posicao[1] = 0;
    return aux;
}
char* getNomeCuidador(Cuidador* cuidador){
    return cuidador->nome;
}
void liberaCuidador(Cuidador* cuidador){
    free(cuidador->nome);
    free(cuidador);
}
