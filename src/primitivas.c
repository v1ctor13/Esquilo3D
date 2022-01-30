#include "vetores.h"
#include "primitivas.h"

static void desenharRetangulo(vec3 v1, vec3 v2, vec3 v3, vec3 v4, cor c){
	glColor3fv(c);
	glBegin(GL_QUADS);
	glVertex3fv(getCoord(v1));
	glVertex3fv(getCoord(v2));
	glVertex3fv(getCoord(v3));
	glVertex3fv(getCoord(v4));
	glEnd();
}

void desenharCubo(float s){
	float d = s / 2.0f;
	vec3 v1 = newVector3(-d, d, d);
	vec3 v2 = newVector3(-d,-d, d);
	vec3 v3 = newVector3( d,-d, d);
	vec3 v4 = newVector3( d, d, d);
	
	vec3 v5 = newVector3( d, d,-d);
	vec3 v6 = newVector3( d,-d,-d);
	vec3 v7 = newVector3(-d,-d,-d);
	vec3 v8 = newVector3(-d, d,-d);

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
