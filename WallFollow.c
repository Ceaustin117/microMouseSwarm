#include "staticVars.h"
#include "functions.h"
/* 
 *Wall follow  Left
 */
void wallFollowRightStrong(int **maze, int width, int height,microMouseBot *microMouse, int microMouseNum) {
	int i = 0;
	int j = 0;
	//If robot facing right
	if((*microMouse).dir==0)
	{
		//if right open
		if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny - 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx + 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny + 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny++;
			(*microMouse).dir = 2;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 2;
		}
	}
	//Else If robot facing left
	else if((*microMouse).dir == 1)
	{
		//if right open
		if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny + 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx - 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny - 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 3;
		}
	}
	//Else If robot facing up
	else if((*microMouse).dir == 2)
	{
		//if right open
		if(checkForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx + 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny + 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(checkForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx - 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 1;
		}
	}
	//Else If robot facing down
	else if((*microMouse).dir == 3)
	{
		//if right open
		if(checkForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx - 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny - 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open, turn left and go left
		else if(checkForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx + 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 0;
		}
	}
};
/* 
 *Wall follow  Left
 */
void wallFollowLeftStrong(int **maze, int width, int height,microMouseBot *microMouse, int microMouseNum) {
	int i = 0;
	int j = 0;
	//If robot facing right
	if((*microMouse).dir==0)
	{
		//if left open
		if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny + 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx + 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny - 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny--;
			(*microMouse).dir = 3;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 3;
		}
	}
	//Else If robot facing left
	else if((*microMouse).dir == 1)
	{
		//if left open
		if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny - 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx - 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny + 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 2;
		}
	}
	//Else If robot facing up
	else if((*microMouse).dir == 2)
	{
		//if left open
		if(checkForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx - 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny + 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(checkForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx + 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 0;
		}
	}
	//Else If robot facing down
	else if((*microMouse).dir == 3)
	{
		//if left open
		if(checkForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx + 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//if forward open
		else if(checkForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx][(*microMouse).ny - 1] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open, turn right and go right
		else if(checkForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 'W';
			maze[(*microMouse).nx - 1][(*microMouse).ny] = microMouseNum;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 1;
		}
	}
};
/* 
 *Wall follow  Left
 */
void wallFollowLeft(int **maze, int width, int height,microMouseBot *microMouse) {
	int i = 0;
	int j = 0;
	//If robot facing right
	if((*microMouse).dir==0)
	{
		//if left open
		if(maze[(*microMouse).nx][(*microMouse).ny + 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny + 1] != 3 )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 2;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else if forward open
		else if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx + 1][(*microMouse).ny] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx+1][(*microMouse).ny] = 2;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny - 1] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 2;
			(*microMouse).ny--;
			(*microMouse).dir = 3;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 3;
		}
	}
	//Else If robot facing left
	else if((*microMouse).dir == 1)
	{
		//if left open
		if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny - 1] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 2;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else if forward open
		else if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx - 1][(*microMouse).ny] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 2;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(maze[(*microMouse).nx][(*microMouse).ny + 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny + 1] != 3 )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 2;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 2;
		}
	}
	//Else If robot facing up
	else if((*microMouse).dir == 2)
	{
		//if left open
		if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx - 1][(*microMouse).ny] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 2;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//if forward open
		else if(maze[(*microMouse).nx][(*microMouse).ny + 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny + 1] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 2;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx + 1][(*microMouse).ny] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx + 1][(*microMouse).ny] = 2;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 0;
		}
	}
	//Else If robot facing down
	else if((*microMouse).dir == 3)
	{
		//if left open
		if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx + 1][(*microMouse).ny] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx + 1][(*microMouse).ny] = 2;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//if forward open
		else if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny - 1] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 2;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open, turn right and go right
		else if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx - 1][(*microMouse).ny] != 3)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 2;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 1;
		}
	}
};
/* 
 *Wall follow  Left
 */
