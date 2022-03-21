#include "vetores.h"

vet3 criarVet3(float x, float y, float z){
    vet3 v = (vet3)malloc(3 * sizeof(float));
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return &v[0];
}

// float* getCoord(float* v){
//     return &v[0];
// }

float getVet3_x(float* v){
    return v[0];
}

float getVet3_y(float* v){
    return v[1];
}

float getVet3_z(float* v){
    return v[2];
}

LISTA_VET3 criarListaVetor3(){
    LISTA_VET3 lista = (LISTA_VET3)malloc(sizeof(LISTA_VET3));
    if(lista != NULL){
        *lista = NULL;
    }else{
        return lista;
    }
    return lista;
}

int tamanhoListaVet3(LISTA_VET3 lista){
    if(lista == NULL){
        return 0;
    }
    int c = 0;
    NODE_LISTA_VET3* node = *lista;
    while(node != NULL){
        c++;
        node = node->prox;
    }
    return c;
}

int inserirListaVet3(LISTA_VET3 lista, vet3 dado){
    if(lista == NULL){
        return 0;
    }
    NODE_LISTA_VET3* node = (NODE_LISTA_VET3*)malloc(sizeof(NODE_LISTA_VET3));
    if(node == NULL){
        return -1;
    }
    node->dado = dado;
    node->prox = NULL;

    if(*lista ==  NULL){
        *lista = node;
    }else{
        NODE_LISTA_VET3* aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = node;
    }
    return 1;
}

