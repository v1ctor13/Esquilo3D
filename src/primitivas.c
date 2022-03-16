#include "vetores.h"
#include "primitivas.h"

static void desenharRetangulo(vetor3 v1, vetor3 v2, vetor3 v3, vetor3 v4, cor c){
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

	// float v1[3] = {-d, d, d};
	// float v2[3] = {-d,-d, d};
	// float v3[3] = { d,-d, d};
	// float v4[3] = { d, d, d};
	vetor3 v1 = criarVetor3(-d, d, d);
	vetor3 v2 = criarVetor3(-d,-d, d);
	vetor3 v3 = criarVetor3( d,-d, d);
	vetor3 v4 = criarVetor3( d, d, d);
	
	// float v5[3] = { d, d,-d};
	// float v6[3] = { d,-d,-d};
	// float v7[3] = {-d,-d,-d};
	// float v8[3] = {-d, d,-d};
	vetor3 v5 = criarVetor3( d, d,-d);
	vetor3 v6 = criarVetor3( d,-d,-d);
	vetor3 v7 = criarVetor3(-d,-d,-d);
	vetor3 v8 = criarVetor3(-d, d,-d);

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
	desenharRetangulo(v2, v7, v6, v3, amarelo);
}
