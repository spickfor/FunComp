#include <stdio.h>
#include <math.h>

int main() {

// uses quadratic formula to find the roots of a quadratic of form ax^2 + bx + c = 0

float a;
float b;
float c;

// ask user for input and set input to variable

printf("What are the values for the coefficients (a,b,c) of the quadratic?\n");
scanf("%f %f %f", &a, &b, &c);

// compute roots
float root1;
float root2;

root1 = (-b - sqrt(pow(b,2) - 4*a*c)) / (2*a);
root2 = (-b + sqrt(pow(b,2) - 4*a*c)) / (2*a);


// compute discriminant
float disc;
disc = pow(b,2) - 4*a*c;

if (disc==0)  {
	printf("There is one solution: ");
	printf("%f",root1);
	printf("\n");
}
else if (disc > 0)  {
	printf("There are two solutions: ");
	printf("%f and %f",root1,root2);
	printf("\n");
}
else {
	printf("There are no real roots\n");
} 

return 0;
}
