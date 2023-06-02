// for question one on the practice exam


#include <stdio.h>
void fun1(int, int);
void fun2(int, int *);
void fun3(int *, int);
void disp(int, int);
int main()
{
int a = 1, b = 4;
fun1(a, b);
disp(a, b); // A
a = 1; b = 4;
fun2(a, &b);
disp(a, b); // B
a = 1; b = 4;
fun2(b, &a);
disp(a, b); // C
a = 1; b = 4;
int arr[] = {b,a,b}, *p = arr;
fun3(p, 3);
disp(a, b); // D
disp(*p, p[1]); // E
return 0;
}
void fun1(int a, int b)
{ a++; b++; }
void fun2(int a, int *b)
{ a++; (*b)++; }
void fun3(int *p, int sz)
{
int i;
for (i = 0; i < sz; i++) {
(*p)++;
p++;
}
}
void disp(int a, int b)
{ printf("%d %d\n", a, b); }
