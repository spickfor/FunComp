#include <stdio.h>

int main() {

int n;

printf("enter n: ");
scanf("%d", &n);

// only needs curly braces for more than one line

if (n>10) {
	printf("hello\n");
	printf("stuff\n");
}
else if (n==9)
	printf("bye\n");
else
	printf("wawawewa\n");



while (n > 20) {
	printf("repeat\n");
	n = n - 1;
}


for (n=1; n<=10; n = n+1) {
printf("n: %d\n",n);

}


return 0;
}


// comparison operators:
// >
// <
// >=
// <=
// ==
// !=


// || (or)
// && (and)
// ! (not)
