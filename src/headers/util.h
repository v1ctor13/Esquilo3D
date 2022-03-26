#ifndef UTIL_H
#define UTIL_H

#include "Esquilo3D.h"

// ---- STRUCTS ----
typedef struct E3D_NODE_INT_LIST{
    int data;
    struct E3D_NODE_INT_LIST* next;
}E3D_NODE_INT_LIST;

typedef struct E3D_NODE_INT_LIST** E3D_INT_LIST;

typedef struct E3D_NODE_LIST_OF_INT_LISTS{
    E3D_INT_LIST data;
    struct E3D_NODE_LIST_OF_INT_LISTS* next;
}E3D_NODE_LIST_OF_INT_LISTS;

typedef E3D_NODE_LIST_OF_INT_LISTS** E3D_LIST_OF_INT_LISTS;

// ---- PROTÓTIPOS DE FUNÇÕES ----
E3D_INT_LIST e3dCreateIntList();
void e3dDestroyIntList(E3D_INT_LIST list);
int e3dSizeofIntList(E3D_INT_LIST list);
int e3dInsertIntoIntList(E3D_INT_LIST list, int data);
E3D_NODE_INT_LIST* e3dIntListIndexSearch(E3D_INT_LIST list, int index);
int e3dIntListIndexInsert(E3D_INT_LIST list, int index);

E3D_LIST_OF_INT_LISTS e3dCreateListOfIntLists();
void e3dDestroyListOfIntLists(E3D_LIST_OF_INT_LISTS list);
int e3dSizeofListOfIntLists(E3D_LIST_OF_INT_LISTS list);
int e3dInsertIntoListOfIntLists(E3D_LIST_OF_INT_LISTS list, int data);
E3D_INT_LIST e3dIntListOfListsIndexSearch(E3D_LIST_OF_INT_LISTS list, int index);
int e3dIntListOfListsIndexInsert(E3D_LIST_OF_INT_LISTS list, int index);

#endif