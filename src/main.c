/*Main function
 *argv[1]= X Dimension of the grid
 *argv[2]=Y Dimension of the grid
 */
#include "staticVars.h"
#include "functions.h"
/*
   main function
 */
int main(int argc, char *argv[])
{
	/*Declare and set to 0 local and static shared variables*/
	int i = 0;
	int j = 0;
	int boundsX = 0;
	int boundsY = 0;
	int loopIteration = 0;
	int timeSlotsSum = 0;
	int avgNumMoves = 0;
	int avgTimeSlots = 0;
	/*Define variables from user choice parameters*/
	boundsX=atoi(argv[1]);
	boundsY=atoi(argv[2]);
	/*Call setters for static vars*/
	setBoundsX(boundsX);
	setBoundsY(boundsY);
	/*declare time variables*/
	time_t now;
	time(&now);
	/*Define local Variables*/
	int sumMoves=0;
	int temp = 0;
	int timeRun = 0;
	int flag = 0;
	setAlgChoice(atoi(argv[3]));
	setNumBots(atoi(argv[4]));
	int numRuns = atoi(argv[5]);
	/* 
	 *Loop until number of Runs is complete
	 */
	/*run countStepsFunc and determine number of moves and timeSlots for microMouseArray to form shape*/
	while(i < numRuns)
	{
		temp = countStepsFunc();
		if(temp >  (-1) )
		{
			timeSlotsSum+=temp;
			timeRun++;
			sumMoves++;
			i++;
		}
		else
		{
			flag = 1;
		}
	}
	/*Print timeSlots and numMoves after one test and then increment loopIteration value*/
	/*
	 * Tests complete, simulation is finished, print avg #timeSlots,,avg #moves and number of numTests
	 */
	printf("\n------------------------------------------\n");
	printf("Done with simulation\n");
	printf("Maze length: %d, width: %d, algChoice: %d,# of robots in swarm: %d, # of tests: %d\n",boundsX,boundsY,atoi(argv[3]),atoi(argv[4]),numRuns);
	printf("average timeSlots==%d\n",timeSlotsSum / timeRun);
	/* done with main function return 0 and exit program*/
	return 0;
}
