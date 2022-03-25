#ifndef UTIL_H
#define UTIL_H

#include "Esquilo3D.h"

// ---- STRUCTS ----
typedef struct E3D_NODE_LISTA_INT{
    int dado;
    struct E3D_NODE_LISTA_INT* prox;
}E3D_NODE_LISTA_INT;

typedef struct E3D_NODE_LISTA_INT** E3D_LISTA_INT;

typedef struct E3D_NODE_LISTA_LISTA_INT{
    E3D_LISTA_INT dado;
    struct E3D_NODE_LISTA_LISTA_INT* prox;
}E3D_NODE_LISTA_LISTA_INT;

typedef E3D_NODE_LISTA_LISTA_INT** E3D_LISTA_LISTA_INT;

// ---- PROTÓTIPOS DE FUNÇÕES ----
E3D_LISTA_INT e3dCriarListaInt();
E3D_LISTA_LISTA_INT e3dCriarListaListaInt();
void e3dDesalocarListaInt(E3D_LISTA_INT lista);
int e3dTamanhoListaInt(E3D_LISTA_INT lista);
int e3dInserirListaInt(E3D_LISTA_INT lista, int dado);

#endif