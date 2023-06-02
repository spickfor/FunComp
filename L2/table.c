#include <stdio.h>

int main() {

// user inputs
int x;
int y;

printf("Give a size for x columns:  ");
scanf("%d",&x);

printf("Give a size for y rows:  ");
scanf("%d",&y);


// loops


printf("*   ");

for (int i=1;i<=x;i++) {
	printf("%4d",i);
}

printf("\n   ");


for (int i=1;i<=x;i++) {
	printf("----");
}

printf("\n");


for (int i=1;i<=y;i++) {
	printf("%2d |", i);
	for (int z=1; z<=x;z++) {
		int mult = i*z;
		printf("%4d", mult);

		}
printf("\n");

}









printf("\n");
return 0;
}
