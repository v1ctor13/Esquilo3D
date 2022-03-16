#ifndef VETORES_H
#define VETORES_H

#include "Esquilo3D.h"

typedef float* vetor3;

//----------- PROTÓTIPOS
vetor3 criarVetor3(float x, float y, float z);
float getVetor3_x(float* v);
float getVetor3_y(float* v);
float getVetor3_z(float* v);
float* getCoord(float* v);

#endif
