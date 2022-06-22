#ifndef IDOSO_H
#define IDOSO_H

typedef struct idoso Idoso;

#include "listaCuidadores.h"
#include "lista.h"
#include "cuidador.h"


Idoso* inicializaIdoso(char* nome);
void addAmigo(Idoso* idoso1, Idoso* idoso2);
FILE* abreArquivoEntrada(Idoso* idoso, char *nomeArquivo);
FILE* abreArquivoSaida(Idoso* idoso, char *nomeArquivo);
void fechaArquivoEntrada(Idoso* idoso);
void fechaArquivoSaida(Idoso* idoso);
char* getNome(Idoso* idoso);
int* getPosicaoIdosos(Idoso* idoso);
Cuidador* getCuidadorProximo(Idoso* idoso);
Idoso* getAmigoProximo(Idoso* idoso);
int atualizaIdoso(Idoso* idoso, float temperatura, int lat, int lon, int queda);
ListaCuidador* getListaCuidador(Idoso* idoso);
Lista* getListaAmigos(Idoso* idoso);
FILE* getArquivoEntrada(Idoso* idoso);
FILE* getArquivoSaida(Idoso* idoso);
void addCuidador(Idoso* idoso,Cuidador* cuidador);
void imprimeAmigos(Idoso* idoso);
void imprimeCuidador(Idoso* idoso);
void liberaIdoso(Idoso* idoso);


#endif // IDOSO_H