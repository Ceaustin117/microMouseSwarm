#ifndef WALLFOLLOW_H
#define WALLFOLLOW_H

#include "microMouse.h"

extern void wallFollowRightStrong(int **maze, int microMouseNum, microMouseBot *microMouse);
extern void wallFollowLeftStrong(int **maze, int microMouseNum, microMouseBot *microMouse);
extern void wallFollowLeft(int **maze, microMouseBot *microMouse);
extern void wallFollowLeft2(int **maze, microMouseBot *microMouse);
extern void wallFollowRight(int **maze, microMouseBot *microMouse);

#endif /* WALLFOLLOW_H */
