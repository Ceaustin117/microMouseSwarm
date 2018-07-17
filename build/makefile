all: maze.o movement.o microMouse.o print.o staticVars.o wallFollow.o microMouseSim

makeMaze.o:maze.c
	gcc -c maze.c
microMouse.o:microMouse.c
	gcc -c microMouse.c
movement.o:movement.c
	gcc -c movement.c
printers.o:print.c
	gcc -c print.c
staticVars.o:staticVars.c
	gcc -c staticVars.c
WallFollow.o:wallFollow.c
	gcc -c wallFollow.c
microMouseSim:	maze.h movement.h microMouse.h print.h staticVars.h wallFollow.h maze.o movement.o microMouse.o print.o staticVars.o wallFollow.o main.c
	gcc -g -o microMouseSim maze.o movement.o microMouse.o print.o staticVars.o wallFollow.o main.c -lm
