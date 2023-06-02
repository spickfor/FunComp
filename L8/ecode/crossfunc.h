// crossfunc.h
// seth pickford
// fundamentals of computing - lab 8

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// global definitions
#define wordsize 15
#define boardsize 15
#define maxwords 20

// create struct type. bools are for if a word has been placed and for word orientation
typedef struct {    
    char str[wordsize];
    bool placed;    
    bool horiz;
    int x;
    int y;
} Word;

//function prototypes
void initboard(char board[][boardsize+2]);
bool AtoZ(char str[], int len);
int userinput(Word words[]);
int readfile(char filename[], Word words[]);
void uppercase(Word words[], int count);
void sort(Word words[], int count);
void place(char board[][boardsize+2], Word words[], int x, int y, bool horiz, int curr);
bool second(char board[][boardsize+2], Word words[], int curr);
bool check(char board[][boardsize+2], Word word, int x, int y, bool horiz, int intersect);
void placerest(char board[][boardsize+2], Word words[], int start, int count);
void printBoardsFile(FILE *point, char board[][boardsize+2]);
void printCluesFile(FILE *point, Word words[], int count);
bool placeremaining(char board[][boardsize+2], Word words[], int count);
