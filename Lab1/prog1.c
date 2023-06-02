#include <stdio.h>

int main() {

// declares variables
int touchdowns;
int extrapoints;
int fieldgoals;
int safeties;

// Prompts user with printf and uses scanf to take the input
printf("How many touchdowns were there?\n");
scanf("%d", &touchdowns);

printf("How many extra points were there?\n");
scanf("%d", &extrapoints);

printf("How many field goals were there?\n");
scanf("%d", &fieldgoals);

printf("How many safeties were there?\n");
scanf("%d", &safeties);

// computes and outputs total points scored

// creates total points variable
int totalpoints;

totalpoints = (touchdowns*6) + (extrapoints) + (fieldgoals*3) + (safeties*2);
printf("The total score for the Irish is: ");
printf("%d",totalpoints);
printf("\n");


return 0;
}
