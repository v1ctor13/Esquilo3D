#include "Esquilo3D.h"

void loop(GLFWwindow* janela){
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		redimensiona(janela);
		desenhar();
		glfwSwapBuffers(janela);
		glfwPollEvents();
	}while(!glfwWindowShouldClose(janela) && !glfwGetKey(janela, GLFW_KEY_ESCAPE));
}

int main(){
    GLFWwindow* janela = inicializarJanela(640, 480);
    loop(janela);
    glfwTerminate();
    return 0;
}
