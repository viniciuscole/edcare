#ifndef LISTACUIDADORES_H
#define LISTACUIDADORES_H

#include "cuidador.h"

typedef struct celulaCuidador CelulaCuidador;
typedef struct listaCuidador ListaCuidador;


ListaCuidador* inicListaCuidadores();
void insereLastCuidadores(ListaCuidador* listaCuidador, Cuidador* cuidador);
Cuidador* getCuidador(ListaCuidador* listaCuidador, char* nome);
void imprimeListaCuidador(ListaCuidador* listaCuidador);
void liberaListaCuidador(ListaCuidador* listaCuidador);

#endif // LISTACUIDADORES_H