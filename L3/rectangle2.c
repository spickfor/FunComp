// rectangle2.c
#include <stdio.h>

// function prototypes go here ...
int find_perim(int,int);
int find_area(int,int);
int display(int,int);

int main()
{
  float len, wid;
  float perim, area;

  printf("enter the rectangle's length and width: ");
  scanf("%f %f", &len, &wid);

  perim = find_perim(len, wid);  // call the find_perim function
  area = find_area(len, wid);    // call the find_area function

  display(perim, area);          // call the display function

  return 0;
}

// function definitions go here ...
int find_perim(int len,int wid)
{
return (2*len)+(2*wid);
}

int find_area(int len,int wid)
{
return len*wid;
}

int display(int perim,int area)
{
printf("Perimeter is: %d.  Area is: %d\n", perim,area);
}


