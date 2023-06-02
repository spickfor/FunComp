// Seth Pickford
// Fundamentals of Computing - lab 7
// path.c

#include <math.h>
#include <stdio.h>

typedef struct { 
  float x; 
  float y; 
} Point;

// function prototypes
void display(Point array[],int,float);
float distance(Point array[],int);

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


