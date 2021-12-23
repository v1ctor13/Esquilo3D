#include "Esquilo3D.h"

typedef float cor[3];

GLFWwindow* inicializarJanela(unsigned int largura, unsigned int altura){
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

// auxiliar da função desenharCubo
static void desenharRetangulo(float v1[3], float v2[3], float v3[3], float v4[3], cor c){
	glColor3fv(c);
	glBegin(GL_QUADS);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glVertex3fv(v4);
	glEnd();
}

void desenharCubo(float s){
	float d = s / 2.0f;

	float v1[3] = {-d, d, d};
	float v2[3] = {-d,-d, d};
	float v3[3] = { d,-d, d};
	float v4[3] = { d, d, d};
	
	float v5[3] = { d, d,-d};
	float v6[3] = { d,-d,-d};
	float v7[3] = {-d,-d,-d};
	float v8[3] = {-d, d,-d};

	// TEMPORARIO
	float vermelho[3] 	= {1.0f, 0.0f, 0.0f};
	float verde[3] 		= {0.0f, 1.0f, 0.0f};
	float azul[3] 		= {0.0f, 0.0f, 1.0f};
	float laranja[3] 	= {1.0f, 0.6f, 0.2f};
	float roxo[3] 		= {0.5f, 0.1f, 0.8f};
	float amarelo[3]	= {1.0f, 1.0f, 0.0f};
	float preto[3]		= {0.0f, 0.0f, 0.0f};

	// frente
	desenharRetangulo(v1, v2, v3, v4, vermelho);
	// direita
	desenharRetangulo(v4, v3, v6, v5, verde);
	// trás
	desenharRetangulo(v5, v8, v7, v6, azul);
	// esquerda
	desenharRetangulo(v1, v8, v7, v2, laranja);
	// cima
	desenharRetangulo(v1, v4, v5, v8, roxo);
	// baixo
	desenharRetangulo(v1, v2, v6, v3, amarelo);
}

void desenhar(){
	glLoadIdentity();
	glTranslated(0.0f, 0.0f, -50.0f);
	glRotated(30.0f, 15.0f, 5.0f, 0.0f);
	desenharCubo(10);
}

void gpuInfo(){
    printf("\n\n[*] Janela iniciada com sucesso.\n");
    printf("> GPU Info: \n");
    printf("  > Fabricante - %s\n", glGetString(GL_VENDOR));
    printf("  > Modelo - %s\n", glGetString(GL_RENDERER));
    printf("  > OpenGL - %s\n", glGetString(GL_VERSION));
}

void redimensiona(GLFWwindow* janela){
    unsigned int largura, altura;

    glfwGetFramebufferSize(janela, &largura, &altura);

    glViewport(0, 0, largura, altura);

    float aspecto = (float)largura / (float)altura;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspecto, 0.1f, 500.0f);

	glMatrixMode(GL_MODELVIEW);
}
