#ifndef MICROMOUSE_H
#define MICROMOUSE_H
/*
 * Declare typedef struct microMouseBot
 */
typedef struct microMouseBot
{
	int wallFollow;
	int nx;
	int ny;
	int tx;
	int ty;
	int point;
	int hasGone;
	int dir;
	int **microMouseMappedMaze;
}microMouseBot;

extern int microMouseCheckForNeighbor(microMouseBot *microMouse, microMouseBot *microMouse2);
void microMouseShareMapping(microMouseBot *microMouse, microMouseBot *microMouse2);
void microMouseBotReset(microMouseBot *microMouse);
extern int microMouseArrayCheck(int i,int j, microMouseBot **microMouseArray);
extern int microMouseArrayMazeCheck(int i,int j, microMouseBot **microMouseArray);
extern int microMouseArrayCheckFirst(int i, int j, microMouseBot ** microMouseArray);
extern void microMouseShareMapping(microMouseBot *microMouse, microMouseBot *microMouse2);
void microMouseArrayMapSharing(int** targetGrid, int index, microMouseBot **microMouseArray);
void microMousePlaceOnRandomSpot(int **maze, microMouseBot *microMouse);
#endif /* MICROMOUSE_H */


