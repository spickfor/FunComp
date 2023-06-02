#include <iostream>
using namespace std;
void func(int &);
int func(int, int);
int func(int, int *);
int func(int *, int *);
void show(int, int, int);
int main()
{
int x, y, z = 0;
x = 3, y = 5;
func(x, y);
show(x, y, z);
x = 3, y = 5;
func(x);
z = func(x, y);
show(x, y, z);
x = 3, y = 5;
z = func(x, &y);
show(x, y, z);
x = 3, y = 5;
z = func(&x, &y);
show(x, y, z);
return 0;
}
void func(int &a)
{ a++; }
int func(int a, int b)
{ a++; b++; return (a + b); }
int func(int a, int *b)
{ a++; (*b)++; return (a + *b); }
int func(int *a, int *b)
{ (*a)++; (*b)++; return (*a + *b); }
void show(int a, int b, int c)
{ cout << a << " " << b << " " << c << endl; }
