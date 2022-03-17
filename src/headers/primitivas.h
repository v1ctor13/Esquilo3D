#ifndef PRIMITIVAS_H
#define PRIMITIVAS_H

#include "Esquilo3D.h"
#include "cores.h"

struct s_ponto3d {
    float x;
    float y;
    float z;
};

typedef struct s_ponto3d ponto3d;

//--------------- PROTÓTIPOS ----------------
void desenharCubo(float s);
void desenharEsfera(float raio, unsigned int nPilhas, unsigned int nSetores);

#endif
