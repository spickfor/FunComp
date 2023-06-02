// for the second quesiton of the old exam

#include <stdio.h>
typedef struct {
int val1;
int val2;
int val3;
} Thing;
int sum(Thing);
int main()
{
int a = 7, *p = &a;
printf("%d %d\n", a, *p); // A
a = 11;
printf("%d %d\n", a, *p); // B
*p = 13;
printf("%d %d\n", a, *p); // C
(*p)++;
printf("%d %d\n", a, *p); // D
Thing x1 = {3,5,4}, x2 = {4,1,3},
x3 = {5,2,6}, x4 = {2,9,4};
Thing quad[] = {x1, x2, x3, x4};
int i, s, total = 0;
for (i = 0; i < 4; i++) {
s = sum(quad[i]);
printf("%d\n", s); // E, F, G, H
total += s;
}
printf("%d\n", total); // I
return 0;
}
int sum(Thing x)
{ return x.val1 + x.val2 + x.val3; }
