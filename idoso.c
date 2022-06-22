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
    return cuidadorProximoPosicao(getListaCuidador(idoso), getPosicaoIdosos(idoso));
}
Idoso* getAmigoProximo(Idoso* idoso){
    return AmigoProximoPosicao(getListaAmigos(idoso), getPosicaoIdosos(idoso));
}

int atualizaIdoso(Idoso* idoso, float temperatura, int lat, int lon, int queda){
    idoso->temperatura = temperatura;
    idoso->posicao[0] = lat;
    idoso->posicao[1] = lon;
    idoso->queda = queda;
    if(queda){
        return 4;
    }
    if(temperatura>=38){
        idoso->qtdFebre=0;
        return 3;
    }
    if(temperatura>37){
        idoso->qtdFebre++;
        if(idoso->qtdFebre>=4){
            idoso->qtdFebre=0;
            return 2;
        }
        return 1;
    }
    return 0;
};

ListaCuidador* getListaCuidador(Idoso* idoso){
    return idoso->cuidadores;
}

FILE* getArquivoEntrada(Idoso* idoso){
    return idoso->arquivoEntrada;
}

FILE* getArquivoSaida(Idoso* idoso){
    return idoso->arquivoSaida;
}

Lista* getListaAmigos(Idoso* idoso){
    return idoso->amigos;
}


void addCuidador(Idoso* idoso, Cuidador* cuidador){
    Cuidador* aux = getCuidador(getListaCuidador(idoso), getNomeCuidador(cuidador));  //checa se já existe o cuidador na lista
    if(aux==NULL){
        insereLastCuidadores(getListaCuidador(idoso), cuidador);
    }
    free(aux);
}

void imprimeAmigos(Idoso* idoso){
    printf("Amigos de %s:\n", getNome(idoso));
    imprimeLista(getListaAmigos(idoso));
};

void imprimeCuidador(Idoso* idoso){
    printf("Cuidadores de %s: ", getNome(idoso));
    
    imprimeListaCuidador(getListaCuidador(idoso));
};

void liberaIdoso(Idoso* idoso){
    free(idoso->nome);
    liberaCelulasAmigos(idoso->amigos);
    liberaCelulasCuidadores(idoso->cuidadores);
    free(idoso);
}