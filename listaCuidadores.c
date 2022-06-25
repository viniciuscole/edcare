#include "idoso.h"
#include "cuidador.h"
#include "listaCuidadores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
void insereLastCuidadores(ListaCuidador* listaCuidador, Cuidador* cuidador){    //insere no final da lista de cuidadores um cuidador
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
Cuidador* getCuidador(ListaCuidador* listaCuidador, char* nome){             //retorna o cuidador com o nome fornecido
    CelulaCuidador* p = listaCuidador->primeiro;
    while(p && strcmp(nome, getNomeCuidador(p->cuidador))!=0){
        p=p->prox;
    }
    if(!p){
        return NULL;
    }
    return p->cuidador;
}
int getQtdCuidadores(ListaCuidador* listaCuidador){
    int qtd=0;
    CelulaCuidador* p = listaCuidador->primeiro;
    while(p){
        qtd++;
        p=p->prox;
    }
    return qtd;
}
Cuidador* getCuidadorPosicao(ListaCuidador* listaCuidador, int posicao){     //retorna o cuidador na posicao fornecida
    int i=0;
    CelulaCuidador* p = listaCuidador->primeiro;
    while(p && i<posicao){
        p=p->prox;
        i++;
    }
    if(!p){
        return NULL;
    }
    return p->cuidador;
}
Cuidador* cuidadorProximoPosicao(ListaCuidador* listaCuidador, int * posicao){   //retorna o cuidador mais proximo da posicao fornecida
    CelulaCuidador* p = listaCuidador->primeiro;
    CelulaCuidador* aux;
    double distancia, min;
    while(p){
        distancia=calculaDistancia(getPosicaoCuidador(p->cuidador), posicao);
        if(p==listaCuidador->primeiro){
            min=distancia;
            aux=p;
        }
        if(distancia<min){
            min=distancia;
            aux=p;
        }
        p=p->prox;
    }
    return aux->cuidador;
}
double calculaDistancia(int * posicao1, int * posicao2){
    return sqrt(pow(posicao1[0]-posicao2[0],2)+pow(posicao1[1]-posicao2[1],2)); // sqrt((x1-x2)^2+(y1-y2)^2)
}
FILE* getArquivoCuidadorPosicao(ListaCuidador* lista, int posicao){
    CelulaCuidador* p = lista->primeiro;
    int i=0;
    while(p && i<posicao){
        p=p->prox;
        i++;
    }
    if(!p){
        printf("Não foi encontrado cuidador na posição %d\n", posicao);
        exit(1);
    }
    return getArquivoCuidador(p->cuidador);
}
void imprimeListaCuidador(ListaCuidador* listaCuidador){                    //imprime todos os cuidadores da lista
    CelulaCuidador* p;                                                      //para debug
    for(p=listaCuidador->primeiro; p!=NULL; p=p->prox){
        printf("%s\n", getNomeCuidador(p->cuidador));
    }
    free(p);
}
void liberaListaCuidador(ListaCuidador* listaCuidador){                     //libera todos os cuidadores da lista, bem como a lista em si
    CelulaCuidador* p = listaCuidador->primeiro;
    while(p){
        CelulaCuidador* aux = p->prox;
        liberaCuidador(p->cuidador);
        free(p);
        p=aux;
    }
    free(listaCuidador);
}
void liberaCelulasCuidadores(ListaCuidador* lista){                         //libera os cuidadores de uma lista de cuidadores, sem liberar o cuidador em si
    CelulaCuidador* p = lista->primeiro;
    CelulaCuidador* temp = NULL;
    while(p){
        temp=p->prox;
        free(p);
        p=temp;
    }
    free(lista); 
};
