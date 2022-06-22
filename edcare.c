#include "edcare.h"
#include "idoso.h"
#include "lista.h"
#include "listaCuidadores.h"
#include "cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEDA 4
#define ALTA 3
#define QUATROBAIXA 2
#define BAIXA 1
#define BEM 0

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
void leSensores(Lista* listaIdosos, ListaCuidador* listaCuidadores, int qtdLeituras){
    int i, j;
    getQtdIdosos(listaIdosos);
    for(i=0;i<getQtdIdosos(listaIdosos);i++){                                                           //abre os arquivos de leitura de cada idoso
        char nomeArquivoEntrada[100];
        char nomeArquivoSaida[100];
        sprintf(nomeArquivoEntrada, "%s.txt", getNome(getIdosoPosicao(listaIdosos, i)));
        sprintf(nomeArquivoSaida, "%s-saida.txt", getNome(getIdosoPosicao(listaIdosos, i)));

        FILE* aux = abreArquivoEntrada(getIdosoPosicao(listaIdosos, i),nomeArquivoEntrada);
        if(!aux){
            printf("Erro ao abrir arquivo %s.txt\n", getNome(getIdosoPosicao(listaIdosos, i)));
            exit(1);
        }
        aux = abreArquivoSaida(getIdosoPosicao(listaIdosos, i),nomeArquivoSaida);
        if(!aux){
            printf("Erro ao abrir arquivo %s-saida.txt\n", getNome(getIdosoPosicao(listaIdosos, i)));
            exit(1);
        }
    }
    for(i=0;i<getQtdCuidadores(listaCuidadores);i++){                                                           //abre os arquivos de leitura de cada idoso
        char nomeArquivoEntradaCuidador[100];
        sprintf(nomeArquivoEntradaCuidador, "%s.txt", getNomeCuidador(getCuidadorPosicao(listaCuidadores, i)));

        FILE* auxCuidador = abreArquivoCuidador(getCuidadorPosicao(listaCuidadores, i),nomeArquivoEntradaCuidador);
        if(!auxCuidador){
            printf("Erro ao abrir arquivo %s.txt\n", getNomeCuidador(getCuidadorPosicao(listaCuidadores, i)));
            exit(1);
        }
    }
    char linha[100];
    char *tempString, *latString, *lonString, *quedaString;
    double temp;
    int lat, lon, queda;
    for(i=0;i<qtdLeituras;i++){
        for(j=0;j<getQtdCuidadores(listaCuidadores);j++){
            fscanf(getArquivoCuidadorPosicao(listaCuidadores, j), "%s", linha);
            latString = strtok(linha, ";");
            lonString = strtok(NULL, ";");
            lat=atoi(latString);
            lon=atoi(lonString);
            atualizaCuidador(getCuidadorPosicao(listaCuidadores, j), lat, lon);
        }
        
        for(j=0;j<getQtdIdosos(listaIdosos);j++){
            fscanf(getArquivoEntradaPosicao(listaIdosos, j), "%s", linha);
            if(strcmp(linha, "falecimento") != 0){
                tempString=strtok(linha, ";");
                latString=strtok(NULL, ";");
                lonString=strtok(NULL, ";");
                quedaString=strtok(NULL, ";");
                temp = atof(tempString);
                lat = atoi(latString);
                lon = atoi(lonString);
                queda = atoi(quedaString);
                atualizaIdoso(getIdosoPosicao(listaIdosos, j), temp, lat, lon, queda);
            }
            else{
                fprintf(getArquivoSaidaPosicao(listaIdosos, j), "falecimento\n");
                fechaArquivoEntrada(getIdosoPosicao(listaIdosos, j));                                                      //fecha cada arquivo de leitura de cada idoso
                fechaArquivoSaida(getIdosoPosicao(listaIdosos, j));  
                atualizaIdosoFalecimento(getIdosoPosicao(listaIdosos, j));
            }
        }

        retiraIdososFalecidos(listaIdosos);
        for (j=0;j<getQtdIdosos(listaIdosos);j++){
            Cuidador* aux;
            Idoso* aux2;
            switch (situacaoIdoso(getIdosoPosicao(listaIdosos, j))) {
                case QUEDA:
                    aux = getCuidadorProximo(getIdosoPosicao(listaIdosos, j));
                    if(!aux){
                        printf("Erro ao encontrar cuidador mais próximos\n");       // para debbugar
                        exit(1);
                    }
                    fprintf(getArquivoSaidaPosicao(listaIdosos, j), "queda, acionou %s\n", getNomeCuidador(aux));
                    break;
                case ALTA:
                    aux = getCuidadorProximo(getIdosoPosicao(listaIdosos, j));
                    if(!aux){
                        printf("Erro ao encontrar cuidador mais próximos\n");       // para debbugar
                        exit(1);
                    }
                    fprintf(getArquivoSaidaPosicao(listaIdosos, j), "febre alta, acionou %s\n", getNomeCuidador(aux));
                    break;
                case QUATROBAIXA:
                    aux = getCuidadorProximo(getIdosoPosicao(listaIdosos, j));
                    if(!aux){
                        printf("Erro ao encontrar cuidador mais próximos\n");       // para debbugar
                        exit(1);
                    }
                    fprintf(getArquivoSaidaPosicao(listaIdosos, j), "febre baixa pela quarta vez, acionou %s\n", getNomeCuidador(aux));
                    break;
                case BAIXA:
                    aux2 = getAmigoProximo(getIdosoPosicao(listaIdosos, j));
                    if(!aux2){
                        fprintf(getArquivoSaidaPosicao(listaIdosos, j), "Febre baixa mas, infelizmente, o idoso está sem amigos na rede\n");
                        break;
                    }
                    fprintf(getArquivoSaidaPosicao(listaIdosos, j), "febre baixa, acionou amigo %s\n", getNome(aux2));
                    break;
                case BEM:
                    fprintf(getArquivoSaidaPosicao(listaIdosos, j), "tudo ok\n");
                    break;
                default:
                    printf("Erro ao atualizar idoso\n");
                    break;
                }
        }
        
    }


    for(i=0;i<getQtdCuidadores(listaCuidadores);i++){
        fechaArquivoCuidador(getCuidadorPosicao(listaCuidadores, i));
    }

    for(i=0;i<getQtdIdosos(listaIdosos);i++){
        fechaArquivoEntrada(getIdosoPosicao(listaIdosos, i));                                                      //fecha cada arquivo de leitura de cada idoso
        fechaArquivoSaida(getIdosoPosicao(listaIdosos, i));                                                      //fecha cada arquivo de leitura de cada idoso
    }
};