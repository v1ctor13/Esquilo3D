#ifndef VETORES_H
#define VETORES_H

#include "Esquilo3D.h"

typedef struct vector3* vec3;

//----------- PROTÓTIPOS
vec3 newVector3(float x, float y, float z);
float getVetor3_x(vec3 v);
float getVetor3_y(vec3 v);
float getVetor3_z(vec3 v);
float* getCoord(vec3 v);

#endif
