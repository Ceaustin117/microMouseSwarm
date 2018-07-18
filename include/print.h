#ifndef PRINTERS_H
#define PRINTERS_H

#include "microMouse.h"

void printGrid(int **maze);
void printmicroMouseMaze(int **maze, microMouseBot * microMouse);
void printMicroMouseArrayMaze(int **maze, microMouseBot **microMouseArray);
extern int checkMicroMouseArray(int i,int j, microMouseBot **microMouseArray);
extern int checkMicroMouseArrayMazes(int i,int j, microMouseBot **microMouseArray);
extern int checkFirstMicroMouseBot(int i,int j, microMouseBot **microMouseArray);

#endif /* PRINTERS_H */

