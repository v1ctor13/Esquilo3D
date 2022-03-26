#include "vectors.h"
#include "primitives.h"
#include "util.h"

static void e3dDrawFace(E3D_VEC3 v1, E3D_VEC3 v2, E3D_VEC3 v3, E3D_VEC3 v4, E3D_COLOR c){
	glColor3fv(c);
	glBegin(GL_QUADS);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glVertex3fv(v4);
	glEnd();
}

void e3dDrawCube(float s){
	float d = s / 2.0f;

	E3D_VEC3 v1 = e3dCreateVec3(-d, d, d);
	E3D_VEC3 v2 = e3dCreateVec3(-d,-d, d);
	E3D_VEC3 v3 = e3dCreateVec3( d,-d, d);
	E3D_VEC3 v4 = e3dCreateVec3( d, d, d);
	
	E3D_VEC3 v5 = e3dCreateVec3( d, d,-d);
	E3D_VEC3 v6 = e3dCreateVec3( d,-d,-d);
	E3D_VEC3 v7 = e3dCreateVec3(-d,-d,-d);
	E3D_VEC3 v8 = e3dCreateVec3(-d, d,-d);

	// front
	e3dDrawFace(v1, v2, v3, v4, E3D_RED);
	// right
	e3dDrawFace(v4, v3, v6, v5, E3D_GREEN);
	// back
	e3dDrawFace(v5, v8, v7, v6, E3D_BLUE);
	// left
	e3dDrawFace(v1, v8, v7, v2, E3D_ORANGE);
	// up
	e3dDrawFace(v1, v4, v5, v8, E3D_PURPLE);
	// down
	e3dDrawFace(v2, v7, v6, v3, E3D_YELLOW);
}

void e3dDrawSphere(float radius, unsigned int nStacks, unsigned int nSectors){
	E3D_LIST_OF_INT_LISTS indices = e3dCreateListOfIntLists();

	E3D_VEC3_LIST points = e3dCreateVec3List();

    const float PHI = 3.14159265359;

    float deltaPHI = PHI / nStacks;
    float deltaTheta = 2 * PHI / nSectors;

    for(int i = 0; i <= nStacks; i++){

        float phi = -PHI / 2.0 + i * deltaPHI;
        float aux = radius * cos(phi);
        float y = radius * sin(phi);

		E3D_INT_LIST pt = e3dCreateIntList();

        for(int j = 0; j < nSectors; j++){
            float theta = j * deltaTheta;
            float x = aux * sin(theta);
            float z = aux * cos(theta);

            E3D_VEC3 v = e3dCreateVec3(x, y, z);
			e3dInsertIntoVec3List(points, v);
			e3dInsertIntoIntList(pt, e3dSizeofVec3List(points));
        }// próximo j
		// indices[i] = pt;
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
