#ifndef STATICVARS_H
#define STATICVARS_H

//setters
extern void setBoundsX (int x);
extern void setBoundsY (int y);
extern void setNumMoves (int m);
extern void setNumBots(int n);
extern void setAlgChoice(int a);
//adders
extern void addToNumMoves (int m);
//getters
extern int getBoundsX(void);
extern int getBoundsY(void);
extern int getNumMoves(void);
extern int getNumBots(void);
extern int getAlgChoice(void);

#endif /* STATICVARS_H */
