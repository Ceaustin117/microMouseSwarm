#ifndef MAZE_H
#define MAZE_H

extern int mazeFullyMapped(int **maze);
extern int mazeCheckForWallOrBot(int **maze, int nx, int ny);
extern void mazeCopy(int **maze1, int **maze2 );
extern void mazeReset(int **maze);
extern void mazeCarve(int **maze, int x, int y);
extern void mazeGenerate(int **maze);

#endif /* MAZE_H */
