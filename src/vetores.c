#include "vetores.h"

struct vector3{
    float coord[3];
};

vec3 newVector3(float x, float y, float z){
    vec3 v = (vec3)malloc(sizeof(vec3));
    v->coord[0] = x;
    v->coord[1] = y;
    v->coord[2] = z;
    return v;
}

float* getCoord(vec3 v){
    return v->coord;
}

float getVetor3_x(vec3 v){
    return v->coord[0];
}

float getVetor3_y(vec3 v){
    return v->coord[1];
}

float getVetor3_z(vec3 v){
    return v->coord[2];
}