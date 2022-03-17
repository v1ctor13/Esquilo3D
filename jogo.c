#include "Esquilo3D.h"

void loop(GLFWwindow* janela){
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		redimensionar(janela);
		desenhar();
		glfwSwapBuffers(janela);
		glfwPollEvents();
	}while(!glfwWindowShouldClose(janela) && !glfwGetKey(janela, GLFW_KEY_ESCAPE));
}

int main(){
    GLFWwindow* janela = iniciarJanela(800, 600);
    loop(janela);
    glfwTerminate();
    return 0;
}
