// Seth Pickford
// Fundamentals of Computing - Lab 5
// mysayings.c

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxsaying 256 // defines the max characters that a saying can be
#define maxfile 30 // max length of file name input by user
#define numsayings 50 // define the max number of sayings


void newsay(char array[][maxsaying],int); // enter new string into database
void search(char array[][maxsaying],int); // list sayings with given string
void newfile(char array[][maxsaying],int); // save all saying in new file


int main() {
	
	char name[maxfile]; // for taking file name
	char usersaying[maxsaying]; // for taking the user's saying input
	FILE *fp; 
	char array[numsayings][maxsaying]; // 2D array to hold the sayings

// take user input and store in name
	printf("What file do you want to access?\n");
	scanf("%s",name);

	fp = fopen(name,"r");

// verifyin that the file is a valid file and exists
	if (fp == NULL) {
		printf("File doesn't exist\n");
		return -1;
	}

// putting file into our array
	int i = 0;
	while(1) {
		fgets(usersaying,maxsaying,fp); // reads through file and takes strings
		if (feof(fp)) break;  // breaks out of while when end is reached
		strcpy(array[i],usersaying); // use strcpy to assign strings to array
		
		i++;
	}




// Start of user interface

	int exit = 0;
	int n;
	
	while (exit!=1) {

//	Menu(); // displays menu of options for user
	printf("1: Display all sayings currently in the Database\n");
	printf("2: Enter a new saying into the database\n");
	printf("3: List sayings that contain an entered string\n");
	printf("4: Save all sayings into a new text file\n");
	printf("5: Quit the program\n");


// takes user input for menu selection
	printf("Please input the number that corresponds to your choice:  ");
	scanf("%d",&n);
	getchar(); 	

// switch statement for taking user input and controlling what function runs
		switch(n) {
			case 1:
				printf("\n");
				for(int x = 0; x<i;x++) {
				printf("%s",array[x]);
				}
				printf("\n");

				break;
			case 2:
				newsay(array,i);
				i++; // adds for increased indexing
				break;
			case 3:
				search(array,i);
				break;
			case 4:
				newfile(array,i);
				break;
			case 5:
				exit = 1;
				break;
			default:
				printf("\nerror: try again\n\n");
		}

	}

	return 0;
}

// USER DEFINED FUNCTIONS

// puts a new string into the database
void newsay(char array[numsayings][maxsaying],int i) {

	char saying[maxsaying]; // new array to hold the input saying
	printf("What is the new saying you want to add:   ");
	fgets(saying,maxsaying,stdin);
	strcpy(array[i],saying);
	printf("\n");
}

// for finding strings with a certain string in them
void search(char array[numsayings][maxsaying],int i) {

	char word[maxsaying];
	printf("Enter a word to look for:  \n");
	fgets(word,maxsaying,stdin);
	int length = strlen(word);
	word[length-1] = '\0'; // to get rid of new line create by user hitting enter
	char *character;

	// for loop to move through the array
	for (int x = 0; x<i;x++) {
		character = strstr(array[x],word);
		if (character != NULL) {
			fputs(array[x],stdout);
		}
	}
	printf("\n");
}

// for saving all the sayings in new text file
void newfile(char array[][maxsaying],int i) {

	FILE *point;
	char newfile[maxfile];
	printf("Enter the name of the new file:  ");
	scanf("%s",newfile);
	point = fopen(newfile,"w");
	
		printf("copying\n");
		for (int x=0;x<i;x++) {
			fputs(array[x],point);
		}

		fclose(point);
}
