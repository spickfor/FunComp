#include <stdio.h>


int main() {

int n = 7;

	for (int i = 1; i <= n; i++) {
		if (i==1 || i==n) {
			for (int x =0;x<n;x++) {
				printf("*");
			}
				printf("\n");
		}
		else {
			printf("*");
			for (int x=0;x < (n-2);x++) {
				printf(" ");
			}
				printf("*\n");
				
		}
	
	}



}
