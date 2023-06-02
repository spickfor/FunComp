// crossfunc.h
// Seth Pickford
// Fundamentals of Computing - Lab 8

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define boardsize 15
#define wordsize 15
#define numwords 20

// struct for holding info on each word
typedef struct {
	char string[wordsize];
	int x;
	int y;
	bool horizontal;
	bool placed;
} Word;


// function prototypes
void initanswerboard(char board[boardsize+2][boardsize+2]);
void initpuzzleboard(char board[boardsize+2][boardsize+2]);
void displayboard(char board[boardsize+2][boardsize+2]);
bool AtoZ(char word[wordsize],int size);
void uppercase(Word words[],int size);
void sort(Word words[],int size);
int inputfile(char filename[],Word words[]);
void place(Word words[],char board[][boardsize+2],int current, bool horizontal,int x, int y);
bool placesecond(Word words[],char board[][boardsize+2],int current);
bool check(char board[][boardsize+2],Word word,int x,int y,bool horizontal,int intersect);
void placenext(char board[][boardsize+2],Word words[],int start,int wordcount);


bool tryagain(char board[][boardsize+2], Word words[], int numWords);
