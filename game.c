#include "Esquilo3D.h"

void loop(GLFWwindow* window){
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		e3dRedimensionate(window);
		e3dDraw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}while(!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE));
}

int main(){
    GLFWwindow* window = e3dInitializeWindow(800, 600);
    loop(window);
    glfwTerminate();
    return 0;
}
