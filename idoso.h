#ifndef IDOSO_H
#define IDOSO_H

typedef struct idoso Idoso;

#include "listaCuidadores.h"
#include "lista.h"
#include "cuidador.h"

/* inicializa um idoso com o nome fornecido
* inputs: o nome
* output: o idoso, inicializado
* pre-condicao: nome já alocado
* pos-condicao: idoso alocado */
Idoso* inicializaIdoso(char* nome);

/* adiciona o idoso1 à lista de amigos do idoso2, e vice-versa
* inputs: os dois idosos
* output: nenhum
* pre-condicao: idosos já inicializados
* pos-condicao: idoso possuem um ao outro na lista de amigos */
void addAmigo(Idoso* idoso1, Idoso* idoso2);

/* retorna se idoso1 e idoso2 sao amigos
* inputs: os idosos
* output: 1 - sao amigos / 0 - nao sao amigos
* pre-condicao: idosos inicializados
* pos-condicao: nada muda */
int ehAmigo(Idoso* idoso1, Idoso* idoso2);

/* abre o arquivo de entrada do idoso e retorna o ponteiro para o arquivo
* inputs: o idoso, e o nome do arquivo de entrada
* output: o ponteiro para o arquivo
* pre-condicao: idoso inicializado e nome já alocado
* pos-condicao: O ponteiro para o arquivo de entrada do idoso agora é um arquivo aberto para leitura */
FILE* abreArquivoEntrada(Idoso* idoso, char *nomeArquivo);

/* abre o arquivo de entrada do idoso e retorna o ponteiro para o arquivo
* inputs: o idoso, e o nome do arquivo de saida
* output: o ponteiro para o arquivo
* pre-condicao: idoso inicializado e nome já alocado
* pos-condicao: O ponteiro para o arquivo de saida do idoso agora é um arquivo aberto para escrita */
FILE* abreArquivoSaida(Idoso* idoso, char *nomeArquivo);

/* fecha o arquivo de entrada do idoso
* inputs: o idoso
* output: nada
* pre-condicao: idoso inicializado, com um arquivo já aberto
* pos-condicao: O arquivo é fechado */
void fechaArquivoEntrada(Idoso* idoso);

/* fecha o arquivo de saida do idoso
* inputs: o idoso
* output: nada
* pre-condicao: idoso inicializado, com um arquivo já aberto
* pos-condicao: O arquivo é fechado */
void fechaArquivoSaida(Idoso* idoso);

/* retorna o nome do idoso
* inputs: o idoso
* output: o nome do idoso
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
char* getNome(Idoso* idoso);

/* retorna a posicao ([latitude, longitude]) do idoso
* inputs: o idoso
* output: o vetor [lat, long] dele
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
int* getPosicaoIdosos(Idoso* idoso);

/* retorna o cuidador da lista de cuidadores de um idoso
* mais proximo dele no momento
* inputs: o idoso
* output: o cuidador do idoso que está mais proximo dele
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
Cuidador* getCuidadorProximo(Idoso* idoso);

/* retorna o amigo da lista de amigos de um idoso
* mais proximo dele no momento
* inputs: o idoso
* output: o amigo do idoso que está mais proximo dele
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
Idoso* getAmigoProximo(Idoso* idoso);

/* atualiza as condições de um idoso
* inputs: o idoso, e as informações a serem atualizadas
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: idoso tem sua temperatura, posição e status de queda atualizados */
void atualizaIdoso(Idoso* idoso, float temperatura, int lat, int lon, int queda);

/* retorna a situação de um idoso
* inputs: o idoso
* output: 4 - queda / 3 - febre alta / 2 - quatro febres baixas seguidas / 1 - febre baixa / 0 - normal
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
int situacaoIdoso(Idoso* idoso);

void retiraListaAmigos(Idoso* idoso);

/* muda a flag de falecido de um idoso
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: idoso tem sua flag de falecido mudada para 1 */
void atualizaIdosoFalecimento(Idoso* idoso);

/* retorna a lista de cuidadores de um idoso
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
ListaCuidador* getListaCuidador(Idoso* idoso);

/* retorna a lista de amigos de um idoso
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
Lista* getListaAmigos(Idoso* idoso);

/* retorna o arquivo de entrada de um idoso
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
FILE* getArquivoEntrada(Idoso* idoso);

/* retorna o arquivo de saida de um idoso
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
FILE* getArquivoSaida(Idoso* idoso);

/* retorna o status de falecido de um idoso
* inputs: o idoso
* output: se a flag de falecido é 1 ou não
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
int idosoFalecido(Idoso* idoso);

/* Aciciona um cuidador à lista de cuidadores de um idoso
* inputs: o idoso e o cuidador
* output: nenhum
* pre-condicao: idoso inicializado e cuidador inicializado
* pos-condicao: cuidador é inserido na lista de cuidadores do idoso */
void addCuidador(Idoso* idoso,Cuidador* cuidador);

/* Imprime os amigos de um idoso (para debug)
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
void imprimeAmigos(Idoso* idoso);

/* Imprime os cuidadores de um idoso (para debug)
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: nada muda */
void imprimeCuidador(Idoso* idoso);

/* libera os espaços de memória alocados para um idoso
* inputs: o idoso
* output: nenhum
* pre-condicao: idoso inicializado
* pos-condicao: espaços de memória do idoso são liberados */
void liberaIdoso(Idoso* idoso);


#endif // IDOSO_H