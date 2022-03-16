#include "Esquilo3D.h"

GLFWwindow* initializeWindow(unsigned int largura, unsigned int altura){
    if(!glfwInit()){
        printf("[ERRO] não foi possível inicializar o GLFW.\n");
        exit(-1);
    }

    GLFWwindow* janela = glfwCreateWindow(largura, altura, "Janela GLFW em contexto OpenGL", NULL, NULL);
    if(!janela){
        glfwTerminate();
        printf("[ERRO] não foi possível inicializar uma janela GLFWwindow.\n");
        exit(-1);
    }

    // ativa o contexto OpenGL
    glfwMakeContextCurrent(janela);
    // imprime informações sobre a GPU
    gpuInfo();
    // configura renderização de faces cheias
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// ativa o teste de profundidade
	glEnable(GL_DEPTH_TEST);
    // ativa reconhecimento de teclado
    glfwSetInputMode(janela, GLFW_STICKY_KEYS, true);
    // retorna a janela criada
    return janela;
}

void draw(){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(15.0f, 0.0f, -50.0f);
	glRotatef(30.0f, 10.0f, 25.0f, 0.0f);
	glScalef(2.0f, 1.0f, 1.0f);
	desenharCubo(10);

	glPopMatrix();
    glPushMatrix();

	glTranslatef(-15.0f, 0.0f, -50.0f);
	glRotatef(50.0f, 46.0f, 15.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	desenharCubo(10);
}

void gpuInfo(){
    printf("\n\n[*] Janela iniciada com sucesso.\n");
    printf("> GPU Info: \n");
    printf("  > Fabricante - %s\n", glGetString(GL_VENDOR));
    printf("  > Modelo - %s\n", glGetString(GL_RENDERER));
    printf("  > OpenGL - %s\n", glGetString(GL_VERSION));
}

void CheckGLError(){
    while (true){
        const GLenum err = glGetError();
        printf("Erro: %i\n", err);
    }
}

void redimensionate(GLFWwindow* janela){
    unsigned int largura, altura;

    glfwGetFramebufferSize(janela, &largura, &altura);

    glViewport(0, 0, largura, altura);

    float aspecto = (float)largura / (float)altura;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspecto, 0.1f, 500.0f);

	glMatrixMode(GL_MODELVIEW);
}
