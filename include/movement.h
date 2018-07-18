#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "microMouse.h"

extern void movementMicroMouseArray(int **maze, microMouseBot **microMouseArray);
extern int movementCountOpen(int **maze);
extern int movementCountStepsFunc();

#endif /* MOVEMENT_H */
