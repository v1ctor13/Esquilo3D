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

//----------------- TIPOS

//----------------- PROTÓTIPOS ***********/

/*@brief Inicializa a janela em contexto OpenGL recebendo a Altura e a Largura em pixels*/
GLFWwindow* iniciarJanela(unsigned int largura, unsigned int altura);

void gpuInfo();
void redimensionar(GLFWwindow* window);
void desenhar();
void CheckGLError();

#endif
