#include "vetores.h"
#include "primitivas.h"
#include "util.h"

static void e3dDesenharFace(E3D_VET3 v1, E3D_VET3 v2, E3D_VET3 v3, E3D_VET3 v4, E3D_COR c){
	glColor3fv(c);
	glBegin(GL_QUADS);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glVertex3fv(v4);
	glEnd();
}

void e3dDesenharCubo(float s){
	float d = s / 2.0f;

	E3D_VET3 v1 = e3dCriarVet3(-d, d, d);
	E3D_VET3 v2 = e3dCriarVet3(-d,-d, d);
	E3D_VET3 v3 = e3dCriarVet3( d,-d, d);
	E3D_VET3 v4 = e3dCriarVet3( d, d, d);
	
	E3D_VET3 v5 = e3dCriarVet3( d, d,-d);
	E3D_VET3 v6 = e3dCriarVet3( d,-d,-d);
	E3D_VET3 v7 = e3dCriarVet3(-d,-d,-d);
	E3D_VET3 v8 = e3dCriarVet3(-d, d,-d);

	// frente
	e3dDesenharFace(v1, v2, v3, v4, E3D_VERMELHO);
	// direita
	e3dDesenharFace(v4, v3, v6, v5, E3D_VERDE);
	// trás
	e3dDesenharFace(v5, v8, v7, v6, E3D_AZUL);
	// esquerda
	e3dDesenharFace(v1, v8, v7, v2, E3D_LARANJA);
	// cima
	e3dDesenharFace(v1, v4, v5, v8, E3D_ROXO);
	// baixo
	e3dDesenharFace(v2, v7, v6, v3, E3D_AMARELO);
}

void e3dDesenharEsfera(float raio, unsigned int nPilhas, unsigned int nSetores){
	E3D_LISTA_VET3 pontos = e3dCriarListaVetor3();
	
	E3D_LISTA_INT indices[nPilhas];

    const float PI = 3.14159265359;

    float deltaPI = PI / nPilhas;
    float deltaTheta = 2 * PI / nSetores;

    for(int i = 0; i <= nPilhas; i++){

        float pi = -PI / 2.0 + i * deltaPI;
        float aux = raio * cos(pi);
        float y = raio * sin(pi);

		E3D_LISTA_INT pt = e3dCriarListaInt();

        for(int j = 0; j < nSetores; j++){
            float theta = j * deltaTheta;
            float x = aux * sin(theta);
            float z = aux * cos(theta);

            E3D_VET3 v = e3dCriarVet3(x, y, z);
			e3dInserirListaVet3(pontos, v);
			e3dInserirListaInt(pt, e3dTamanhoListaVet3(pontos));
        }// próximo j
		indices[i] = pt;
    }// próximo i

	// printf("PONTOS: %d\n", tamanhoListaVet3(pontos));
    //--plota pontos
    // glColor3fv(vermelho);
    // glPointSize(5.0f);
    // glBegin(GL_POINTS);

	

	

	// ↓↓↓ TO-DO: encapsular
	// NODE_LISTA_VET3* n = *pontos;
	// while(n != NULL){
	// 	glVertex3fv(n->dado);
	// 	n = n->prox;
	// }
	// ↑↑↑

}
