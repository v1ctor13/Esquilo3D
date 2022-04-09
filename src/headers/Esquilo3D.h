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
#include "primitives.h"
#include "util.h"

//-----------------   TIPOS    -----------------/

//----------------- PROTÓTIPOS -----------------/

/*@brief Inicializa a janela em contexto OpenGL recebendo a Altura e a Largura em pixels*/
GLFWwindow* e3dInitializeWindow(unsigned int width, unsigned int height);
void e3dGameLoop(GLFWwindow* window);
static void e3dLoopTimer();
void e3dSetFps(int value);
void e3dGpuInfo();
void e3dRedimensionate(GLFWwindow* window);
void e3dDrawInit();
void e3dDraw(float delta);
void e3dCheckGLError();

#endif
