#include "vetores.h"
#include "primitivas.h"

static void desenharFace(vet3 v1, vet3 v2, vet3 v3, vet3 v4, cor c){
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

	vet3 v1 = criarVet3(-d, d, d);
	vet3 v2 = criarVet3(-d,-d, d);
	vet3 v3 = criarVet3( d,-d, d);
	vet3 v4 = criarVet3( d, d, d);
	
	vet3 v5 = criarVet3( d, d,-d);
	vet3 v6 = criarVet3( d,-d,-d);
	vet3 v7 = criarVet3(-d,-d,-d);
	vet3 v8 = criarVet3(-d, d,-d);

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
	LISTA_VET3 pontos = criarListaVetor3();

    const float PI = 3.14159265359;

    float deltaPI = PI / nPilhas;
    float deltaTheta = 2 * PI / nSetores;

    for(int i = 0; i <= nPilhas; i++){

        float pi = -PI / 2.0 + i * deltaPI;
        float aux = raio * cos(pi);
        float y = raio * sin(pi);

        for(int j = 0; j < nSetores; j++){
            float theta = j * deltaTheta;
            float x = aux * sin(theta);
            float z = aux * cos(theta);

            vet3 v = criarVet3(x, y, z);
			inserirListaVet3(pontos, v);
        }// próximo j

    }// próximo i

    //--plota pontos
    glColor3fv(vermelho);
    glPointSize(5.0f);
    glBegin(GL_POINTS);

	// ↓↓↓ TO-DO: encapsular
	NODE_LISTA_VET3* n = *pontos;
	while(n != NULL){
		glVertex3fv(n->dado);
		n = n->prox;
	}
	// ↑↑↑

    glEnd();
}
