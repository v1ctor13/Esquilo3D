#include "Esquilo3D.h"

float angulo;

GLFWwindow* e3dIniciarJanela(unsigned int largura, unsigned int altura){
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
    e3dGpuInfo();
    // configura renderização de faces cheias
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// ativa o teste de profundidade
	glEnable(GL_DEPTH_TEST);
    // ativa reconhecimento de teclado
    glfwSetInputMode(janela, GLFW_STICKY_KEYS, true);
    // retorna a janela criada
    return janela;
}

void e3dDesenhar(){
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -30.0f);
	glRotatef(angulo, 10.0f, 25.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	e3dDesenharEsfera(5.0f, 20.0f, 20.0f);
	glPopMatrix();

    // glPushMatrix();
	// glTranslatef(-15.0f, 0.0f, -50.0f);
	// glRotatef(-angulo, 46.0f, 15.0f, 0.0f);
	// glScalef(1.0f, 1.0f, 1.0f);
	// desenharCubo(10);

    angulo += 0.01;
}



void e3dGpuInfo(){
    printf("\n\n[*] Janela iniciada com sucesso.\n");
    printf("> GPU Info: \n");
    printf("  > Fabricante - %s\n", glGetString(GL_VENDOR));
    printf("  > Modelo - %s\n", glGetString(GL_RENDERER));
    printf("  > OpenGL - %s\n", glGetString(GL_VERSION));
}

void e3dCheckGLError(){
    while (true){
        const GLenum err = glGetError();
        printf("Erro: %i\n", err);
    }
}

void e3dRedimensionar(GLFWwindow* janela){
    int largura, altura;

    glfwGetFramebufferSize(janela, &largura, &altura);

    glViewport(0, 0, largura, altura);

    float aspecto = (float)largura / (float)altura;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspecto, 0.1f, 500.0f);

	glMatrixMode(GL_MODELVIEW);
}
