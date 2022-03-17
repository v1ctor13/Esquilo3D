#include "vetores.h"
#include "primitivas.h"

static void desenharFace(vetor3 v1, vetor3 v2, vetor3 v3, vetor3 v4, cor c){
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

	vetor3 v1 = criarVetor3(-d, d, d);
	vetor3 v2 = criarVetor3(-d,-d, d);
	vetor3 v3 = criarVetor3( d,-d, d);
	vetor3 v4 = criarVetor3( d, d, d);
	
	vetor3 v5 = criarVetor3( d, d,-d);
	vetor3 v6 = criarVetor3( d,-d,-d);
	vetor3 v7 = criarVetor3(-d,-d,-d);
	vetor3 v8 = criarVetor3(-d, d,-d);

	// frente
	desenharFace(v1, v2, v3, v4, vermelho);
	// direita
	desenharFace(v4, v3, v6, v5, verde);
	// trás
	desenharFace(v5, v8, v7, v6, azul);
	// esquerda
	desenharFace(v1, v8, v7, v2, laranja);
	// cima
	desenharFace(v1, v4, v5, v8, roxo);
	// baixo
	desenharFace(v2, v7, v6, v3, amarelo);
}

void desenharEsfera(float raio, unsigned int nPilhas, unsigned int nSetores){
    vetor3 pontos[5000];

    const float PI = 3.14159265359;

    float deltaPI = PI / nPilhas;
    float deltaTheta = 2 * PI / nSetores;

    int contador = 0;
    for(int i = 0; i <= nPilhas; i++){

        float pi = -PI / 2.0 + i * deltaPI;
        float aux = raio * cos(pi);
        float y = raio * sin(pi);


        for(int j = 0; j < nSetores; j++){
            float theta = j * deltaTheta;
            float x = aux * sin(theta);
            float z = aux * cos(theta);

            vetor3 v = criarVetor3(x, y, z);
            pontos[contador] = v;
            contador++;
        }// próximo j

    }// próximo i

    //--plota pontos
    glColor3fv(vermelho);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for(int i = 0; i < contador; i++){
        glVertex3fv(pontos[i]);
    }
    glEnd();
}
