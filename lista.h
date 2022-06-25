#ifndef LISTA_H
#define LISTA_H

typedef struct celula Celula;
typedef struct lista Lista;

#include <stdio.h>
#include "idoso.h"

/*Cria uma lista vazia
* inputs: nenhum
* output: lista alocada e vazia
* pre-condicao: nao tem
* pos-condicao: lista alocada e vazia */
Lista* inicLista();

/*Insere idoso na ultima posição da lista
* inputs: idoso que será inserido, e a lista onde ele será inserido
* output: nenhum
* pre-condicao: lista e idosos já alocados
* pos-condicao: lista com o idoso na ultima posicao */
void insereLast(Lista* lista, Idoso* idoso);

/*Retira os idosos marcados com a flag "falecido" da lista
* inputs: a lista a ser varrida
* output: nenhum
* pre-condicao: lista já alocada.
* pos-condicao: todos os idosos falecidos são retirados da lista  */
void retiraIdososFalecidos(Lista* lista);

/*Retira da lista o idoso que possuir o nome fornecido
* inputs: a lista, e o nome do idoso que será retirado
* output: nenhum
* pre-condicao: lista e nome alocados
* pos-condicao: idoso com o nome fornecido é retirado da lista */
void retiraNome(Lista* lista, char* nome);

void retiraNomeSemLiberarIdoso(Lista* lista, char* nome);

/* Retorna o Idoso da lista que possuir o nome fornecido
* inputs: a lista, e o nome do idoso
* output: o ponteiro para o idoso de nome fornecido ou NULL se não existir
* pre-condicao: lista e nome alocados
* pos-condicao: lista nao muda */
Idoso* getIdoso(Lista* lista, char* nome);

/* Retorna o Idoso da lista que estiver na posição fornecida
* inputs: a lista, e a posicao
* output: o ponteiro para o idoso que está na posição fornecida
* pre-condicao: lista alocada
* pos-condicao: lista nao muda */
Idoso* getIdosoPosicao(Lista* lista, int posicao);

/* Retorna o Idoso da lista mais próximo da posição fornecida
* inputs: a lista (de amigos), e a posicão do idoso ([latitude, longitude])
* output: o ponteiro para o amigo do idoso mais próximo da posição fornecida
* pre-condicao: lista de amigos alocada, e vetor de posição alocado
* pos-condicao: lista nao muda */
Idoso* AmigoProximoPosicao(Lista* amigos, int * posicao);

/* Retorna o ponteiro para o arquivo de entrada do idoso que se encontra na posição 'x' da lista
* inputs: a lista, e a posicao do idoso
* output: o ponteiro para o arquivo de entrada do idoso
* pre-condicao: lista alocada
* pos-condicao: lista nao muda */
FILE* getArquivoEntradaPosicao(Lista* lista, int posicao);

/* Retorna o ponteiro para o arquivo de saida do idoso que se encontra na posição 'x' da lista
* inputs: a lista, e a posicao do idoso
* output: o ponteiro para o arquivo de saida do idoso
* pre-condicao: lista alocada
* pos-condicao: lista nao muda */
FILE* getArquivoSaidaPosicao(Lista* lista, int posicao);


/* Retorna a quantidade de idosos na lista
* inputs: a lista
* output: a quantidade de idosos
* pre-condicao: lista alocada
* pos-condicao: lista nao muda */
int getQtdIdosos(Lista* lista);

/* Imprime os elementos da lista
* inputs: a lista
* output: nenhum
* pre-condicao: lista alocada
* pos-condicao: lista nao muda */
void imprimeLista(Lista* lista);

/* Libera os elementos da lista, e a lista
* inputs: a lista
* output: nenhum
* pre-condicao: lista alocada
* pos-condicao: lista e os idosos da lista são liberados, e a lista é destruida */
void liberaLista(Lista* lista);

/* Libera as células da lista de amigos de um idoso
* inputs: a lista de amigos
* output: nenhum
* pre-condicao: lista de amigos alocada
* pos-condicao: as células da lista de amigos são liberadas, sem destruir o idoso que estava naquela célula */
void liberaCelulasAmigos(Lista* lista);

#endif // LISTA_H