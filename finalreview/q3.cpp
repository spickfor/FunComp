#include <iostream>
#include <string>
using namespace std;
int main()
{
char s1[] = "Exam", *p1 = s1;
string s2 = "CSE", *p2 = &s2;
cout << s1 << endl;
cout << p1 << endl;
cout << *p1 << endl;
cout << s2 << endl;
cout << p2 << endl;
cout << *p2 << endl;
return 0;
}
