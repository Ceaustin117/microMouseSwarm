#include <stdio.h>
#include "staticVars.h"
#include "microMouse.h"
#include "print.h"

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define KYEL "\x1B[33m"
#define KGRE "\x1B[32m"
#define KPINK "\x1B[35m"
/*
   Print Maze
 */
void printMaze(int **maze)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	//Loop through maze and print out all possible values in different colors
	for(i = 0 ; i< boundsX; i++){
		for (j =0 ; j < boundsY; j++){
			switch(maze[i][j]) {
				case 0:
					printf("0 ");
					break;
				case 1:
					printf("%d ", maze[i][j]);
					break;
				case 2:
					printf("%d ", maze[i][j]);
					break;
				case 3:
					printf("%d ", maze[i][j]);
					break;
				case 'W':
					printf("0 ");
					break;
				case 5:
					printf("%d ", maze[i][j]);
					break;
				case 9:
					printf("%d ", maze[i][j]);
					break;
				default:
					printf("X ");
					break;
			}
		}
		printf("\n");
	}
	printf("------------------------\n");
};
/*
   Print Maze from mouse view
 */
void printmicroMouseMaze(int **maze, microMouseBot * microMouse) {
	int i = 0;
	int j = 0;
	int k = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	for(k = 0; k < 10; k++)
	{
		printf(" \n\n\n\n\n\n\n\n\n\n");
	}
	//Loop through maze and print out all possible values in different colors
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (i == ( * microMouse).nx && j == ( * microMouse).ny) {
				printf("2 ");
			} else {
				switch (maze[i][j]) {
					case 0:
						printf("0 ");
						break;
					case 1:
						printf("%d ", maze[i][j]);
						break;
					case 2:
						printf("%d ", maze[i][j]);
						break;
					case 3:
						printf("%d ", maze[i][j]);
						break;
					case 4:
						printf("%d ", maze[i][j]);
						break;
					case 5:
						printf("%d ", maze[i][j]);
						break;
					case 9:
						printf("%d ", maze[i][j]);
						break;
					default:
						printf("X ");
						break;
				}
			}
		}
		printf("\n");
	}
	printf("------------------------\n");
};
/*
 * Print maze from microMouseArray view
 */
void printMicroMouseArrayMaze(int ** maze, microMouseBot ** microMouseArray) {
	int i = 0;
	int j = 0;
	int k = 0;
	int mazeNum = 0;
	int boundsX = getBoundsX();
	int boundsY = getBoundsY();
	for(k = 0; k < 10; k++)
	{
		printf(" \n\n\n\n\n\n\n\n\n\n");
	}
	//Loop through maze and print out all possible values in different colors
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if( (*(microMouseArray[0])).nx == i && (*(microMouseArray[0])).ny == j){
				printf("%sM ", KRED);
			} 
			else if( microMouseArrayCheck(i,j,microMouseArray) == 1 ){
				printf("%sM ", KYEL);
			} 
			else if(microMouseArrayCheckFirst(i,j,microMouseArray) == 0)
			{
				printf("%s0 ", KGRE);
			}
			else {
			mazeNum = microMouseArrayMazeCheck(i,j,microMouseArray); 
				switch (mazeNum) {
					case 0:
						printf("%s0 ", KWHT);
						break;
					case 1:
						printf("%s1 ", KBLU);
						break;
				}
			}
		}
		printf("\n");
	}
	printf("------------------------\n");
};
