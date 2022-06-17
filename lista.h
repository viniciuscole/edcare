#ifndef LISTA_H
#define LISTA_H

typedef struct celula Celula;
typedef struct lista Lista;

#include "idoso.h"

Lista* inicLista();
void insereLast(Lista* lista, Idoso* idoso);
void retiraNome(Lista* lista, char* nome);
Idoso* getIdoso(Lista* lista, char* nome);
void imprimeLista(Lista* lista);
void liberaLista(Lista* lista);
void liberaCelulasAmigos(Lista* lista);

#endif // LISTA_H