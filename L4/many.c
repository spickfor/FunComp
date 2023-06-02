#include <stdio.h>



int main() {
	int num;
	int a[20];
 	int count = 0;

	printf("input number");
	scanf("%d", &num);

	while(num != -1)  {

	a[count] = num;
	count = count+1;
	scanf("%d", &num);
	}

	for (int i = count - 1;i>=0; i = i-1) {
	printf("%d",a[i]);
	}

printf("\n");

return 0;
}
