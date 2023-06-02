// symbol.c
// Seth Pickford
// Fundamentals of Computing - Lab 9

#include "gfx.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

void circle(int);
void square(int);
void triangle(int);
void polygon(int,int);

int main() {

	int size = 50;
	char temp;
// open the window
	gfx_open(700,700,"WINDOW");
// wait until user presses a key or clicks
	while(1) {
// wait for user event
		temp = gfx_wait();
// if user left clicks it will show a blue square
		if (temp == 1) {
			square(size);
		}
// if user inputs c it will print a white circle
		else if (temp == 'c') {
			circle(size);
		}
// user inputs t it shows green triangle
		else if (temp =='t') {
			triangle(size);
		}
// if escape key is hit, clear the screen
		else if (temp == 27) {
			gfx_clear();
		}
// quit window if q is hit
		else if (temp =='q') {
			break;
		}
// creates shape with number of sides typed 3-9
		else if('3' <= temp <= '9') {
			int numsides = temp - '0';
			polygon(size,numsides);
		}
	}
	return 0;
}

// function for making square
void square(int size) {
	gfx_color(0,0,255);
	gfx_line(gfx_xpos()-(size/2),gfx_ypos()-(size/2),gfx_xpos()-(size/2),gfx_ypos()+(size/2));
	gfx_line(gfx_xpos()+(size/2),gfx_ypos()-(size/2),gfx_xpos()+(size/2),gfx_ypos()+(size/2));
	gfx_line(gfx_xpos()-(size/2),gfx_ypos()-(size/2),gfx_xpos()+(size/2),gfx_ypos()-(size/2));
	gfx_line(gfx_xpos()-(size/2),gfx_ypos()+(size/2),gfx_xpos()+(size/2),gfx_ypos()+(size/2));
}

// function to make circle
void circle(int size) {
	gfx_color(255,255,255);
	gfx_circle(gfx_xpos(),gfx_ypos(),size/2);
}

// function to make a triangle
void triangle(int size) {
	gfx_color(0,255,0);
	gfx_line(gfx_xpos()-(size/2),gfx_ypos()-(size/2),gfx_xpos()+(size/2),gfx_ypos()-(size/2));
	gfx_line(gfx_xpos()-(size/2),gfx_ypos()-(size/2),gfx_xpos(),gfx_ypos()+(size/2));
	gfx_line(gfx_xpos()+(size/2),gfx_ypos()-(size/2),gfx_xpos(),gfx_ypos()+(size/2));
}

// function to creates polygons with varying num sides
void polygon(int size, int numsides) {

	gfx_color(255,0,255);
	int x = gfx_xpos();
	int y = gfx_ypos();
	int angle = 90;
	int x1,x2,y1,y2;
// for loop to create each side
	for(int i=0;i<numsides;i++) {
// find starts of line
		x1 = x-size/2*cos(angle*M_PI/180); 
		y1 = y-size/2*sin(angle*M_PI/180);
// control angle based on the number of sides input
		angle += 360/numsides;
// find the ends of the line
		x2 = x-size/2*cos(angle*M_PI/180); 
		y2 = y-size/2*sin(angle*M_PI/180);
// create line
		gfx_line(x1,y1,x2,y2);
	}
}
