//statesfunc.c
// Seth Pickford
// Fundamentals of Computing - lab 7

#include <stdio.h>
#include "statesfunc.h"

// display table of choices and take user input
int table_input()
{
	printf("\n1: Display info for all states");
	printf("2: Display info for a certain state");
	printf("3: Display the capital of a certain state");
	printf("4: Display all the states that joined the union in a given year");
	printf("5: Display all states that start with a certain letter");
	printf("0: Quit the program");
	printf("Please enter a choice: ");
	int input;
	scanf("%d", &input);
	printf("\n");
	return input;
}
