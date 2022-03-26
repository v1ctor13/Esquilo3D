#include "vectors.h"

E3D_VEC3 e3dCreateVec3(float x, float y, float z){
    E3D_VEC3 v = (E3D_VEC3)malloc(3 * sizeof(float));
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return &v[0];
}

float e3dGetVec3_x(float* v){
    return v[0];
}

float e3dGetVec3_y(float* v){
    return v[1];
}

float e3dGetVec3_z(float* v){
    return v[2];
}

E3D_VEC3_LIST e3dCreateVec3List(){
    E3D_VEC3_LIST list = (E3D_VEC3_LIST)malloc(sizeof(E3D_VEC3_LIST));
    if(list != NULL){
        *list = NULL;
    }else{
        return list;
    }
    return list;
}

void e3dDestroyVec3List(E3D_VEC3_LIST list){
    if(list != NULL){
        E3D_NODE_VEC3_LIST* node;
        while((*list != NULL)){
            node = *list;
            *list = (*list)->next;
            free(node);
        }
        free(list);
    }
}

int e3dSizeofVec3List(E3D_VEC3_LIST list){
    if(list == NULL){
        return 0;
    }
    int c = 0;
    E3D_NODE_VEC3_LIST* node = *list;
    while(node != NULL){
        c++;
        node = node->next;
    }
    return c;
}

int e3dInsertIntoVec3List(E3D_VEC3_LIST list, E3D_VEC3 data){
    if(list == NULL){
        return 0;
    }
    E3D_NODE_VEC3_LIST* node = (E3D_NODE_VEC3_LIST*)malloc(sizeof(E3D_NODE_VEC3_LIST));
    if(node == NULL){
        return -1;
    }
    node->data = data;
    node->next = NULL;

    if(*list ==  NULL){
        *list = node;
    }else{
        E3D_NODE_VEC3_LIST* aux = *list;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}

E3D_VEC3 e3dVec3ListIndexSearch(E3D_VEC3_LIST list, int index){
    if(list == NULL) return NULL;

    E3D_NODE_VEC3_LIST* node = *list;
    if(node == NULL) return NULL;

    int contador = 0;

    while(contador < index){
        node = node->next;
        if(node == NULL) return NULL;

        contador++;
    }

    return node->data;
}

