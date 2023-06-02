#include <stdio.h>

int get_gcd(int,int);

int main()  {

int a;
int b;
int greatest;

printf("Give two values:   ");
scanf("%d %d", &a, &b);

greatest = get_gcd(a,b);
printf("The gcd is:  %d\n",greatest);

return 0;
}




int get_gcd(int a, int b)
{
int c;
int remainder;

	while (a != 0 && b != 0) {
		if (a<b) {
			a = c;
			b = a;
			c = b;
		}

		remainder = a%b;
		if (remainder ==0) {
			return b;
		}
		else {
			a = b;
			b = remainder;
		}
		
	}

}
