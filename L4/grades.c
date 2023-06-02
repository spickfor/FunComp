#include <stdio.h>
#include <math.h>

//Seth Pickford
//grades.c
//Fundamentals of Computing- lab4


// function prototypes

float average(int[],int);
float std(int[],int);

int main()
{
// given array of grades
  int grades[] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79 };

  // calling of user functions and displaying of values

	int size = sizeof(grades)/4;
	printf("There are %d grades in the given array\n",size);

	float avg;
	avg = average(grades,size);
	printf("The average to two decimals is:  %.2f\n",avg);

	float standardDeviation;
	standardDeviation = std(grades,size);
	printf("The standard deviation to two decimals is:  %.2f\n",standardDeviation);

  
	return 0;
}

// function definitions

// function to find the average of the array
float average(int array[],int size) 
{
	float total;
	for (int i=0;i < size; i = i + 1) {
		total = total + array[i];		
	}
	float ave = total/size;
	return ave;

}
// function to find the standard deviation of array
float std(int array[],int size) 
{
	float total;
	for (int i=0;i < size; i = i + 1) {
		total = total + array[i];		
	}
	float ave = total/size;

	float square;
	float sqtotal;
	for (int i=0; i<size; i = i+1) {
		square = pow((array[i] - ave),2);
		sqtotal = sqtotal + square;
	}
	
	float final;
	final = sqrt((sqtotal)/size);
	return final;
	
}





