#include "idoso.h"
#include "cuidador.h"
#include "listaCuidadores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct celulaCuidador{
    Cuidador* cuidador;
    CelulaCuidador* prox;
};
struct listaCuidador{
    CelulaCuidador* primeiro;
    CelulaCuidador* ultimo;
};

ListaCuidador* inicListaCuidadores(){
    ListaCuidador* listaCuidador = (ListaCuidador*)malloc(sizeof(ListaCuidador));
    listaCuidador->primeiro=NULL;
    listaCuidador->ultimo=NULL;
    return listaCuidador;
};
void insereLastCuidadores(ListaCuidador* listaCuidador, Cuidador* cuidador){
    CelulaCuidador* nova = (CelulaCuidador*)malloc(sizeof(CelulaCuidador));
    nova->prox=NULL;
    nova->cuidador= cuidador;
    if(listaCuidador->primeiro==NULL){
        listaCuidador->primeiro=nova;
        listaCuidador->ultimo=nova;
        return;
    }

    listaCuidador->ultimo->prox=nova;
    listaCuidador->ultimo=nova;
    return;
}
Cuidador* getCuidador(ListaCuidador* listaCuidador, char* nome){
    CelulaCuidador* p = listaCuidador->primeiro;
    while(p && strcmp(nome, getNomeCuidador(p->cuidador))!=0){
        p=p->prox;
    }
    if(!p){
        return NULL;
    }
    return p->cuidador;
}
void imprimeListaCuidador(ListaCuidador* listaCuidador){
    CelulaCuidador* p;
    for(p=listaCuidador->primeiro; p!=NULL; p=p->prox){
        printf("%s\n", getNomeCuidador(p->cuidador));
    }
    free(p);
}
void liberaListaCuidador(ListaCuidador* listaCuidador){
    CelulaCuidador* p = listaCuidador->primeiro;
    while(p){
        CelulaCuidador* aux = p->prox;
        liberaCuidador(p->cuidador);
        free(p);
        p=aux;
    }
    free(listaCuidador);
}
void liberaCelulasCuidadores(ListaCuidador* lista){
    CelulaCuidador* p = lista->primeiro;
    CelulaCuidador* temp = NULL;
    while(p){
        temp=p->prox;
        free(p);
        p=temp;
    }
    free(lista); 
};
