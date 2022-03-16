#include "Esquilo3D.h"

void loop(GLFWwindow* janela){
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		redimensionate(janela);
		draw();
		glfwSwapBuffers(janela);
		glfwPollEvents();
	}while(!glfwWindowShouldClose(janela) && !glfwGetKey(janela, GLFW_KEY_ESCAPE));
}

int main(){
    GLFWwindow* janela = initializeWindow(800, 600);
    loop(janela);
    glfwTerminate();
    return 0;
}
