DEPENDENCIES_INCLUDE_FOLDER 	= ../dependencies/include
DEPENDENCIES_LIB_FOLDER 	= ../dependencies/lib
DEPENDENCIES 			= -lglfw3 -lglew32 -lopengl32 -lgdi32 -lUser32 -lShell32 -lOpengl32 -lkernel32 -lglu32

FLAGS 				= -D GLEW_STATIC

ESQUILO_3D_BUILDER_DEPENDENCIES = $(OBJ)/Esquilo3D.o

ROOT 	= ..
HEADERS = headers
BIN 	= ../bin
OBJ 	= obj
LIB	= lib

all:
	gcc -c Esquilo3D.c -o $(OBJ)/Esquilo3D.o -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FOLDER) $(DEPENDENCIES)

jogo: all
	gcc $(ROOT)/jogo.c -o $(ROOT)/jogo.exe $(ESQUILO_3D_BUILDER_DEPENDENCIES) -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FOLDER) $(DEPENDENCIES)

play:
	cd $(ROOT) && jogo.exe 