void wallFollowLeft2(int **maze, int width, int height,microMouseBot *microMouse) {
	int i = 0;
	int j = 0;
	//If robot facing right
	if((*microMouse).dir==0)
	{
		//if left open
		if(maze[(*microMouse).nx][(*microMouse).ny + 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny + 1] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 3;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else if forward open
		else if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx + 1][(*microMouse).ny] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx+1][(*microMouse).ny] = 3;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny - 1] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 3;
			(*microMouse).ny--;
			(*microMouse).dir = 3;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 3;
		}
	}
	//Else If robot facing left
	else if((*microMouse).dir == 1)
	{
		//if left open
		if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny - 1] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 3;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else if forward open
		else if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx - 1][(*microMouse).ny] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 3;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(maze[(*microMouse).nx][(*microMouse).ny + 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny + 1] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 3;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 2;
		}
	}
	//Else If robot facing up
	else if((*microMouse).dir == 2)
	{
		//if left open
		if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1 &&  maze[(*microMouse).nx - 1][(*microMouse).ny] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 3;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//if forward open
		else if(maze[(*microMouse).nx][(*microMouse).ny + 1] != 1 &&  maze[(*microMouse).nx][(*microMouse).ny + 1] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 3;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open
		else if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1 &&  maze[(*microMouse).nx + 1][(*microMouse).ny] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx + 1][(*microMouse).ny] = 3;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 0;
		}
	}
	//Else If robot facing down
	else if((*microMouse).dir == 3)
	{
		//if left open
		if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx + 1][(*microMouse).ny] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx + 1][(*microMouse).ny] = 3;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//if forward open
		else if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1 && maze[(*microMouse).nx][(*microMouse).ny - 1] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 3;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if right open, turn right and go right
		else if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1 && maze[(*microMouse).nx - 1][(*microMouse).ny] != 2)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 3;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//else turn right
		else
		{
			(*microMouse).dir = 1;
		}
	}
};
/* 
 *Wall follow  Right
 */
void wallFollowRight(int **maze, int width, int height,microMouseBot *microMouse) {
	int i = 0;
	int j = 0;
	//If robot facing right
	if((*microMouse).dir==0)
	{
		//if right open
		if(maze[(*microMouse).nx][(*microMouse).ny - 1] != (1 || 2)  )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 2;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else if forward open
		else if(maze[(*microMouse).nx + 1][(*microMouse).ny] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx+1][(*microMouse).ny] = 2;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(maze[(*microMouse).nx][(*microMouse).ny + 1] != (1 || 2)  )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 2;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 2;
		}
	}
	//Else If robot facing left
	else if((*microMouse).dir == 1)
	{
		//if right open
		if(maze[(*microMouse).nx][(*microMouse).ny + 1] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 2;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 2;
		}
		//else if forward open
		else if(maze[(*microMouse).nx - 1][(*microMouse).ny] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 2;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(maze[(*microMouse).nx][(*microMouse).ny - 1] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 2;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 3;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 3;
		}
	}
	//Else If robot facing up
	else if((*microMouse).dir == 2)
	{
		//if  right open
		if(maze[(*microMouse).nx + 1][(*microMouse).ny] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx + 1][(*microMouse).ny] = 2;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//if forward open
		else if(maze[(*microMouse).nx][(*microMouse).ny + 1] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny + 1] = 2;
			(*microMouse).ny++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(maze[(*microMouse).nx - 1][(*microMouse).ny] != (1 || 2) )
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 2;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 1;
		}
	}
	//Else If robot facing down
	else if((*microMouse).dir == 3)
	{
		//if right open
		if(maze[(*microMouse).nx - 1][(*microMouse).ny] != 1)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx - 1][(*microMouse).ny] = 2;
			(*microMouse).nx--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 1;
		}
		//if forward open
		else if(maze[(*microMouse).nx][(*microMouse).ny - 1] != 1)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx][(*microMouse).ny - 1] = 2;
			(*microMouse).ny--;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
		}
		//else if left open
		else if(maze[(*microMouse).nx + 1][(*microMouse).ny] != 1)
		{
			maze[(*microMouse).nx][(*microMouse).ny] = 4;
			maze[(*microMouse).nx + 1][(*microMouse).ny] = 2;
			(*microMouse).nx++;
			(*microMouse).microMouseMappedGrid[(*microMouse).nx][(*microMouse).ny] = 0;
			(*microMouse).dir = 0;
		}
		//else turn left
		else
		{
			(*microMouse).dir = 0;
		}
	}
};
