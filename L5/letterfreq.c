#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Seth Pickford
// letterfreq.c
// Fundamentals of Computing - Lab 5


// function prototypes
char display(int, int,char *);


// number of characters in alphabet can be changed for different alphabet sizes
#define alphabetnum 26

int main() {

// initializing
	char infile[30]; // array that holds file name from user input
	FILE *fp; // holds file location
	int alphcount[alphabetnum];
	int numletters;
	int totalchars;  
	char characters;
	int dist;


// Takes user input for which file to analyze
	printf("Which file do you want to look at?\nFile Name:  ");
	scanf("%s",infile);

// open file specified by user and check if it exists
	fp = fopen(infile,"r");
	if (fp == NULL) {
		printf("File name %s not found.\n",infile);
		return -1;
	}

// sets array to all zeros
	for (int i=0;i<alphabetnum;i++) {
		alphcount[i]=0;
	}

// goes through file
	while (1) {
		fscanf(fp,"%c",&characters); // reads file and stores as characters in txt var
		if (feof(fp)) break; // breaks loop if end is reached
	
// below if statement uses isalpha from ctype library to check if character is alphabetic
		if (isalpha(characters)) {
		
			numletters++;
			characters = tolower(characters); // makes the letter lowercase
			dist = characters - 97; // finds the distance from a(97 in ascii)
			alphcount[dist] = alphcount[dist] + 1;
		}
		totalchars++;	

	}

// display total number of characters and letters
	display(totalchars,numletters,infile);
// display number of each letter
	printf("Letter Counts:\n");
	int count = 0;
	int asciivalue = 97;  // initializes to spot 97 on ascii table which is "a"
	for (int i = 0; i< alphabetnum;i++) {
		printf("%c:%6d  ", asciivalue,alphcount[i]);
		count++;
		if (count%6==0) printf("\n");
		asciivalue +=1;
	}
	printf("\n\n");

// display percentages for letters
	printf("Letter Percentages: \n");
	count = 0;
	asciivalue = 97;
	double percent;
	for (int i = 0; i<alphabetnum;i++) {
		percent = (double) alphcount[i]/ (double) numletters;
		percent = percent *100;
		printf("%c:%5.1lf%%  ", asciivalue,percent);
		count++;
		if (count%6==0) printf("\n");
		asciivalue +=1;

	}
	printf("\n");


return 0;
}

// function for displaying total number of characters and letters
char display(int characters,int let,char *infile) {
	printf("General Summary for %s:\n", infile);
	printf(" There were %d total characters \n There were %d total letters\n", characters,let);
}

