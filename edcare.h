#ifndef EDCARE_H
#define EDCARE_H
#include "lista.h"
#include "listaCuidadores.h"

void leRedeApoio(Lista* lista);
void leRedeCuidadores(ListaCuidador* listaCuidador, Lista* listaIdosos);
void leSensores(Lista* listaIdosos, ListaCuidador* listaCuidadores, int qtdLeituras);

#endif // EDCARE_H