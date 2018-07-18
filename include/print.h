#ifndef PRINT_H
#define PRINT_H
#include "microMouse.h"

extern void printGrid(int **maze);
extern void printmicroMouseMaze(int **maze, microMouseBot * microMouse);
extern void printMicroMouseArrayMaze(int **maze, microMouseBot **microMouseArray);
extern int checkMicroMouseArray(int i,int j, microMouseBot **microMouseArray);
extern int checkMicroMouseArrayMazes(int i,int j, microMouseBot **microMouseArray);
extern int checkFirstMicroMouseBot(int i,int j, microMouseBot **microMouseArray);

#endif /* PRINT_H */
