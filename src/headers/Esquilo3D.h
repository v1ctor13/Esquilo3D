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
#include "vetores.h"
#include "cores.h"
#include "primitivas.h"
#include "util.h"

//----------------- TIPOS

//----------------- PROTÓTIPOS ***********/

/*@brief Inicializa a janela em contexto OpenGL recebendo a Altura e a Largura em pixels*/
GLFWwindow* e3dIniciarJanela(unsigned int largura, unsigned int altura);

void e3dGpuInfo();
void e3dRedimensionar(GLFWwindow* window);
void e3dDesenhar();
void e3dCheckGLError();

#endif
