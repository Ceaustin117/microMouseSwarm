#ifndef STATICVARS_H
#define STATICVARS_H

//Setters
extern void setAlgChoice (int a);
extern void setBoundsX (int x);
extern void setBoundsY (int y);
extern void setNumMoves (int m);
extern void setNumTests(int n);
extern void setNumBots(int n);
//Getters
extern int getBoundsX (void);
extern int getBoundsY (void);
extern int getNumMoves (void);
extern int getNumTests(void);
extern int getNumBots(void);
extern int getAlgChoice(void);
//Adders
extern void addToNumMoves (int s);

#endif /* STATICVARS_H */

