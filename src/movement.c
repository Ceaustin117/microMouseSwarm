#include <stdlib.h>
#include <stdio.h>
#include "staticVars.h"
#include "movement.h"
#include "wallFollow.h"
#include "maze.h"
#include "print.h"
/*
 * int countOpen
 */
static int movementCountOpen(int **maze) {
	int i = 0;
	int j = 0;
	int count = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (maze[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
};
/*
 * Move microMouse Array
 */
static void movementMicroMouseArray(int **maze, microMouseBot** microMouseArray)
{
	int i = 0;
	int numBots = getNumBots();
	int algChoice = getAlgChoice();
	while(i < numBots)
	{
		microMouseArrayMapSharing(maze, i, microMouseArray);
		switch(algChoice)
		{
		case(1):
		 	wallFollowLeft(maze,  i + 2, microMouseArray[i]);
		 	break;
		case(2):
		 	wallFollowRight(maze, i + 2, microMouseArray[i]);
			break;
		case(3):
			if( (i%2) == 0 )
			{
				wallFollowLeft(maze, i + 2, microMouseArray[i]);
			}
			else
			{
				wallFollowRight(maze, i + 2, microMouseArray[i]);
			}
			break;
		case(4):
			if((*microMouseArray[i]).wallFollow != 0)
			{
				wallFollowLeft(maze, i + 2, microMouseArray[i]);
				(*microMouseArray[i]).wallFollow = 1;
			}
			if((*microMouseArray[i]).wallFollow != 1)
			{
				wallFollowRight(maze, i + 2, microMouseArray[i]);
				(*microMouseArray[i]).wallFollow = 0;
			}
			break;
		}
		i++;
	}
};
/*
 * Function which walks microMousebot until it reaches target
 */
int movementCountStepsFunc() {
	int i = 0;
	int j = 0;
	int count = 0;
	int timeSlotsCount = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	int numBots = getNumBots();
	//Create and allocate memory for grid and targetGrid
	int **maze = (int**)malloc(boundsX * sizeof(int*));
	int **mockMaze = (int**)malloc(boundsX * sizeof(int*));
	for (i = 0; i < boundsX; i++) {
		maze[i] = (int*)malloc(boundsY * sizeof(int));
		mockMaze[i] = (int*)malloc(boundsY * sizeof(int));
	}
	mazeReset(maze);
	mazeGenerate(maze);
	count = movementCountOpen(maze);
	if(numBots >= count)
	{
	 printf("numBots == %d are too many for maze size == %d press any key to exit\n",numBots,count);
	 getchar();
	 return timeSlotsCount;
	}
	mazeCopy(maze, mockMaze);
	//Make microMouseArray
	microMouseBot **microMouseArray = calloc(numBots, sizeof(microMouseBot));
	microMouseMakeArray(maze,microMouseArray);
	//While loop which runs until microMousebot reaches the target on the grid
	while ( (mazeFullyMapped( (*(microMouseArray[0])).microMouseMappedMaze)) < count) {
		movementMicroMouseArray(maze, microMouseArray);
		printMicroMouseArrayMaze(maze,microMouseArray);
		timeSlotsCount++;
		if (timeSlotsCount > 2000) {
			return (-5);
		}
	}
	return timeSlotsCount;
};
