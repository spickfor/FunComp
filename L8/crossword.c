// crossword.c MINE
// Seth Pickford
// Fundamentals of Computing - Lab 8

#include "crossfunc.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int main(int argc,char *argv[]) {

// initialize board variables
	char answerboard[boardsize+2][boardsize+2];
	char puzzleboard[boardsize+2][boardsize+2];
// initiaize boards
	initanswerboard(answerboard);
	initpuzzleboard(puzzleboard);
// display each blank board
	displayboard(puzzleboard);
	displayboard(answerboard);

// variable for counting words, for user input, and temp variable for storing string
	int count =  0;
	char temp[numwords][wordsize];
// array of structs for holding the words and their data
	Word words[numwords];
// If else used to control what happens based on command line inputs
	if(argc == 1) {
// prompt user for their words
		printf("Input 20 words or if you want fewer, a \".\" to stop inputting\n");
// while loop to iterate through our array with count, reads and sets = to
// temp, strcpy used to copy over to array
		while(count < numwords) {
			scanf("%s",temp[count]);
			if ((strcmp(temp[count],".") != 0) && (AtoZ(temp[count],strlen(temp[count])) == true) && (strlen(temp[count]) > 2 && strlen(temp[count]) <= wordsize)) {
				strcpy(words[count].string,(temp[count]));
				count++;
			}
			else if((strcmp(temp[count],".") == 0) || (AtoZ(temp[count],strlen(temp[count])) == false) || (strlen(temp[count]) <= 2 || strlen(temp[count]) > wordsize)) {
				break;

			}
		}
	}
	else if(argc == 2) {
		count = inputfile(argv[1],words);	
		if(count == -1) {
			printf("File doesn't exist\n");
		}
	}
	else if (argc == 3) {
		printf("not done yet");
	}
	else {
		printf("Too many command line inputs");
	}
// for sorting and setting to uppercase the words	
	sort(words,count);
	uppercase(words,count);

// placing of first word
	place(words,answerboard,0,true,(boardsize-strlen(words[0].string))/2,boardsize/2);

// place second word and break if can't be placed
	placesecond(words,answerboard,1);
	if(!placesecond(words,answerboard,1)) {
		printf("\n%s cound't be placed\n",words[1].string);
	}

	placenext(answerboard,words,3,count);

	while(tryagain(answerboard, words, count)) {}
////////////////////////////////////// test print function
	displayboard(answerboard);
	for(int x = 0;x<count;x++) {
		printf("%s\n",words[x].string);
	}

/////////////////////////////////////

	return 0;
}
