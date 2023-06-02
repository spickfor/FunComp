// Seth Pickford
// Fundamentals of Computing - lab 7
// path.c

#include <math.h>
#include <stdio.h>
#include "pathfunc.h"



// outputting the table and points
void display(Point array[],int size,float distance) {
// display num points
	printf("There are %d points:\n\n", size);

	// top line
	printf("  x   |   y\n");

	// second line
	printf("-------+--------\n");
	
	// printing table of points
	for (int i = 0;i < size;i++) {
			printf("%5.1f | %5.1f",array[i].x, array[i].y);

		printf("\n");
	}
	printf("The length of the path through them is %.2f\n",distance);
}



// finding distance between points
float distance(Point array[], int size) {
	
	float total = 0;
	for (int i = 0; i< size-1; i++) {
		total = total + sqrt(pow((array[i+1].x - array[i].x), 2) +  pow((array[i+1].y - array[i].y), 2));
	}
	
	return total;
}


