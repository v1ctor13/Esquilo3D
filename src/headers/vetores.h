#ifndef VETORES_H
#define VETORES_H

#include "Esquilo3D.h"

typedef float* E3D_VET3;

typedef struct E3D_NODE_LISTA_VET3{
    E3D_VET3 dado;
    struct E3D_NODE_LISTA_VET3* prox;
}E3D_NODE_LISTA_VET3;

typedef struct E3D_NODE_LISTA_VET3** E3D_LISTA_VET3;

// ----------- PROTÓTIPOS
E3D_VET3 e3dCriarVet3(float x, float y, float z);
float e3dGetVet3_x(E3D_VET3 v);
float e3dGetVet3_y(E3D_VET3 v);
float e3dGetVet3_z(E3D_VET3 v);
float* e3dGetCoord(E3D_VET3 v);

E3D_LISTA_VET3 e3dCriarListaVetor3();
void e3dDesalocarListaVet3(E3D_LISTA_VET3 lista);
int e3dTamanhoListaVet3(E3D_LISTA_VET3 lista);
int e3dInserirListaVet3(E3D_LISTA_VET3 lista, E3D_VET3 dado);

// LISTA_VET2 criarListaVetor2();

#endif
