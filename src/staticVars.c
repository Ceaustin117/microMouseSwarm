/*
   private variables
 */
static int boundsX;
static int boundsY;
static int numMoves;
static int numTests;
static int numBots;
static int algChoice;
/*
   Setters
 */
void setAlgChoice (int a)
{
	algChoice = a;
};
void setBoundsX (int x)
{
	boundsX = x;
};
void setBoundsY (int y)
{
	boundsY = y;
};
void setNumMoves (int m)
{
	numMoves = m;
};
int setNumTests(int n)
{
	numTests = n;
};
int setNumBots(int n)
{
	numBots = n;
};
/*
   Adders
 */
void addToNumMoves (int s)
{
	numMoves = numMoves + s;
};
/*
   Getters
 */
int getBoundsX (void)
{
	return boundsX;
};
int getBoundsY (void)
{
	return boundsY;
};
int getNumMoves (void)
{
	return numMoves;
}
int getNumTests(void)
{
	return numTests;
};
int getNumBots(void)
{
	return numBots;
};
int getAlgChoice(void)
{
	return algChoice;
}
