#include "staticVars.h"
#include "functions.h"
void copyGrid(int boundsX, int boundsY,int **grid1, int **grid2 ) {

        int i = 0;
        int j = 0;
        for(i=0;i<boundsX;i++)
        {
                for(j=0;j<boundsY;j++)
                {
                        grid2[i][j]= grid1[i][j];
                }
        }
};
/*
   Reset the target Grid to all 0's
 */
void resetTargetGrid(int boundsX, int boundsY,int **targetGrid) {
        int i = 0;
        int j = 0;
        /*Set all targetGrid values to 0*/
        for(i=0;i<boundsX;i++)
        {
                for(j=0;j<boundsY;j++)
                {
                        targetGrid[i][j]=1;
                }
        }
};
/*  
 *Carve the maze starting at x, y. 
 */
void carveMaze(int **maze, int width, int height, int x, int y) {

	int x1, y1;
	int x2, y2;
	int dx, dy;
	int dir, count;
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
		if(   x2 > 0 && x2 < width && y2 > 0 && y2 < height
				&& maze[x1][y1] == 1 && maze[x2][y2] == 1) {
			maze[x1][y1] = 0;
			maze[x2][y2] = 0;
			x = x2; y = y2;
			dir = rand() % 4;
			count = 0;
		} else {
			dir = (dir + 1) % 4;
			count += 1;
		}
	}

};
/* 
 *Generate maze in matrix maze with size width, height. 
 */
void generateMaze(int **maze, int width, int height) {

	int x, y;
	// Initialize the maze.   
	for(x = 0; x < width;x++)
		for(y=0;y<height; y++) {
			maze[x][y] = 1;
		}   
	maze[1][1] = 0;
	// Seed the random number generator. 
	srand(time(0));
	// Carve the maze.  
	for(y = 1; y < height; y += 2) {
		for(x = 1; x < width; x += 2) {
			carveMaze(maze, width, height, x, y);
		}
	}   
	// Set up the entry and exit. 
	//maze[0][1] = 0;
	//maze[(width - 2)][(height - 1)] = 0;
};
