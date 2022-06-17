#ifndef IDOSO_H
#define IDOSO_H

#include "listaCuidadores.h"
#include "cuidador.h"

typedef struct idoso Idoso;

Idoso* inicializaIdoso(char* nome);
void addAmigo(Idoso* idoso1, Idoso* idoso2);
char* getNome(Idoso* idoso);
ListaCuidador* getListaCuidador(Idoso* idoso);
void addCuidador(Idoso* idoso,Cuidador* cuidador);
void printaAmigos(Idoso* idoso);
void liberaIdoso(Idoso* idoso);

#endif // IDOSO_H