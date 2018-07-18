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

extern void microMouseShareMapping(microMouseBot *microMouse, microMouseBot *microMouse2);
extern void microMouseBotReset(microMouseBot *microMouse);
extern void microMouseShareMapping(microMouseBot *microMouse, microMouseBot *microMouse2);
extern void microMouseArrayMapSharing(int** targetGrid, int index, microMouseBot **microMouseArray);
extern void microMousePlaceOnRandomSpot(int **maze, microMouseBot *microMouse);
extern int microMouseArrayCheck(int i,int j, microMouseBot **microMouseArray);
extern int microMouseArrayMazeCheck(int i,int j, microMouseBot **microMouseArray);
extern int microMouseArrayCheckFirst(int i, int j, microMouseBot ** microMouseArray);
extern int microMouseCheckForNeighbor(microMouseBot *microMouse, microMouseBot *microMouse2);

#endif /* MICROMOUSE_H */


