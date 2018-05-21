#include "staticVars.h"
#include "functions.h"

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define KYEL "\x1B[33m"
#define KGRE "\x1B[32m"
#define KPINK "\x1B[35m"
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
	for(k = 0; k < 10; k++)
	{
		printf(" \n\n\n\n\n\n\n\n\n\n");
	}
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
/*
 * Print Grid
 */
void printMicroMouseArrayGrid(int boundsX, int boundsY, int * * grid, microMouseBot ** microMouseArray) {
	int i = 0;
	int j = 0;
	int k = 0;
	int gridNum = 0;
	for(k = 0; k < 10; k++)
	{
		printf(" \n\n\n\n\n\n\n\n\n\n");
	}
	//Loop through grid and print out all possible values in different colors
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if( (*(microMouseArray[0])).nx == i && (*(microMouseArray[0])).ny == j){
				printf("%sM ", KRED);
			} 
			else if( checkMicroMouseArray(i,j,microMouseArray) == 1 ){
				printf("%sM ", KYEL);
			} 
			else if(checkFirstMicroMouseBot(i,j,microMouseArray) == 0)
			{
				printf("%s0 ", KGRE);
			}
			else {
			gridNum = checkMicroMouseArrayGrids(i,j,microMouseArray); 
				switch (gridNum) {
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
/*
 *
 */
int checkMicroMouseArray(int i,int j, microMouseBot ** microMouseArray)
{
	int val = 0;
	int k = 0;
	int numBots = 0;
	numBots = getNumBots();
	for(k = 0; k < numBots; k++)
	{
	 if( (*(microMouseArray[k])).nx == i && (*(microMouseArray[k])).ny == j )
	  {
		val = 1;
	  }
	}
	return val;
};
/*
 * 
 */
int checkMicroMouseArrayGrids(int i,int j, microMouseBot ** microMouseArray)
{
	int val = 1;
	int k = 0;
	int numBots = 0;
	numBots = getNumBots();
	for(k = 0; k < numBots; k++)
	{
	 if( (*(microMouseArray[k])).microMouseMappedGrid[i][j] != 1)
	  {
		val = (*(microMouseArray[k])).microMouseMappedGrid[i][j];
	  }
	}
	return val;
};
/*
 *
 */
int checkFirstMicroMouseBot(int i,int j,microMouseBot ** microMouseArray)
{
	int val = 1;
	if( (*(microMouseArray[0])).microMouseMappedGrid[i][j] == 0)
	{
		return 0;
	}
	else
	return 1;
}
