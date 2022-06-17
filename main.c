#include <stdio.h>
#include <stdlib.h>
#include "edcare.h"
#include "lista.h"
#include "listaCuidadores.h"

int main(int argc, char* argv[ ]){
    if(argc<2){
        printf("Numero de leituras nao informado\n");
        return 1;
    }
    int qtdLeituras = atoi(argv[1]);

    Lista* lista = inicLista();
    ListaCuidador* listaCuidador = inicListaCuidadores();

    leRedeApoio(lista);
    leRedeCuidadores(listaCuidador, lista);
    liberaListaCuidador(listaCuidador);
    liberaLista(lista);

    return 0;
}