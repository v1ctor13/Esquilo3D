#include "Esquilo3D.h"

void loop(GLFWwindow* window){
	e3dSetFps(60);

	do{
		e3dGameLoop(window);
	}while(!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE));
}

int main(){
    GLFWwindow* window = e3dInitializeWindow(800, 600);
    loop(window);
    glfwTerminate();
    return 0;
}
