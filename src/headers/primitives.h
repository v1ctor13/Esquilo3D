#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "Esquilo3D.h"
#include "colors.h"

typedef struct E3D_POINT3D{
    float x;
    float y;
    float z;
}E3D_POINT3D;

//--------------- PROTÓTIPOS ----------------
void e3dDrawCube(float s);
void e3dDrawSphere(float radius, unsigned int nStacks, unsigned int nSectors);

#endif
