#include"functions.h"
/*
   check if microMouse near another microMouse
 */
int checkNearOthermicroMouse(microMouseBot * microMouse, microMouseBot * microMouse2) {
        int i = 0;
        int j = 0;
        int x1 = ( * microMouse).nx;
        int y1 = ( * microMouse).ny;
        int x2 = ( * microMouse2).nx;
        int y2 = ( * microMouse2).ny;
        int val = 0;
        //if microMouse2 is 1 right of microMouse
        if (x1 == x2 - 1 && y1 == y2) {
                val = 1;
        }
        //else if microMouse2 is 1 left of microMouse
        else if (x1 == x2 + 1 && y1 == y2) {
                val = 1;
        }
        //else if microMouse2 is 1 down of microMouse
        else if (x1 == x2 && y1 == y2 + 1) {
                val = 1;
        }
        //else if microMouse2 is 1 up of microMouse
        else if (x1 == x2 && y1 == y2 - 1) {
                val = 1;
        }
        return val;
}
/*
//microMouse share mapping
*/
void microMouseShareMapping(int boundsX, int boundsY, microMouseBot * microMouse, microMouseBot * microMouse2) {
	int i = 0;
	int j = 0;
	for (i = 0; i < boundsX; i++) {
		for (j = 0; j < boundsY; j++) {
			if (( * microMouse).microMouseMappedGrid[i][j] == 0 || ( * microMouse2).microMouseMappedGrid[i][j] == 0
					|| (*microMouse).microMouseMappedGrid[i][j]>1) {
				( * microMouse).microMouseMappedGrid[i][j] = 0;
				( * microMouse2).microMouseMappedGrid[i][j] = 0;
			}
		}
	}
};
/*
   Reset microMousebot values
 */
void resetmicroMouseBot(microMouseBot * microMouse, int boundsX, int boundsY) {
	int i = 0;
	int j = 0;
	( * microMouse).wallFollow = (-1);
	( * microMouse).nx = -1;
	( * microMouse).ny = -1;
	( * microMouse).tx = -1;
	( * microMouse).ty = -1;
	( * microMouse).hasGone = -1;
	( * microMouse).dir = 0;
	( * microMouse).microMouseMappedGrid = calloc(boundsX, sizeof(int * ));
	for (i = 0; i < boundsX; i++) {
		( * microMouse).microMouseMappedGrid[i] = calloc(boundsY, sizeof(int));
		for (j = 0; j < boundsY; j++) {
			( * microMouse).microMouseMappedGrid[i][j] = 1;
		}
	}
};

