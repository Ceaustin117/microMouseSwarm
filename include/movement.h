int checkForWallOrBot(int * * maze, int nx, int ny);
int mazeFullyMapped(int * * maze, int boundsX, int boundsY);
void placemicroMouseOnRandomSpot(int * * maze, int boundsX, int boundsY, microMouseBot * microMouse);
int countOpen(int * * maze, int width, int height);
void microMouseArrayMapSharing(int** targetGrid,int  boundsX,int  boundsY,microMouseBot** microMouseArray,int index);
void moveMicroMouseArray(int **targetGrid, int boundsX, int boundsY, microMouseBot** microMouseArray);
int countStepsFunc();
