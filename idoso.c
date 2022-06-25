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
    int qtdFebre;
    int queda;
    int falecido;
    FILE* arquivoEntrada;
    FILE* arquivoSaida;
    Lista* amigos;
    ListaCuidador* cuidadores;
};

Idoso* inicializaIdoso(char* nome){
    Idoso* idoso = (Idoso*)malloc(sizeof(Idoso));
    idoso->nome = strdup(nome);
    idoso->posicao[0] = 0;
    idoso->posicao[1] = 0;
    idoso->temperatura = 0;
    idoso->qtdFebre = 0;
    idoso->queda = 0;
    idoso->falecido = 0;

    idoso->arquivoEntrada = NULL;
    idoso->arquivoSaida = NULL;
    idoso->amigos = inicLista();
    idoso->cuidadores = inicListaCuidadores();
    return idoso;
};

void addAmigo(Idoso* idoso1, Idoso* idoso2){
    insereLast(idoso1->amigos, idoso2);
};

int ehAmigo(Idoso* idoso1, Idoso* idoso2){
    return getIdoso(idoso1->amigos, idoso2->nome) != NULL;
};


FILE* abreArquivoEntrada(Idoso* idoso, char *nomeArquivo){
    FILE* arquivo = fopen(nomeArquivo, "r");
    idoso->arquivoEntrada = arquivo;
    return arquivo;
};

FILE* abreArquivoSaida(Idoso* idoso, char *nomeArquivo){
    FILE* arquivo = fopen(nomeArquivo, "w");
    idoso->arquivoSaida = arquivo;
    return arquivo;
};

void fechaArquivoEntrada(Idoso* idoso){
    fclose(idoso->arquivoEntrada);
};

void fechaArquivoSaida(Idoso* idoso){
    fclose(idoso->arquivoSaida);
};

char* getNome(Idoso* idoso){
    return idoso->nome;
};

int* getPosicaoIdosos(Idoso* idoso){
    return idoso->posicao;
};

Cuidador* getCuidadorProximo(Idoso* idoso){
    return cuidadorProximoPosicao(getListaCuidador(idoso), getPosicaoIdosos(idoso));    //retorna o cuidador mais proximo da posicao do idoso
}
Idoso* getAmigoProximo(Idoso* idoso){
    return AmigoProximoPosicao(getListaAmigos(idoso), getPosicaoIdosos(idoso));         //retorna o amigo mais proximo da posicao do idoso
}

void atualizaIdoso(Idoso* idoso, float temperatura, int lat, int lon, int queda){
    idoso->temperatura = temperatura;
    idoso->posicao[0] = lat;
    idoso->posicao[1] = lon;
    idoso->queda = queda;
};
int situacaoIdoso(Idoso* idoso){
    if(idoso->queda){
        return 4;
    }
    if(idoso->temperatura>=38){
        idoso->qtdFebre=0;
        return 3;
    }
    if(idoso->temperatura>37){
        idoso->qtdFebre++;
        if(idoso->qtdFebre>=4){
            idoso->qtdFebre=0;
            return 2;
        }
        return 1;
    }
    return 0;
};

void retiraListaAmigos(Idoso* idoso){
    Lista* listaAmigos = getListaAmigos(idoso);
    
    int i=0;
    while (getIdosoPosicao(listaAmigos, i)){                                                            //Para cada amigo do idoso falecido,
        retiraNomeSemLiberarIdoso(getListaAmigos(getIdosoPosicao(listaAmigos, i)), getNome(idoso));     //o idoso é retirado da lista de amigos dos seus amigos,
        i++;                                                                                            //afinal, se joao é amigo de pedro, então pedro é amigo de joão
    }                                                                                                   //OBS: não libera o idoso, pois, dessa maneira, ele poderia ser liberado várias vezes. Ele apenas é retirado da lista
    
}

void atualizaIdosoFalecimento(Idoso* idoso){
    idoso->falecido = 1;
}

ListaCuidador* getListaCuidador(Idoso* idoso){
    return idoso->cuidadores;
}

FILE* getArquivoEntrada(Idoso* idoso){
    return idoso->arquivoEntrada;
}

FILE* getArquivoSaida(Idoso* idoso){
    return idoso->arquivoSaida;
}

int idosoFalecido(Idoso* idoso){
    return idoso->falecido;
}

Lista* getListaAmigos(Idoso* idoso){
    return idoso->amigos;
}

void addCuidador(Idoso* idoso, Cuidador* cuidador){
    Cuidador* aux = getCuidador(getListaCuidador(idoso), getNomeCuidador(cuidador));    //checa se já existe o cuidador na lista
    if(aux==NULL){
        insereLastCuidadores(getListaCuidador(idoso), cuidador);                        //Insere no final da lista de cuidadores do idoso
    }
    free(aux);
}

void imprimeAmigos(Idoso* idoso){
    printf("Amigos de %s:\n", getNome(idoso));                                          //Para debug, imprime todos os amigos do idoso
    imprimeLista(getListaAmigos(idoso));
};

void imprimeCuidador(Idoso* idoso){                                                     //Para debug, imprime todos os cuidadores do idoso
    printf("Cuidadores de %s: ", getNome(idoso));
    
    imprimeListaCuidador(getListaCuidador(idoso));
};

void liberaIdoso(Idoso* idoso){                                                         //Libera toda a memória alocada para o idoso
    free(idoso->nome);
    liberaCelulasAmigos(idoso->amigos);
    liberaCelulasCuidadores(idoso->cuidadores);
    free(idoso);
}