#include <stdio.h>
#include <math.h> 

int main() {

// This program takes the two legs of a right triangle and outputs the hypotenuse length


// inputs for the lengths of the legs

float leg1;
float leg2;

printf("What is the length of the first leg? ");
scanf("%f", &leg1);

printf("What is the length of the second leg? ");
scanf("%f", &leg2);


// computes the hypotenuse length to 3 decimal places
// formula for hypotenuse is sqrt(a^2 + b^2)


float hypotenuse;
hypotenuse = sqrt(pow(leg1,2) + pow(leg2,2));

printf("The length of the hypotenuse is: %.3f \n",hypotenuse);

}
