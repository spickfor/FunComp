// Seth Pickford
// Fundamentals of Computing - lab 7
// path.c

#include <math.h>
#include <stdio.h>
#include "pathfunc.h"

int main() {

// takes user file name input
	int	maxfilelength = 30;
	int maxpoints = 30;
	char file[maxfilelength];
	printf("File Name:  ");
	scanf("%s",file);

	FILE *fp = fopen(file,"r");
	Point point_array[maxpoints];
	int count = 0;

// counts the number of points and reads in the points into point_array
	while(1) {
		fscanf(fp,"%f %f", &point_array[count].x,&point_array[count].y);
		if(feof(fp)) break;
		count++;
	}
printf("\n"); // spaces output from user input line

	
	float dist = distance(point_array,count);

	display(point_array,count,dist);


	return 0;
}

