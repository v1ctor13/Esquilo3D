DEPENDENCIES_INCLUDE_FOLDER 	= ../dependencies/include
DEPENDENCIES_LIB_FOLDER 	= ../dependencies/lib
DEPENDENCIES 			= -lglfw3 -lglew32 -lopengl32 -lgdi32 -lUser32 -lShell32 -lOpengl32 -lkernel32 -lglu32

FLAGS 				= -D GLEW_STATIC

GAME_DEPENDENCIES = $(OBJ)/Esquilo3D.o $(OBJ)/primitivas.o $(OBJ)/vetores.o $(OBJ)/util.o
OBJ_DEPENDENCIES = -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FODLER) $(DEPENDENCIES)

ROOT 	= ..
HEADERS = headers
BIN 	= ../bin
OBJ 	= obj
LIB		= lib

ifdef OS
	ECHO = echo "estamos no windows!"
else
	ifeq ($(shell uname), Linux)
		ECHO = echo "estamos no linux!"
	endif
endif

all:
	gcc -c Esquilo3D.c -o $(OBJ)/Esquilo3D.o -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FOLDER) $(DEPENDENCIES)
	$(ECHO)

obj: all
	gcc -c primitivas.c -o $(OBJ)/primitivas.o $(OBJ_DEPENDENCIES)
	gcc -c vetores.c -o $(OBJ)/vetores.o $(OBJ_DEPENDENCIES)
	gcc -c util.c -o $(OBJ)/util.o $(OBJ_DEPENDENCIES)

jogo: obj
	gcc $(ROOT)/jogo.c -o $(ROOT)/jogo.exe $(GAME_DEPENDENCIES) -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FOLDER) $(DEPENDENCIES)

play:
	cd $(ROOT) && jogo.exe 
