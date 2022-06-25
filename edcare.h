#ifndef EDCARE_H
#define EDCARE_H
#include "lista.h"
#include "listaCuidadores.h"

/* Lê e interpreta o arquivo apoio.txt, inserindo na lista fornecida
* os idosos e criando a rede de amizade
* inputs: a lista
* output: nenhum
* pre-condicao: lista alocada
* pos-condicao: idosos são adicionados na lista, com sua lista de amigos */

void leRedeApoio(Lista* lista);
/* Lê e interpreta o arquivo cuidadores.txt, inserindo na lista de
* cuidadores fornecida os cuidadores. Além disso, os cuidadores são
* adicionados na lista de cuidadores de cada idoso.
* inputs: a lista de idosos e a lista de cuidadores
* output: nenhum
* pre-condicao: ambas as listas devem estar alocadas
* pos-condicao: cuidadores são adicionados na lista de cuidadores,
* e também na rede de cuidadores de cada idoso               */
void leRedeCuidadores(ListaCuidador* listaCuidador, Lista* listaIdosos);

/* Executa o edCare, lendo os arquivos de entrada de cada idoso e de cada cuidador,
* atualizando a situação deles e escrevendo o arquivo de saída.
* inputs: a lista de idosos, a lista de cuidadores e a quantidade de leituras
* output: nenhum
* pre-condicao: listas alocadas
* pos-condicao: idosos falecidos são liberados das listas. Arquivos de saida são gerados */
void leSensores(Lista* listaIdosos, ListaCuidador* listaCuidadores, int qtdLeituras);

#endif // EDCARE_H