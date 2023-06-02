#include <stdio.h>


int main() {
	printf("input 5 integers, they will be displayed in reverse order:   ");
	int a[5];
	int num;

	for (int i = 0; i<5; i = i+1) { 
		scanf("%d",&num);
		a[i] = num;
	}
	
	printf("\n");
	for (int x = 4; x>=0; x = x-1) {
		printf("%d", a[x]);
		
	}

printf("\n");



return 0;
}
