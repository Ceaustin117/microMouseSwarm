#ifndef WALLFOLLOW_H
#define WALLFOLLOW_H

#include "microMouse.h"

void wallFollowRightStrong(int **maze, int microMouseNum, microMouseBot *microMouse);
void wallFollowLeftStrong(int **maze, int microMouseNum, microMouseBot *microMouse);
void wallFollowLeft(int **maze, microMouseBot *microMouse);
void wallFollowLeft2(int **maze, microMouseBot *microMouse);
void wallFollowRight(int **maze, microMouseBot *microMouse);

#endif /* WALLFOLLOW_H */
