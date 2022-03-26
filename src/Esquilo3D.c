#include "Esquilo3D.h"

float angulo;

GLFWwindow* e3dInitializeWindow(unsigned int width, unsigned int height){
    if(!glfwInit()){
        printf("[ERROR] couldn't initialize GLFW.\n");
        exit(-1);
    }

    GLFWwindow* window = glfwCreateWindow(width, height, "Janela GLFW em contexto OpenGL", NULL, NULL);
    if(!window){
        glfwTerminate();
        printf("[ERROR] couldn't initialize a GLFWwindow window.\n");
        exit(-1);
    }

    // ativa o contexto OpenGL
    glfwMakeContextCurrent(window);
    // imprime informações sobre a GPU
    e3dGpuInfo();
    // configura renderização de faces cheias
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// ativa o teste de profundidade
	glEnable(GL_DEPTH_TEST);
    // ativa reconhecimento de teclado
    glfwSetInputMode(window, GLFW_STICKY_KEYS, true);
    // retorna a janela criada
    return window;
}

void e3dDraw(){
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -30.0f);
	glRotatef(angulo, 10.0f, 25.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	e3dDrawSphere(5.0f, 20.0f, 20.0f);
	// glPopMatrix();

    // glPushMatrix();
	// glTranslatef(-15.0f, 0.0f, -50.0f);
	// glRotatef(-angulo, 46.0f, 15.0f, 0.0f);
	// glScalef(1.0f, 1.0f, 1.0f);
	// e3dDrawCube(10);

    angulo += 0.1;
}



void e3dGpuInfo(){
    printf("\n\n[*] Window initialized.\n");
    printf("> GPU Info: \n");
    printf("  > Manufactor  - %s\n", glGetString(GL_VENDOR));
    printf("  > Model       - %s\n", glGetString(GL_RENDERER));
    printf("  > OpenGL      - %s\n", glGetString(GL_VERSION));
}

void e3dCheckGLError(){
    while (true){
        const GLenum err = glGetError();
        printf("Error: %i\n", err);
    }
}

void e3dRedimensionate(GLFWwindow* window){
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);

    float aspect = (float)width / (float)height;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 500.0f);

	glMatrixMode(GL_MODELVIEW);
}
