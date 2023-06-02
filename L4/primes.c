#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Seth Pickford
//primes.c
// Fundamentals of Computing- lab4


int main() {
// intializing the array to 1's and initilize count

	bool array[1000];
	int count = 0;

	for (int i = 0; i < 1000; i++) {
		array[i] = true;
}


// finding the primes and displaying them in a table with 10 colums



for (int x = 2; x < 1000; x++) {
	for (int i = 2; i <= x; i++) {
		if (x==i && count !=10) {
			printf("%4d",x);
			count +=1;
		}
		else if (x==i && count ==10) {
			printf("\n");
			printf("%4d",x);
			count =1;
		}
		else if (x % i == 0) {
			break;
		}

	}

}

printf("\n");




	return 0;
}


