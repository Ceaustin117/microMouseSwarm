#include "staticVars.h"
#include "functions.h"
//Check for wall or bot
int checkForWallOrBot(int * * maze, int nx, int ny) {
	int numBots = getNumBots();
	int flag = 0;
	int i = 0;
	int j = 0;
	//check if wall
	if (maze[nx][ny] == 1) {
		flag = 1;
	}
	//check if other microMousebot
	for (i = 2; i < numBots + 2; i++) {
		if (maze[nx][ny] == i) {
			flag = 1;
		}
	}
	return flag;
};
//Maze fully Mapped
int mazeFullyMapped(int * * maze, int boundsX, int boundsY) {
	int i = 0;
	int j = 0;
	int val = 0;
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (maze[i][j] == 0) {
				val++;
			}
		}
	}
	return val;
};
//Place microMouse on random open spot on maze
void placemicroMouseOnRandomSpot(int * * maze, int boundsX, int boundsY, microMouseBot * microMouse) {
	int i = 0;
	int j = 0;
	int flag = 0;
	int randX = rand() % boundsX;
	int randY = rand() % boundsY;
	while (flag == 0) {
		randX = rand() % boundsX;
		randY = rand() % boundsY;
		if (maze[randX][randY] == 0) {
			maze[randX][randY] = 2;
			( * microMouse).nx = randX;
			( * microMouse).ny = randY;
			flag = 1;
		}
	}
};
/*
 * int countOpen
 */
int countOpen(int * * maze, int width, int height) {
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			if (maze[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
};
void microMouseArrayMapSharing(int** targetGrid,int  boundsX,int  boundsY,microMouseBot** microMouseArray,int index)
{
	int numBots = getNumBots();
	int i = 0;
	while(i < numBots)
	{
		if(i != index)
		{
			if(checkNearOthermicroMouse(microMouseArray[index], microMouseArray[i]) == 1) {
				microMouseShareMapping(boundsX, boundsY, microMouseArray[index], microMouseArray[i]);
			}
		}
		i++;
	}
};
/*
 * Move microMouse Array
 */
void moveMicroMouseArray(int **targetGrid, int boundsX, int boundsY, microMouseBot** microMouseArray)
{
	int i = 0;
	int numBots = getNumBots();
	int algChoice = getAlgChoice();
	while(i < numBots)
	{
		microMouseArrayMapSharing(targetGrid, boundsX, boundsY, microMouseArray,i);
		if(algChoice == 1)
		{
		 wallFollowLeftStrong(targetGrid, boundsX, boundsY, microMouseArray[i], i + 2);
		}
		if(algChoice == 2)
		{
		 wallFollowRightStrong(targetGrid, boundsX, boundsY, microMouseArray[i], i + 2);
		}
		if(algChoice == 3)
		{
			if( (i%2) == 0 )
			{
				wallFollowLeftStrong(targetGrid, boundsX, boundsY, microMouseArray[i], i + 2);
			}
			else
			{
				wallFollowRightStrong(targetGrid, boundsX, boundsY, microMouseArray[i], i + 2);
			}
		}
		if(algChoice == 4)
		{
			if((*microMouseArray[i]).wallFollow != 0)
			{
				wallFollowLeftStrong(targetGrid, boundsX, boundsY, microMouseArray[i], i + 2);
				(*microMouseArray[i]).wallFollow = 1;
			}
			if((*microMouseArray[i]).wallFollow != 1)
			{
				wallFollowRightStrong(targetGrid, boundsX, boundsY, microMouseArray[i], i + 2);
				(*microMouseArray[i]).wallFollow = 0;
			}
		}
		i++;
	}
};
/*
 * Function which walks microMousebot until it reaches target
 */
int countStepsFunc() {
	int i, j;
	int timeSlotsCount = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	int numBots = getNumBots();
	//Create and allocate memory for grid and targetGrid
	int **targetGrid = (int**)malloc(boundsX * sizeof(int*));
	int **mockGrid = (int**)malloc(boundsX * sizeof(int*));
	for (i = 0; i < boundsX; i++) {
		targetGrid[i] = (int*)malloc(boundsY * sizeof(int));
		mockGrid[i] = (int*)malloc(boundsY * sizeof(int));
	}
	resetTargetGrid(boundsX, boundsY, targetGrid);
	generateMaze(targetGrid, boundsX, boundsY);
	int countO = countOpen(targetGrid, boundsX, boundsY);
	copyGrid(boundsX, boundsY, targetGrid, mockGrid);
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
		resetmicroMouseBot(microMouseArray[i], boundsX, boundsY);
		placemicroMouseOnRandomSpot(targetGrid, boundsX, boundsY, microMouseArray[i]);
		targetGrid[( * (microMouseArray[i])).nx][( * (microMouseArray[i])).ny] = i + 2;
	}
	int val = 0;
	int numMoves;
	int bla = 0;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	//While loop which runs until microMousebot reaches the target on the grid
	while ( (mazeFullyMapped( (*(microMouseArray[0])).microMouseMappedGrid, boundsX, boundsY)) < countO) {
		moveMicroMouseArray(targetGrid,boundsX,boundsY,microMouseArray);
		printMicroMouseArrayGrid(boundsX, boundsY, targetGrid,microMouseArray);
		usleep(30000);
		timeSlotsCount++;
		if (timeSlotsCount > 2000) {
			return (-5);
		}
	}
	return timeSlotsCount;
};
