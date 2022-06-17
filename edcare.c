#include "edcare.h"
#include "idoso.h"
#include "lista.h"
#include "listaCuidadores.h"
#include "cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leRedeApoio(Lista* lista){
    char linha[100];
    FILE* apoioFile = fopen("apoio.txt", "r");
    if(!apoioFile){
        printf("Erro ao abrir arquivo apoio.txt\n");
        exit(1);
    }
    fscanf(apoioFile,"%s", linha);
    Idoso* aux;
    char * nome = strtok(linha, ";");    // Primeiro nome
    while(nome != NULL){                 // função semelhante ao 'split' do js. Essa não separa a string toda de uma vez só, tem que ser repetida varias vezes
        aux = inicializaIdoso(nome);
        insereLast(lista, aux);
        nome = strtok(NULL, ";");
    }
    char *amigo1, *amigo2;
    char letra;
    while(fscanf(apoioFile, "%s", linha) != EOF){
        amigo1 = strtok(linha, ";");
        amigo2 = strtok(NULL, ";");
        addAmigo(getIdoso(lista, amigo1), getIdoso(lista, amigo2));
        addAmigo(getIdoso(lista, amigo2), getIdoso(lista, amigo1));
    }
    fclose(apoioFile);
};

void leRedeCuidadores(ListaCuidador* listaCuidador, Lista* listaIdosos){
    char nomes[100];
    FILE* cuidadoresFile = fopen("cuidadores.txt", "r");
    if(!cuidadoresFile){
        printf("Erro ao abrir arquivo cuidadores.txt\n");
        exit(1);
    }
    fscanf(cuidadoresFile,"%s", nomes);
    Cuidador* aux;
    char * nomeCuidador = strtok(nomes, ";");  
    while(nomeCuidador != NULL){                 
        aux = inicializaCuidador(nomeCuidador);
        insereLastCuidadores(listaCuidador, aux);
        nomeCuidador = strtok(NULL, ";");
    }
    char nomes2[100], *idoso, *cuidador;
    while(fscanf(cuidadoresFile,"%s", nomes2)!=EOF){
        idoso = strtok(nomes2, ";");
        do{
            cuidador = strtok(NULL, ";");
            if(cuidador != NULL){
                addCuidador(getIdoso(listaIdosos, idoso), getCuidador(listaCuidador, cuidador));
            }
        }while(cuidador != NULL);
        
    }
    fclose(cuidadoresFile);
};