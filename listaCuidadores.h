#ifndef LISTACUIDADORES_H
#define LISTACUIDADORES_H

#include "cuidador.h"

typedef struct celulaCuidador CelulaCuidador;
typedef struct listaCuidador ListaCuidador;


ListaCuidador* inicListaCuidadores();
void insereLastCuidadores(ListaCuidador* listaCuidador, Cuidador* cuidador);
Cuidador* getCuidador(ListaCuidador* listaCuidador, char* nome);
int getQtdCuidadores(ListaCuidador* listaCuidador);
Cuidador* getCuidadorPosicao(ListaCuidador* listaCuidador, int posicao);
Cuidador* cuidadorProximoPosicao(ListaCuidador* listaCuidador, int * posicao);
FILE* getArquivoCuidadorPosicao(ListaCuidador* listaCuidador, int posicao);
double calculaDistancia(int * posicao1, int * posicao2);
void imprimeListaCuidador(ListaCuidador* listaCuidador);
void liberaListaCuidador(ListaCuidador* listaCuidador);
void liberaCelulasCuidadores(ListaCuidador* lista);

#endif // LISTACUIDADORES_H