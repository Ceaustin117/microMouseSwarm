#ifndef MAZE_H
#define MAZE_H

extern int mazeFullyMapped(int **maze);
extern int mazeCheckForWallOrBot(int **maze, int nx, int ny);
void mazeCopy(int **maze1, int **maze2 );
void mazeReset(int **maze);
void mazeCarve(int **maze, int x, int y);
void mazeGenerate(int **maze);

#endif /* MAZE_H */
