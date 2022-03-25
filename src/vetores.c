#include "vetores.h"

E3D_VET3 e3dCriarVet3(float x, float y, float z){
    E3D_VET3 v = (E3D_VET3)malloc(3 * sizeof(float));
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return &v[0];
}

// float* getCoord(float* v){
//     return &v[0];
// }

float e3dGetVet3_x(float* v){
    return v[0];
}

float e3dGetVet3_y(float* v){
    return v[1];
}

float e3dGetVet3_z(float* v){
    return v[2];
}

E3D_LISTA_VET3 e3dCriarListaVetor3(){
    E3D_LISTA_VET3 lista = (E3D_LISTA_VET3)malloc(sizeof(E3D_LISTA_VET3));
    if(lista != NULL){
        *lista = NULL;
    }else{
        return lista;
    }
    return lista;
}

void e3dDesalocarListaVet3(E3D_LISTA_VET3 lista){
    if(lista != NULL){
        E3D_NODE_LISTA_VET3* node;
        while((*lista != NULL)){
            node = *lista;
            *lista = (*lista)->prox;
            free(node);
        }
        free(lista);
    }
}

int e3dTamanhoListaVet3(E3D_LISTA_VET3 lista){
    if(lista == NULL){
        return 0;
    }
    int c = 0;
    E3D_NODE_LISTA_VET3* node = *lista;
    while(node != NULL){
        c++;
        node = node->prox;
    }
    return c;
}

int e3dInserirListaVet3(E3D_LISTA_VET3 lista, E3D_VET3 dado){
    if(lista == NULL){
        return 0;
    }
    E3D_NODE_LISTA_VET3* node = (E3D_NODE_LISTA_VET3*)malloc(sizeof(E3D_NODE_LISTA_VET3));
    if(node == NULL){
        return -1;
    }
    node->dado = dado;
    node->prox = NULL;

    if(*lista ==  NULL){
        *lista = node;
    }else{
        E3D_NODE_LISTA_VET3* aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = node;
    }
    return 1;
}

