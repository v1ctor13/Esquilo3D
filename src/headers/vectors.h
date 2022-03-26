#ifndef VECTORS_H
#define VECTORS_H

#include "Esquilo3D.h"

typedef float* E3D_VEC3;

typedef struct E3D_NODE_VEC3_LIST{
    E3D_VEC3 data;
    struct E3D_NODE_VEC3_LIST* next;
}E3D_NODE_VEC3_LIST;

typedef struct E3D_NODE_VEC3_LIST** E3D_VEC3_LIST;

// ----------- PROTÓTIPOS
E3D_VEC3 e3dCreateVec3(float x, float y, float z);
float e3dGetVec3_x(E3D_VEC3 v);
float e3dGetVec3_y(E3D_VEC3 v);
float e3dGetVec3_z(E3D_VEC3 v);

E3D_VEC3_LIST e3dCreateVec3List();
void e3dDestroyVec3List(E3D_VEC3_LIST list);
int e3dSizeofVec3List(E3D_VEC3_LIST list);
int e3dInsertIntoVec3List(E3D_VEC3_LIST list, E3D_VEC3 data);

// LISTA_VET2 criarListaVetor2();

#endif
