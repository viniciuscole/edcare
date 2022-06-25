#ifndef LISTACUIDADORES_H
#define LISTACUIDADORES_H

#include "cuidador.h"

typedef struct celulaCuidador CelulaCuidador;
typedef struct listaCuidador ListaCuidador;

/* Inicializa uma lista de cuidadores
* inputs: nenhum
* output: o ponteiro para a lista, inicializada
* pre-condicao: nenhuma
* pos-condicao: nenhuma */
ListaCuidador* inicListaCuidadores();

/* Insere um cuidador no final da lista de cuidadores
* inputs: lista de cuidadores e o cuidador
* output: nenhum
* pre-condicao: nenhuma
* pos-condicao: nenhuma */
void insereLastCuidadores(ListaCuidador* listaCuidador, Cuidador* cuidador);

/* Retorna o cuidador com o nome fornecido
* inputs: lista de cuidadores e o nome
* output: Cuidador com o nome fornecido ou NULL se não existir
* pre-condicao: nome e lista alocados
* pos-condicao: nada muda */
Cuidador* getCuidador(ListaCuidador* listaCuidador, char* nome);

/* Retorna a quantidade de cuidadores em uma lista
* inputs: lista de cuidadores
* output: numero de cuidadores na lista
* pre-condicao: lista inicializada
* pos-condicao: nada muda */
int getQtdCuidadores(ListaCuidador* listaCuidador);

/* Retorna o cuidador na posicao fornecida da lista
* inputs: lista de cuidadores e a posicao
* output: Cuidador na posição fornecida ou NULL se não existir
* pre-condicao: lista inicializada
* pos-condicao: nada muda */
Cuidador* getCuidadorPosicao(ListaCuidador* listaCuidador, int posicao);

/* Retorna o cuidador mais próximo da posição fornecida ([latitude, longitude])
* inputs: lista de cuidadores e a posicao
* output: Cuidador mais próximo da posição fornecida ou NULL se não existir
* pre-condicao: lista inicializada
* pos-condicao: nada muda */
Cuidador* cuidadorProximoPosicao(ListaCuidador* listaCuidador, int * posicao);

/* Retorna o arquivo do cuidador que se encontra na posição da lista fornecida
* inputs: lista de cuidadores e a posicao
* output: arquivo do cuidador na posicao fornecida ou NULL se não existir
* pre-condicao: lista inicializada
* pos-condicao: nada muda */
FILE* getArquivoCuidadorPosicao(ListaCuidador* listaCuidador, int posicao);

/* Caalcula a distancia entre duas posicoes ([latitude, longitude])
* inputs: posicoes
* output: distancia
* pre-condicao: nenhuma
* pos-condicao: nada muda */
double calculaDistancia(int * posicao1, int * posicao2);

/* Imprime a lista de cuidadores
* inputs: lista de cuidadores
* output: nenhum
* pre-condicao: lista de cuidadores inicializada
* pos-condicao: nada muda */
void imprimeListaCuidador(ListaCuidador* listaCuidador);

/* Libera a memoria de uma lista de cuidadores
* inputs: lista de cuidadores
* output: nenhum
* pre-condicao: lista inicializada
* pos-condicao: a lista de cuidadores e os cuidadores da lista são liberados */
void liberaListaCuidador(ListaCuidador* listaCuidador);

/* Libera as células de uma lista de cuidadores(Cuidadores de um idoso)
* inputs: lista de cuidadores
* output: nenhum
* pre-condicao: lista inicializada
* pos-condicao: a lista de cuidadores e as células da lista são liberados */
void liberaCelulasCuidadores(ListaCuidador* lista);

#endif // LISTACUIDADORES_H