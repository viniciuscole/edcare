#include "idoso.h"
#include "lista.h"
#include "cuidador.h"
#include "listaCuidadores.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct idoso{
    char* nome;
    int posicao[2];
    float temperatura;
    int queda;
    Lista* amigos;
    ListaCuidador* cuidadores;
};

Idoso* inicializaIdoso(char* nome){
    Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->posicao[0] = 0;
    idoso->posicao[1] = 0;
    idoso->temperatura = 0;
    idoso->queda = 0;
    idoso->amigos = inicLista();
    idoso->cuidadores = inicListaCuidadores();
    return idoso;
};

void addAmigo(Idoso* idoso1, Idoso* idoso2){
    insereLast(idoso1->amigos, idoso2);
};

char* getNome(Idoso* idoso){
    return idoso->nome;
}

ListaCuidador* getListaCuidador(Idoso* idoso){
    return idoso->cuidadores;
}

void addCuidador(Idoso* idoso, Cuidador* cuidador){
    Cuidador* aux = getCuidador(getListaCuidador(idoso), getNomeCuidador(cuidador));  //checa se já existe o cuidador na lista
    printf("lista cuidadores: ");
    imprimeListaCuidador(getListaCuidador(idoso));
    if(aux==NULL){
        insereLastCuidadores(getListaCuidador(idoso), cuidador);
    }
}

void printaAmigos(Idoso* idoso){
    imprimeLista(idoso->amigos);
};

void liberaIdoso(Idoso* idoso){
    free(idoso->nome);
    liberaLista(idoso->amigos);
    free(idoso);
}