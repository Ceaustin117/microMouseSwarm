#include "staticVars.h"
#include "movement.h"
#include <stdio.h>
#include <stdlib.h>
/*
   main function
 */
int main(int argc, char *argv[])
{
	int i = 0;
	int temp = 0;
	int timeSlotsSum = 0;
	int timeRun = 0;
	setBoundsX(atoi(argv[1]));
	setBoundsY(atoi(argv[2]));
	setAlgChoice(atoi(argv[3]));
	setNumBots(atoi(argv[4]));
	int numRuns = atoi(argv[5]);
	/*run countStepsFunc and determine number of timeSlots for microMouseArray to form shape*/
	while(i < numRuns)
	{
		temp = movementCountStepsFunc();
		if(temp >  (-1) )
		{
			timeSlotsSum+=temp;
			timeRun++;
			i++;
		}
		else
		{
			//
		}
	}
	//Tests complete, simulation is finished, print avg #timeSlots,,avg #moves and number of numTests
	printf("\n------------------------------------------\n");
	printf("Done with simulation\n");
	printf("Maze length: %d, width: %d, algChoice: %d,# of robots in swarm: %d, # of tests: %d\n"
		,getBoundsX(),getBoundsY(),atoi(argv[3]),atoi(argv[4]),numRuns);
	printf("average timeSlots==%d\n",timeSlotsSum / timeRun);
	/* done with main function return 0 and exit program*/
	return 0;
}
