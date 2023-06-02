// usastates.c
// Seth Pickford
// Fundamentals of Computing - lab7


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "statesfunc.h"

// defining constants
const int maxfilelength = 30;
const int maxstates = 100;

int main() {



	// takes user file name because it wasnt entered at command line
		char file[maxfilelength];
		printf("File Name:  ");
		scanf("%s",file);
	
		FILE *fp = fopen (file,"r");
		if (!fp) return -1;
		int count = 0;
		int length = 200;
  		char line[length];
		State states[maxstates];


// reads in the file and counts the number of states
	while(1) {
		        fgets(line, maxfilelength, fp);    //read in the next line
        if(feof(fp))  break; 

        strcpy(states[count].abbreviation, strtok(line, ","));
        strcpy(states[count].name, strtok(NULL, ","));
        strcpy(states[count].capital, strtok(NULL, ","));
        states[count].year = atoi(strtok(NULL, "\n"));
        count++;
	}

	
// space out input from outputs
	printf("\n");

	int choice = table_input();


	return 0;
}
