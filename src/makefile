ifdef OS
	DEPENDENCIES = -lglfw3 -lglew32 -lopengl32 -lgdi32 -lUser32 -lShell32 -lOpengl32 -lkernel32 -lglu32
	PLAY = game.exe
else
	ifeq ($(shell uname), Linux)
		DEPENDENCIES = -lglfw -lGL -lGLU -lm
		PLAY = ./game.exe
	endif
endif

ROOT 	= ..
HEADERS = headers
BIN 	= ../bin
OBJ 	= obj
LIB		= lib

DEPENDENCIES_INCLUDE_FOLDER = ../dependencies/include/
DEPENDENCIES_LIB_FOLDER = ../dependencies/lib/

FLAGS = -D GLEW_STATIC

GAME_DEPENDENCIES = $(OBJ)/Esquilo3D.o $(OBJ)/primitives.o $(OBJ)/vectors.o $(OBJ)/util.o
OBJ_DEPENDENCIES = -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FODLER) $(DEPENDENCIES)

all:
	gcc -c Esquilo3D.c -o $(OBJ)/Esquilo3D.o -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FOLDER) $(DEPENDENCIES)

linux-dependencies:
	sudo apt-get install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev

obj: all
	gcc -c primitives.c -o $(OBJ)/primitives.o $(OBJ_DEPENDENCIES)
	gcc -c vectors.c -o $(OBJ)/vectors.o $(OBJ_DEPENDENCIES)
	gcc -c util.c -o $(OBJ)/util.o $(OBJ_DEPENDENCIES)

game: obj
	gcc $(ROOT)/game.c -o $(ROOT)/game.exe $(GAME_DEPENDENCIES) -I $(HEADERS) -I $(DEPENDENCIES_INCLUDE_FOLDER) -L $(DEPENDENCIES_LIB_FOLDER) $(DEPENDENCIES)

play:
	cd $(ROOT) && $(PLAY) 
