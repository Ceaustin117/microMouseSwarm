#include <stdlib.h>
#include "staticVars.h"
#include "microMouse.h"
/*
   check if microMouse near another microMouse
 */
int microMouseCheckForNeighbor(microMouseBot * microMouse, microMouseBot * microMouse2) {
        int i = 0;
        int j = 0;
        int x1 = ( * microMouse).nx;
        int y1 = ( * microMouse).ny;
        int x2 = ( * microMouse2).nx;
        int y2 = ( * microMouse2).ny;
        int val = 0;
        //if microMouse2 is 1 right of microMouse
        if (x1 == x2 - 1 && y1 == y2) {
                val = 1;
        }
        //else if microMouse2 is 1 left of microMouse
        else if (x1 == x2 + 1 && y1 == y2) {
                val = 1;
        }
        //else if microMouse2 is 1 down of microMouse
        else if (x1 == x2 && y1 == y2 + 1) {
                val = 1;
        }
        //else if microMouse2 is 1 up of microMouse
        else if (x1 == x2 && y1 == y2 - 1) {
                val = 1;
        }
        return val;
}
/*
//microMouse share mapping
*/
void microMouseShareMapping(microMouseBot *microMouse, microMouseBot * microMouse2) {
	int i = 0;
	int j = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (( * microMouse).microMouseMappedMaze[i][j] == 0 || ( * microMouse2).microMouseMappedMaze[i][j] == 0
					|| (*microMouse).microMouseMappedMaze[i][j]>1) {
				( * microMouse).microMouseMappedMaze[i][j] = 0;
				( * microMouse2).microMouseMappedMaze[i][j] = 0;
			}
		}
	}
};
/*
   Reset microMousebot values
 */
void microMouseBotReset(microMouseBot *microMouse) {
	int i = 0;
	int j = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	( * microMouse).wallFollow = (-1);
	( * microMouse).nx = -1;
	( * microMouse).ny = -1;
	( * microMouse).tx = -1;
	( * microMouse).ty = -1;
	( * microMouse).hasGone = -1;
	( * microMouse).dir = 0;
	( * microMouse).microMouseMappedMaze = calloc(boundsX, sizeof(int * ));
	for (i = 0; i < boundsX; i++) {
		( * microMouse).microMouseMappedMaze[i] = calloc(boundsY, sizeof(int));
		for (j = 0; j < boundsY; j++) {
			( * microMouse).microMouseMappedMaze[i][j] = 1;
		}
	}
};
/*
 *
 */
int microMouseArrayCheck(int i,int j, microMouseBot ** microMouseArray)
{
	int val = 0;
	int k = 0;
	int numBots = 0;
	numBots = getNumBots();
	for(k = 0; k < numBots; k++)
	{
	 if( (*(microMouseArray[k])).nx == i && (*(microMouseArray[k])).ny == j )
	  {
		val = 1;
	  }
	}
	return val;
};
/*
 * 
 */
int microMouseArrayMazeCheck(int i, int j, microMouseBot ** microMouseArray)
{
	int val = 1;
	int k = 0;
	int numBots = 0;
	numBots = getNumBots();
	for(k = 0; k < numBots; k++)
	{
	 if( (*(microMouseArray[k])).microMouseMappedMaze[i][j] != 1)
	  {
		val = (*(microMouseArray[k])).microMouseMappedMaze[i][j];
	  }
	}
	return val;
};
/*
 *
 */
int microMouseArrayCheckFirst(int i,int j,microMouseBot ** microMouseArray)
{
	int val = 1;
	if( (*(microMouseArray[0])).microMouseMappedMaze[i][j] == 0)
	{
		return 0;
	}
	else
	return 1;
}
/*
 *
 */
void microMouseArrayMapSharing(int **maze, int index, microMouseBot** microMouseArray)
{
	int numBots = getNumBots();
        int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	int i = 0;
	while(i < numBots)
	{
		if(i != index)
		{
			if(microMouseCheckForNeighbor(microMouseArray[index], microMouseArray[i]) == 1) {
				microMouseShareMapping(microMouseArray[index], microMouseArray[i]);
			}
		}
		i++;
	}
};
//Place microMouse on random open spot on maze
void microMousePlaceOnRandomSpot(int **maze, microMouseBot *microMouse) {
	int i = 0;
	int j = 0;
	int flag = 0;
        int boundsX = getBoundsX();
	int boundsY = getBoundsY();
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
