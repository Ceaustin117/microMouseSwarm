#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "microMouse.h"

extern int movementCountOpen(int **maze);
extern int movementCountStepsFunc();
extern void movementMicroMouseArray(int **maze, microMouseBot **microMouseArray);

#endif /* MOVEMENT_H */
