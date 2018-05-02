#include "staticVars.h"
#include "functions.h"
/*
   Print Grid
 */
void printGrid(int boundsX, int boundsY,int **grid)
{
	int i = 0;
	int j = 0;
	int k;
	//Loop through grid and print out all possible values in different colors
	for(i = 0 ; i< boundsX; i++){
		for (j =0 ; j < boundsY; j++){
			switch(grid[i][j]) {
				case 0:
					printf("0 ");
					break;
				case 1:
					printf("%d ", grid[i][j]);
					break;
				case 2:
					printf("%d ", grid[i][j]);
					break;
				case 3:
					printf("%d ", grid[i][j]);
					break;
				case 'W':
					printf("0 ");
					break;
				case 5:
					printf("%d ", grid[i][j]);
					break;
				case 9:
					printf("%d ", grid[i][j]);
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
   Print Grid
 */
void printmicroMouseGrid(int boundsX, int boundsY, int * * grid, microMouseBot * microMouse) {
	int i = 0;
	int j = 0;
	int k;
	//Loop through grid and print out all possible values in different colors
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (i == ( * microMouse).nx && j == ( * microMouse).ny) {
				printf("2 ");
			} else {
				switch (grid[i][j]) {
					case 0:
						printf("0 ");
						break;
					case 1:
						printf("%d ", grid[i][j]);
						break;
					case 2:
						printf("%d ", grid[i][j]);
						break;
					case 3:
						printf("%d ", grid[i][j]);
						break;
					case 4:
						printf("%d ", grid[i][j]);
						break;
					case 5:
						printf("%d ", grid[i][j]);
						break;
					case 9:
						printf("%d ", grid[i][j]);
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
