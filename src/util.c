#include "util.h"

// ---- E3D_INT_LIST

E3D_INT_LIST e3dCreateIntList(){
    E3D_INT_LIST list = (E3D_INT_LIST)malloc(sizeof(E3D_INT_LIST));
    if(list != NULL){
        *list = NULL;
    }else{
        return list;
    }
    return list;
}

void e3dDestroyIntList(E3D_INT_LIST list){
    if(list != NULL){
        E3D_NODE_INT_LIST* node;
        while((*list != NULL)){
            node = *list;
            *list = (*list)->next;
            free(node);
        }
        free(list);
    }
}

int e3dSizeofIntList(E3D_INT_LIST list){
    if(list == NULL) return 0;
    int c = 0;
    E3D_NODE_INT_LIST* node = *list;
    while(node != NULL){
        c++;
        node = node->next;
    }
    return c;
}

int e3dInsertIntoIntList(E3D_INT_LIST list, int data){
    if(list == NULL) return 0;

    E3D_NODE_INT_LIST* node = (E3D_NODE_INT_LIST*)malloc(sizeof(E3D_NODE_INT_LIST));
    if(node == NULL) return -1;
    
    node->data = data;
    node->next = NULL;

    if(*list ==  NULL){
        *list = node;
    }else{
        E3D_NODE_INT_LIST* aux = *list;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}

E3D_NODE_INT_LIST* e3dIntListIndexSearch(E3D_INT_LIST list, int index){
    if(list == NULL) return NULL;

    E3D_NODE_INT_LIST* node = *list;
    if(node == NULL) return NULL;

    int contador = 0;

    while(contador < index){
        node = node->next;
        if(node == NULL) return NULL;

        contador++;
    }

    return node;
}

// ---- E3D_LIST_OF_INT_LISTS

E3D_LIST_OF_INT_LISTS e3dCreateListOfIntLists(){
    E3D_LIST_OF_INT_LISTS list = (E3D_LIST_OF_INT_LISTS)malloc(sizeof(E3D_LIST_OF_INT_LISTS));
    if(list != NULL){
        *list = NULL;
    }else{
        return list;
    }
    return list;
}

void e3dDestroyListOfIntLists(E3D_LIST_OF_INT_LISTS list){

}

int e3dSizeofListOfIntLists(E3D_LIST_OF_INT_LISTS list){

}

int e3dInsertIntoListOfIntLists(E3D_LIST_OF_INT_LISTS list, E3D_INT_LIST data){
    if(list == NULL) return 0;

    E3D_NODE_LIST_OF_INT_LISTS* node = (E3D_NODE_LIST_OF_INT_LISTS*)malloc(sizeof(E3D_NODE_LIST_OF_INT_LISTS));
    if(node == NULL) return -1;
    
    node->data = data;
    node->next = NULL;

    if(*list ==  NULL){
        *list = node;
    }else{
        E3D_NODE_LIST_OF_INT_LISTS* aux = *list;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}

E3D_INT_LIST e3dIntListOfListsIndexSearch(E3D_LIST_OF_INT_LISTS list, int index){
    if(list == NULL) return NULL;

    E3D_NODE_LIST_OF_INT_LISTS* node = *list;
    if(node == NULL) return NULL;

    int contador = 0;

    while(contador < index){
        node = node->next;
        if(node == NULL) return NULL;

        contador++;
    }

    return node->data;

}
