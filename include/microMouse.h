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

extern void microMouseMakeArray(int **maze,microMouseBot **microMouseArray);
extern void microMouseBotReset(microMouseBot *microMouse);
extern int microMouseArrayCheck(int i,int j, microMouseBot **microMouseArray);
extern int microMouseArrayMazeCheck(int i,int j, microMouseBot **microMouseArray);
extern int microMouseArrayCheckFirst(int i, int j, microMouseBot ** microMouseArray);
extern void microMouseArrayMapSharing(int** targetGrid, int index, microMouseBot **microMouseArray);
extern void microMousePlaceOnRandomSpot(int **maze, microMouseBot *microMouse);

static int microMouseCheckForNeighbor(microMouseBot *microMouse, microMouseBot *microMouse2);
static void microMouseShareMapping(microMouseBot *microMouse, microMouseBot *microMouse2);

#endif /* MICROMOUSE_H */


