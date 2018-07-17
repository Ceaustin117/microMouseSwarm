#include<stdlib.h>
#include "staticVars.h"
#include "maze.h"
//Check for wall or bot
int mazeCheckForWallOrBot(int **maze, int nx, int ny) {
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
int mazeFullyMapped(int **maze) {
	int i = 0;
	int j = 0;
	int val = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (maze[i][j] == 0) {
				val++;
			}
		}
	}
	return val;
};
//
void mazeCopy(int **maze1, int **maze2 ) {

        int i = 0;
        int j = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
        for(i = 0;i < boundsX;i++)
        {
                for(j = 0;j < boundsY;j++)
                {
                        maze2[i][j] = maze1[i][j];
                }
        }
};
//
void mazeReset(int **maze) {
        int i = 0;
        int j = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
        for(i = 0;i < boundsX;i++)
        {
                for(j = 0;j < boundsY;j++)
                {
                        maze[i][j] = 0;
                }
        }
};
//
void mazeCarve(int **maze,int x, int y) {

	int x1, y1;
	int x2, y2;
	int dx, dy;
	int dir, count;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	dir = rand() % 4;
	count = 0;
	while(count < 4) {
		dx = 0; dy = 0;
		switch(dir) {
			case 0:  dx = 1;  break;
			case 1:  dy = 1;  break;
			case 2:  dx = -1; break;
			default: dy = -1; break;
		}
		x1 = x + dx;
		y1 = y + dy;
		x2 = x1 + dx;
		y2 = y1 + dy;
		if(   x2 > 0 && x2 < boundsX && y2 > 0 && y2 < boundsY
		             && maze[x1][y1] == 1 && maze[x2][y2] == 1) {
			maze[x1][y1] = 0;
			maze[x2][y2] = 0;
			x = x2; 
                        y = y2;
			dir = rand() % 4;
			count = 0;
		} else {
			dir = (dir + 1) % 4;
			count += 1;
		}
	}

};
//
void mazeGenerate(int **maze) {

	int x = 0;
	int y = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	// Initialize the maze with all values to 1  
	for(x = 0; x < boundsX;x++)
		for(y=0;y < boundsY; y++) {
			maze[x][y] = 1;
		}   
	maze[1][1] = 0;
	// Carve the maze.  
	for(y = 1; y < boundsY; y += 2) {
		for(x = 1; x < boundsX; x += 2) {
			mazeCarve(maze,x,y);
		}
	}   
};
