#ifndef CUIDADOR_H
#define CUIDADOR_H

typedef struct cuidador Cuidador;

#include <stdio.h>

/* Inicializa um cuidador com o nome fornecido
* inputs: nome do cuidador
* output: ponteiro para o cuidador inicializado
* pre-condicao: nenhum
* pos-condicao: Cuidador alocado com o nome fornecido*/
Cuidador* inicializaCuidador(char* nome);

/* Atualiza a posição do cuidador ([lat, long])
* inputs: Cuidador e a posicao
* output: nenhum
* pre-condicao: p
* pos-condicao: Cuidador alocado com o nome fornecido*/
void atualizaCuidador(Cuidador* cuidador, int lat, int lon);

/* Abre o arquivo do cuidador
* inputs: Cuidador e o nome do arquivo
* output: o ponteiro para o arquivo
* pre-condicao: Cuidador alocado, e arquivo existente
* pos-condicao: Arquivo de nome fornecido é aberto para leitura*/
FILE* abreArquivoCuidador(Cuidador* cuidador, char* nomeArquivo);

/* Retorna o nome do cuidador
* inputs: Cuidador
* output: nome do cuidador
* pre-condicao: Cuidador alocado
* pos-condicao: nenhuma*/
char* getNomeCuidador(Cuidador* cuidador);

/* Retorna a posição ([lat, long]) do cuidador
* inputs: Cuidador
* output: posição do cuidador
* pre-condicao: Cuidador alocado
* pos-condicao: nenhuma*/
int* getPosicaoCuidador(Cuidador* cuidador);

/* Retorna o arquivo do cuidador
* inputs: Cuidador
* output: ponteiro para o arquivo do cuidador
* pre-condicao: Cuidador alocado e arquivo aberto
* pos-condicao: nenhuma*/
FILE* getArquivoCuidador(Cuidador* cuidador);

/* Libera a memória alocada para o cuidador
* inputs: Cuidador
* output: nenhum
* pre-condicao: Cuidador alocado
* pos-condicao: Memória liberada*/
void liberaCuidador(Cuidador* cuidador);

/* Fecha o arquivo do cuidador
* inputs: Cuidador
* output: nenhum
* pre-condicao: Cuidador alocado
* pos-condicao: nenhuma*/
void fechaArquivoCuidador(Cuidador* cuidador);

#endif // CUIDADOR_H