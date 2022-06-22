#ifndef LISTA_H
#define LISTA_H

typedef struct celula Celula;
typedef struct lista Lista;

#include <stdio.h>
#include "idoso.h"

Lista* inicLista();
void insereLast(Lista* lista, Idoso* idoso);
void retiraIdososFalecidos(Lista* lista);
void retiraNome(Lista* lista, char* nome);
Idoso* getIdoso(Lista* lista, char* nome);
Idoso* getIdosoPosicao(Lista* lista, int posicao);
Idoso* AmigoProximoPosicao(Lista* amigos, int * posicao);
FILE* getArquivoEntradaPosicao(Lista* lista, int posicao);
FILE* getArquivoSaidaPosicao(Lista* lista, int posicao);
int getQtdIdosos(Lista* lista);
void imprimeLista(Lista* lista);
void liberaLista(Lista* lista);
void liberaCelulasAmigos(Lista* lista);

#endif // LISTA_H