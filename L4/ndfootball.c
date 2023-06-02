#include <stdio.h>
#include <math.h>

// Seth Pickford
// ndfootball.c
// Fundamentals of Computing - lab 4


// function prototypes
int winloss(int);
int numloss(int);
int numwins(int);
void winrecord(void);
void lossrecord(void);

// win and loss arrays
int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 10, 11 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4, 5, 3, 8, 3, 1, 2, 2, 2 };

// finds size of arrays aka number of years the arrays span
int size = sizeof(wins)/4;


int main() {

// kill variable is to end the while loop
	int kill = 0;
	while(kill != 1) {

// display table of options and take user input
		int num;
		printf("  1: Display the win/loss record for a chosen year\n  2: Display years with at least \"N\" number of wins\n  3: Display years with at least \"N\" number of losses\n  4: Display years with a winning record\n  5: Display years with a losing record\n  6: Quit Program\n");
		printf("Choice:  ");
		scanf("%d",&num);


	
// switch used to decide what to do based off user input
		int year;
		int temp;
		switch(num) {
			case(1):
			printf("What year would you like to look at?  ");
			scanf("%d",&year);
			winloss(year);
			break;
		case(2):
			printf("At least how many wins do you want to look at?  \n");
			scanf("%d",&temp);
			numwins(temp);
			break;
		case(3):
			printf("At least how many losses do you want to look at?  \n");
			scanf("%d",&temp);
			numloss(temp);
			break;
		case(4):
			printf("The years with winning records are:\n");
			winrecord();
			break;
		case(5):
			printf("The years with losing records are:\n");
			lossrecord();
			break;
		case(6):
			kill = 1;
			printf("Program has been terminated.  Have a nice day!");
			break;
		default:
			printf("Incorrect input, try again");

		}
		printf("\n");
	}





	return 0;
}

// USER DEFINED FUNCTIONS


// function for win loss record for a year (case 1)
int winloss(int year) {

	if (year >=1900 && year <= 2021) {
		int spot = year - 1900;
		printf("Wins: %d\n", wins[spot]);
		printf("Losses: %d\n",losses[spot]);
	}
	else {
		printf("Invalid input! Input a year between 1900 & 2021.\n");
	}
}

	


// function for finding years with at least n number of wins (case 2)
int numwins(int dubs) {
	int year;
	int count=0;

	for (int i = 0; i < size; i++) {
	
		if (wins[i] >= dubs && count != 10) {
			year= i + 1900;
			printf("%5d",year);
			count = count + 1;
		}
		else if(wins[i] >= dubs && count == 10) {
			year = i +1900;
			printf("\n%5d",year);
			count = 1;
		}
	}
}



// function for finding years with at least n number of losses (case 3)
int numloss(int loss) {
	int year;
	int count=0;

	for (int i = 0; i < size; i++) {
	
		if (losses[i] >= loss && count != 10) {
			year= i + 1900;
			printf("%5d",year);
			count = count + 1;
		}
		else if (losses[i] >= loss && count == 10) {
			year = i + 1900;
			printf("\n%5d",year);
			count = 1;
		}
	}
}

// finds years with winning records (case 4)
void winrecord(void) {
	int count = 0;

	for (int i = 0;i<size;i++) {
		if (wins[i] > losses[i] && (count != 10)) {
			printf("%5d", i+1900);
			count = count + 1;
		}
		else if (wins[i] > losses[i] && count == 10){
			printf("\n");
			count = 0;
		}
	}
}





// find years with losing records
void lossrecord(void) {
	int count = 0;

	for (int i = 0;i<size;i++) {
		if (losses[i] > wins[i] && (count != 10)) {
			printf("%5d", i+1900);
			count = count + 1;
		}
		else if (losses[i] > wins[i] && count == 10){
			printf("\n");
			count = 0;
		}
	}
}


