all: makeMaze.o movement.o microMouse.o printers.o staticVars.o WallFollow.o microMouseSim

makeMaze.o:makeMaze.c
	gcc -c makeMaze.c
microMouse.o:microMouse.c
	gcc -c microMouse.c
movement.o:movement.c
	gcc -c movement.c
printers.o:printers.c
	gcc -c printers.c
staticVars.o:staticVars.c
	gcc -c staticVars.c
WallFollow.o:WallFollow.c
	gcc -c WallFollow.c
microMouseSim:	functions.h staticVars.h makeMaze.o movement.o microMouse.o printers.o staticVars.o WallFollow.o main.c
	gcc -g -o microMouseSim makeMaze.o movement.o microMouse.o printers.o staticVars.o WallFollow.o main.c -lm
