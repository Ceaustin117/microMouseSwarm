#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "staticVars.h"
/*
   Declare typedef struct microMouseBot
 */
typedef struct microMouseBot
{
	int wallFollow;
	int nx;
	int ny;
	int tx;
	int ty;
	int point;
	int hasGone;
	int dir;
	int **microMouseMappedGrid;
}microMouseBot;
/*
  Maze functions
 */
void carveMaze(int **maze, int width, int height, int x, int y);
void generateMaze(int **maze, int width, int height);
/*
   movement.c
 */
extern int countStepsFunc();
