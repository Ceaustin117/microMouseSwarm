# microMouseSwarm program which is written in C 
 
 
 ![Alt Text](https://media.giphy.com/media/3oszOc1V32IwZqqyVk/giphy.gif)
 
 The makefile is for a standard gcc compiler
 
 Each microMouse start at random locations in the maze and share their partial mappings when one maze cell away from each other. This continues until the maze is fully mapped for one of the microMice.
 
 Four algorithmic choices for the maze solving.
 
 Algorithm Choices are:
 
 (1)Left Wall Follow 
 
 (2) Right Wall Follow
 
 (3) 50/50 chance of Left or Right Wall Follow
 
 (4)Switch between Left or Right Wall follow 
 when next to another microMouse
 
This is a general program only using the libraries
 
 stdlib.h math.h string.h stdio.h
 
 Takes input args width,height,algorithm, number of microMice, number of tests
 
 maze must be given odd height and width for maze to be made properly
 
 Example input parameters could be (13,13,2,5,100)
 
 This would give a maze width and height of 13, right wall follow with 5 microMice and 100 tests
