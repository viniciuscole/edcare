#ifndef IDOSO_H
#define IDOSO_H

typedef struct idoso Idoso;

#include "listaCuidadores.h"
#include "lista.h"
#include "cuidador.h"


Idoso* inicializaIdoso(char* nome);
void addAmigo(Idoso* idoso1, Idoso* idoso2);
char* getNome(Idoso* idoso);
ListaCuidador* getListaCuidador(Idoso* idoso);
Lista* getListaAmigos(Idoso* idoso);
void addCuidador(Idoso* idoso,Cuidador* cuidador);
void imprimeAmigos(Idoso* idoso);
void imprimeCuidador(Idoso* idoso);
void liberaIdoso(Idoso* idoso);


#endif // IDOSO_H