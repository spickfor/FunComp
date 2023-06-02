#include <stdio.h>
typedef struct {
int val1;
int val2;
} Pair;
int sum(Pair);
void func(Pair);
int main()
{
Pair x1 = {3,5}, x2 = {4,2}, x3 = {3,4};
Pair trio[] = {x1, x2, x3};
int i, s, total = 0;
for (i = 0; i < 3; i++) {
s = sum(trio[i]);
printf("%d\n", s);
total += s;
}
printf("%d\n", total);
func(x1);
}
int sum(Pair x)
{ return x.val1 + x.val2; }
void func(Pair x)
{
if(!(x.val1*x.val2)) return;
printf("%d %d\n", x.val1, x.val2);
x.val1--;
x.val2--;
func(x);
}
