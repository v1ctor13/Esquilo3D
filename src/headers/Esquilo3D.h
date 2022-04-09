#ifndef ESQUILO3D_H
#define ESQUILO3D_H

#define NO_ERROR 0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "math.h"
#include "vectors.h"
#include "colors.h"
#include "util.h"
#include "primitives.h"

//-----------------   TIPOS    -----------------/

typedef struct E3D_3D_OBJECT_STRUCT E3D_3D_OBJECT;
typedef struct E3D_NODE_3D_OBJECT_LIST** E3D_3D_OBJECT_LIST;

//----------------- PROTÓTIPOS -----------------/

/*@brief Inicializa a janela em contexto OpenGL recebendo a Altura e a Largura em pixels*/
GLFWwindow* e3dInitializeWindow(unsigned int width, unsigned int height);
void e3dGameLoop(GLFWwindow* window);
static void e3dLoopTimer();
void e3dGpuInfo();
void e3dRedimensionate(GLFWwindow* window);
void e3dDrawInit();
void e3dDraw(float delta);
void e3dCheckGLError();

E3D_3D_OBJECT_LIST e3dCreate3dObjectList();
void e3dDestroy3dObjectList(E3D_3D_OBJECT_LIST e3dObjectList);
int e3dSizeof3dObjectList(E3D_3D_OBJECT_LIST e3dObjectList);
int e3dInsertInto3dObjectList(E3D_3D_OBJECT_LIST e3dObjectList, E3D_3D_OBJECT obj);
E3D_3D_OBJECT* e3d3dObjectListIndexSearch(E3D_3D_OBJECT_LIST e3dObjectList, int index);
int e3d3dObjectIndexInsert(E3D_3D_OBJECT_LIST e3dObjectList, E3D_3D_OBJECT obj);

#endif
