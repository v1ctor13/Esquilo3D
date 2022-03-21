#ifndef VETORES_H
#define VETORES_H

#include "Esquilo3D.h"

typedef float* vet3;

typedef struct NODE_LISTA_VET3{
    vet3 dado;
    struct NODE_LISTA_VET3* prox;
}NODE_LISTA_VET3;

typedef struct NODE_LISTA_VET3** LISTA_VET3;

//----------- PROTÓTIPOS
vet3 criarVet3(float x, float y, float z);
float getVet3_x(float* v);
float getVet3_y(float* v);
float getVet3_z(float* v);
float* getCoord(float* v);

LISTA_VET3 criarListaVetor3();
void desalocarListaVet3(LISTA_VET3 lista);
int tamanhoListaVet3(LISTA_VET3 lista);
int inserirListaVet3(LISTA_VET3 lista, vet3 dado);

// LISTA_VETOR2 criarListaVetor2();

#endif
