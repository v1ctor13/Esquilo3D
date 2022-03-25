#ifndef PRIMITIVAS_H
#define PRIMITIVAS_H

#include "Esquilo3D.h"
#include "cores.h"

typedef struct E3D_PONTO_3D{
    float x;
    float y;
    float z;
}E3D_PONTO_3D;

//--------------- PROTÓTIPOS ----------------
void e3dDesenharCubo(float s);
void e3dDesenharEsfera(float raio, unsigned int nPilhas, unsigned int nSetores);

#endif
