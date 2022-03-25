#include "util.h"

E3D_LISTA_INT e3dCriarListaInt(){
    E3D_LISTA_INT lista = (E3D_LISTA_INT)malloc(sizeof(E3D_LISTA_INT));
    if(lista != NULL){
        *lista = NULL;
    }else{
        return lista;
    }
    return lista;
}

void e3dDesalocarListaInt(E3D_LISTA_INT lista){
    if(lista != NULL){
        E3D_NODE_LISTA_INT* node;
        while((*lista != NULL)){
            node = *lista;
            *lista = (*lista)->prox;
            free(node);
        }
        free(lista);
    }
}

int e3dTamanhoListaInt(E3D_LISTA_INT lista){
    if(lista == NULL){
        return 0;
    }
    int c = 0;
    E3D_NODE_LISTA_INT* node = *lista;
    while(node != NULL){
        c++;
        node = node->prox;
    }
    return c;
}

int e3dInserirListaInt(E3D_LISTA_INT lista, int dado){
    if(lista == NULL){
        return 0;
    }
    E3D_NODE_LISTA_INT* node = (E3D_NODE_LISTA_INT*)malloc(sizeof(E3D_NODE_LISTA_INT));
    if(node == NULL){
        return -1;
    }
    node->dado = dado;
    node->prox = NULL;

    if(*lista ==  NULL){
        *lista = node;
    }else{
        E3D_NODE_LISTA_INT* aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = node;
    }
    return 1;
}