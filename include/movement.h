#include <stdlib.h>
#include "staticVars.h"
#include "movement.h"
#include "wallFollow.h"
#include "maze.h"
#include "print.h"
#include <stdio.h>
/*
 * int countOpen
 */
int movementCountOpen(int * * maze) {
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
void movementMicroMouseArray(int **maze, microMouseBot** microMouseArray)
{
	int i = 0;
	int numBots = getNumBots();
	int algChoice = getAlgChoice();
	while(i < numBots)
	{
		microMouseArrayMapSharing(maze, i, microMouseArray);
		if(algChoice == 1)
		{
		 wallFollowLeftStrong(maze,  i + 2, microMouseArray[i]);
		}
		if(algChoice == 2)
		{
		 wallFollowRightStrong(maze, i + 2, microMouseArray[i]);
		}
		if(algChoice == 3)
		{
			if( (i%2) == 0 )
			{
				wallFollowLeftStrong(maze, i + 2, microMouseArray[i]);
			}
			else
			{
				wallFollowRightStrong(maze, i + 2, microMouseArray[i]);
			}
		}
		if(algChoice == 4)
		{
			if((*microMouseArray[i]).wallFollow != 0)
			{
				wallFollowLeftStrong(maze, i + 2, microMouseArray[i]);
				(*microMouseArray[i]).wallFollow = 1;
			}
			if((*microMouseArray[i]).wallFollow != 1)
			{
				wallFollowRightStrong(maze, i + 2, microMouseArray[i]);
				(*microMouseArray[i]).wallFollow = 0;
			}
		}
		i++;
	}
printf("moved\n");
};
/*
 * Function which walks microMousebot until it reaches target
 */
int movementCountStepsFunc() {
	int i, j;
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
	int countO = movementCountOpen(maze);
	mazeCopy(maze, mockMaze);
	printf("made it this far\n");
	//Make microMouseArray
	microMouseBot ** microMouseArray = calloc(numBots, sizeof(microMouseBot));
	for (i = 0; i < numBots; i++) {
		microMouseArray[i] = malloc(sizeof(microMouseBot));
		if( (i % 2) == 0 )
		{
			(*microMouseArray[i]).wallFollow = 0;
		}
		if( (i % 2) == 1 )
		{
			(*microMouseArray[i]).wallFollow = 1;	
		}
		microMouseBotReset(microMouseArray[i]);
		microMousePlaceOnRandomSpot(maze, microMouseArray[i]);
		maze[( * (microMouseArray[i])).nx][( * (microMouseArray[i])).ny] = i + 2;
	printf("made it this far2\n");
	}
	int val = 0;
	int numMoves;
	int bla = 0;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	//While loop which runs until microMousebot reaches the target on the grid
	while ( (mazeFullyMapped( (*(microMouseArray[0])).microMouseMappedMaze)) < countO) {
		printf("made it in loop\n");
		movementMicroMouseArray(maze, microMouseArray);
		printf("moved array\n");
		printMicroMouseArrayMaze(maze,microMouseArray);
		timeSlotsCount++;
		if (timeSlotsCount > 2000) {
			return (-5);
		}
                printf("made it thisfar 3\n");
	}
	return timeSlotsCount;
};
