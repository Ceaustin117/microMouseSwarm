#ifndef WALLFOLLOW_H
#define WALLFOLLOW_H

#include "microMouse.h"

extern void wallFollowRight(int **maze,  int microMouseNum, microMouseBot *microMouse);
extern void wallFollowLeft(int **maze,int microMouseNum, microMouseBot *microMouse);

static void wallFollowMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowMoveInDir(int **maze, microMouseBot *microMouse);
static void wallFollowRightFacingRightMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowRightFacingLeftMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowRightFacingUpMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowRightFacingDownMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowLeftFacingRightMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowLeftFacingLeftMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowLeftFacingUpMove(int **maze, int microMouseNum, microMouseBot *microMouse);
static void wallFollowLeftFacingDownMove(int **maze, int microMouseNum, microMouseBot *microMouse);

#endif /* WALLFOLLOW_H */
