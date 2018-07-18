#include "staticVars.h"
#include "movement.h"
#include "wallFollow.h"
#include "maze.h"
/* 
 *Wall follow  Right Strong
 */
void wallFollowRight(int **maze,  int microMouseNum, microMouseBot *microMouse) {
	
	switch( (*microMouse).dir )
	{
		case(0):
			wallFollowRightFacingRightMove(maze,microMouseNum,microMouse);
			break;
		case(1):
			wallFollowRightFacingLeftMove(maze,microMouseNum,microMouse);
			break;
		case(2):
			wallFollowRightFacingUpMove(maze,microMouseNum,microMouse);
			break;
		case(3):
			wallFollowRightFacingDownMove(maze, microMouseNum, microMouse);
			break;
	}
};
/* 
 *Wall follow  Left
 */
void wallFollowLeft(int **maze,int microMouseNum, microMouseBot *microMouse) {

	
	switch( (*microMouse).dir )
	{
		case(0):
			wallFollowLeftFacingRightMove(maze,microMouseNum,microMouse);
			break;
		case(1):
			wallFollowLeftFacingLeftMove(maze,microMouseNum,microMouse);
			break;
		case(2):
			wallFollowLeftFacingUpMove(maze,microMouseNum,microMouse);
			break;
		case(3):
			wallFollowLeftFacingDownMove(maze, microMouseNum, microMouse);
			break;
	}
};
/*
 * move the microMouseBot
 */
static void wallFollowMoveInDir(int **maze, microMouseBot *microMouse)
{
		switch( (*microMouse).dir )
		{
			case(0):
				(*microMouse).nx++;
				break;
			case(1):
				(*microMouse).nx--;
				break;
			case(2):
				(*microMouse).ny++;
				break;
			case(3):
				(*microMouse).ny--;
				break;
			
		}
};
/*
 * move the microMouseBot
 */
static void wallFollowMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		maze[(*microMouse).nx][(*microMouse).ny] = 'W';
		(*microMouse).microMouseMappedMaze[(*microMouse).nx][(*microMouse).ny] = 0;
		//
		wallFollowMoveInDir(maze,microMouse);
		//
		maze[(*microMouse).nx][(*microMouse).ny] = microMouseNum;
		(*microMouse).microMouseMappedMaze[(*microMouse).nx][(*microMouse).ny] = 0;
};
//
static void wallFollowRightFacingRightMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if right open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			(*microMouse).dir = 3;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if left open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			(*microMouse).dir = 2;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn left
		else
		{
			(*microMouse).dir = 2;
		}
};
//
static void wallFollowRightFacingLeftMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if right open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			(*microMouse).dir = 2;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if left open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			(*microMouse).dir = 3;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn left
		else
		{
			(*microMouse).dir = 3;
		}
};
//
static void wallFollowRightFacingUpMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if right open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 0;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if left open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 1;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn left
		else
		{
			(*microMouse).dir = 1;
		}
};
//
static void wallFollowRightFacingDownMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if right open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 1;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if left open, turn left and go left
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 0;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn left
		else
		{
			(*microMouse).dir = 0;
		}
};
//
static void wallFollowLeftFacingRightMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if left open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			(*microMouse).dir = 2;
			wallFollowMove(maze, microMouseNum, microMouse);

		}
		//else if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if right open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			(*microMouse).dir = 3;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn right
		else
		{
			(*microMouse).dir = 3;
		}
};
//
static void wallFollowLeftFacingLeftMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if left open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			(*microMouse).dir = 3;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if right open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			(*microMouse).dir = 2;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn right
		else
		{
			(*microMouse).dir = 2;
		}
};
//
static void wallFollowLeftFacingUpMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if left open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 1;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny + 1) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if right open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 0;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn right
		else
		{
			(*microMouse).dir = 0;
		}
};
//
static void wallFollowLeftFacingDownMove(int **maze, int microMouseNum, microMouseBot *microMouse)
{
		//if left open
		if(mazeCheckForWallOrBot(maze, (*microMouse).nx + 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 0;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//if forward open
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx, (*microMouse).ny - 1) == 0)
		{
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else if right open, turn right and go right
		else if(mazeCheckForWallOrBot(maze, (*microMouse).nx - 1, (*microMouse).ny) == 0)
		{
			(*microMouse).dir = 1;
			wallFollowMove(maze, microMouseNum, microMouse);
		}
		//else turn right
		else
		{
			(*microMouse).dir = 1;
		}
};
