#ifndef CUIDADOR_H
#define CUIDADOR_H

typedef struct cuidador Cuidador;

Cuidador* inicializaCuidador(char* nome);
char* getNomeCuidador(Cuidador* cuidador);
void liberaCuidador(Cuidador* cuidador);

#endif // CUIDADOR_H