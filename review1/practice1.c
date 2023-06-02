#include <stdio.h>


int main ()  {

	int n = 5;

	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= i; x++) {
			printf("%2d",x);
		}
		printf("\n");
	}

	for (int i = n-1; i >= 1; i--) {
		for (int x = 1; x <= i; x++) {
			printf("%2d",x);
		}
		printf("\n");
	}


}
