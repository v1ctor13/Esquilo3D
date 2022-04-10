#include "Esquilo3D.h"

// Display List
static unsigned int sphereId;
static unsigned int gridTerrainId;

struct E3D_3D_OBJECT_STRUCT{
    unsigned int id;
    E3D_VEC3 pos;
};

struct E3D_NODE_3D_OBJECT_LIST_STRUCT{
    E3D_3D_OBJECT obj;
    struct E3D_NODE_3D_OBJECT_LIST_STRUCT* next;
};

// FPS
float dt = 0.0f;
float lastTime = 0.0f;

float angulo;

GLFWwindow* e3dInitializeWindow(unsigned int width, unsigned int height){
    if(!glfwInit()){
        printf("[ERROR] couldn't initialize GLFW. Error code: %d\n", glfwGetError(NULL));
        exit(-1);
    }

    GLFWwindow* window = glfwCreateWindow(width, height, "Janela GLFW em contexto OpenGL", NULL, NULL);
    if(!window){
        glfwTerminate();
        printf("[ERROR] couldn't initialize a GLFWwindow window. Error code: %d\n", glfwGetError(NULL));
        exit(-1);
    }

    // ativa o contexto OpenGL
    glfwMakeContextCurrent(window);
    // imprime informações sobre a GPU
    e3dGpuInfo();
    // ativa reconhecimento de teclado
    glfwSetInputMode(window, GLFW_STICKY_KEYS, true);
    // configurações iniciais antes de desenhar
    e3dDrawInit();
    
    // retorna a janela criada
    return window;
}
void e3dGameLoop(GLFWwindow* window){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    e3dRedimensionate(window);
    e3dLoopTimer();
    e3dDraw(dt);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

static void e3dLoopTimer(){
    float value = 0.0f;
    float currentTime; 
 
    currentTime = (float)glfwGetTime();
    dt = currentTime - lastTime;
    lastTime = currentTime;
}

static void e3dDrawGridTerrain(unsigned int id){
    float L = 500.0f;
    float interval = 1.0f;
    float y = -0.5f;

    glNewList(id, GL_COMPILE);
    glColor3fv(E3D_WHITE);
    glBegin(GL_LINES);
    for(float i = -L; i <= L; i += interval){
        // Vertical
        glVertex3f(i, y, -L);
        glVertex3f(i, y,  L);

        // Horizontal
        glVertex3f(-L, y,  i);
        glVertex3f( L, y,  i);
    }
    glEnd();
    glEndList();

}

void e3dDrawInit(){
	// ativa o teste de profundidade
	glEnable(GL_DEPTH_TEST);
    // background color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    sphereId = glGenLists(1);
    gridTerrainId = glGenLists(1);

    e3dDrawSphere(sphereId, 5.0f, E3D_RED, 20.0f, 20.0f);
    e3dDrawGridTerrain(gridTerrainId);
}

void e3dDraw(float delta){
    float angularVelocity = 60.0f * delta; // 60° por segundo
	glLoadIdentity();

    glCallList(gridTerrainId);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -30.0f);
	glRotatef(angulo, 10.0f, 25.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);
    glCallList(sphereId);
	glPopMatrix();

    angulo += angularVelocity;
    if(angulo >= 360.0f){
        angulo = 0.0f;
    }
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

// ---- 3D OBJECT ----

E3D_3D_OBJECT e3dCreate3dObject(){
    struct E3D_3D_OBJECT_STRUCT* obj;
    obj->id = 0;

    E3D_VEC3 v = e3dCreateVec3(0.0f, 0.0f, 0.0f);
    obj->pos = v;
    return obj;
}

E3D_3D_OBJECT_LIST e3dCreate3dObjectList(){
    E3D_3D_OBJECT_LIST e3dObjectList = (E3D_3D_OBJECT_LIST)malloc(sizeof(E3D_3D_OBJECT_LIST));
    if(e3dObjectList != NULL){
        *e3dObjectList = NULL;
    }else{
        return e3dObjectList;
    }
    return e3dObjectList;
}

void e3dDestroy3dObjectList(E3D_3D_OBJECT_LIST e3dObjectList){
    if(e3dObjectList != NULL){
        E3D_NODE_3D_OBJECT_LIST* node;
        while((*e3dObjectList != NULL)){
            node = *e3dObjectList;
            *e3dObjectList = (*e3dObjectList)->next;
            free(node);
        }
        free(e3dObjectList);
    }
}

int e3dSizeof3dObjectList(E3D_3D_OBJECT_LIST e3dObjectList){
    if(e3dObjectList == NULL) return 0;
    
    int c = 0;
    E3D_NODE_3D_OBJECT_LIST* node = *e3dObjectList;
    while(node != NULL){
        c++;
        node = node->next;
    }
    return c;
}

int e3dInsertInto3dObjectList(E3D_3D_OBJECT_LIST e3dObjectList, E3D_3D_OBJECT obj){
    if(e3dObjectList == NULL) return 0;
    
    E3D_NODE_3D_OBJECT_LIST* node = (E3D_NODE_3D_OBJECT_LIST*)malloc(sizeof(E3D_NODE_3D_OBJECT_LIST));
    if(node == NULL) return -1;
    
    node->obj = obj;
    node->next = NULL;

    if(*e3dObjectList ==  NULL){
        *e3dObjectList = node;
    }else{
        E3D_NODE_3D_OBJECT_LIST* aux = *e3dObjectList;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}
