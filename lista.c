#include "lista.h"
#include "idoso.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula{
    Idoso* idoso;
    Celula* prox;
};

struct lista{
    Celula* primeiro;
    Celula* ultimo;
};

Lista* inicLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro=NULL;
    lista->ultimo=NULL;
    return lista;
};
void insereLast(Lista* lista, Idoso* idoso){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->prox=NULL;
    nova->idoso= idoso;
    if(lista->primeiro==NULL){
        lista->primeiro=nova;
        lista->ultimo=nova;
        return;
    }

    lista->ultimo->prox=nova;
    lista->ultimo=nova;
};
void retiraNome(Lista* lista, char* nome){
    Celula* anterior=NULL;
    Celula* p = lista->primeiro;
    while(p && strcmp(nome, getNome(p->idoso))!=0){
        anterior=p;
        p=p->prox;
    }
    if(!p){
        printf("Não foi encontrado\n");
    }
    if(p==lista->primeiro && p==lista->ultimo){
        lista->primeiro = lista->ultimo = NULL;
        liberaIdoso(p->idoso);
        free(p);
        return;
    }
    if(p==lista->ultimo){
        lista->ultimo = anterior;
        anterior->prox=NULL;
        liberaIdoso(p->idoso);
        free(p);
        return;
    }
    if(p==lista->primeiro){
        lista->primeiro = p->prox;
    }
    else{
        anterior->prox = p->prox;
    }
    liberaIdoso(p->idoso);
    free(p);
}
Idoso* getIdoso(Lista* lista, char* nome){
    Celula* p = lista->primeiro;
    while(p && strcmp(nome, getNome(p->idoso))!=0){
        p=p->prox;
    }
    if(!p){
        printf("Não foi encontrado idoso %s\n", nome);
        exit(1);
    }
    return p->idoso;
}
void imprimeLista(Lista* lista){
    Celula* p=lista->primeiro;
    for(p=lista->primeiro; p!=NULL; p=p->prox){
        printf("%s\n", getNome(p->idoso));
    }
    free(p);
};
void liberaLista(Lista* lista){
    Celula* p = lista->primeiro;
    Celula* temp = NULL;
    while(p){
        temp=p->prox;
        liberaIdoso(p->idoso);
        free(p);
        p=temp;
    }
    free(temp);
    free(lista); 
};