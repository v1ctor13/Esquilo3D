#include "vetores.h"


float* criarVetor3(float x, float y, float z){
    vetor3 v = (vetor3)malloc(3 * sizeof(float));
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return &v[0];
}

float* getCoord(float* v){
    return &v[0];
}

float getVetor3_x(float* v){
    return v[0];
}

float getVetor3_y(float* v){
    return v[1];
}

float getVetor3_z(float* v){
    return v[2];
}