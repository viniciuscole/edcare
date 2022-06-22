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
void retiraIdososFalecidos(Lista* lista){
    Celula* p = lista->primeiro;
    while(p){
        if(idosoFalecido(p->idoso)){
            retiraNome(lista, getNome(p->idoso));
        }
        p=p->prox;
    }
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
Idoso* getIdosoPosicao(Lista* lista, int posicao){
    Celula* p = lista->primeiro;
    int i=0;
    while(p && i<posicao){
        p=p->prox;
        i++;
    }
    if(!p){
        printf("Não foi encontrado idoso na posição %d\n", posicao);
        exit(1);
    }
    return p->idoso;
}
Idoso* AmigoProximoPosicao(Lista* amigos, int * posicao){
    Celula* p = amigos->primeiro;
    Celula* aux;
    double distancia, min=-1;
    while(p){
        if(!idosoFalecido(p->idoso)){
            distancia=calculaDistancia(getPosicaoIdosos(p->idoso), posicao);
            if(min==-1){ // primeira vez
                min=distancia;
                aux=p;
            }
            if(distancia<min){
                min=distancia;
                aux=p;
            }
        }
        p=p->prox;
    }
    if(min==-1){
        return NULL;
    }
    return aux->idoso;
}
FILE* getArquivoEntradaPosicao(Lista* lista, int posicao){
    Celula* p = lista->primeiro;
    int i=0;
    while(p && i<posicao){
        p=p->prox;
        i++;
    }
    if(!p){
        printf("Não foi encontrado idoso na posição %d\n", posicao);
        exit(1);
    }
    return getArquivoEntrada(p->idoso);
}
FILE* getArquivoSaidaPosicao(Lista* lista, int posicao){
    Celula* p = lista->primeiro;
    int i=0;
    while(p && i<posicao){
        p=p->prox;
        i++;
    }
    if(!p){
        printf("Não foi encontrado idoso na posição %d\n", posicao);
        exit(1);
    }
    return getArquivoSaida(p->idoso);
}
int getQtdIdosos(Lista* lista){
    Celula* p = lista->primeiro;
    int qtd=0;
    while(p){
        qtd++;
        p=p->prox;
    }
    return qtd;
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
    free(lista); 
};
void liberaCelulasAmigos(Lista* lista){
    Celula* p = lista->primeiro;
    Celula* temp = NULL;
    while(p){
        temp=p->prox;
        free(p);
        p=temp;
    }
    free(lista); 
};
