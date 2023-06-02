// funanim.c
// Seth Pickford
// Fundamentals of Computing - Lab 9
// click to change to random color,hit s,c,t to change the shape,space changes direction of spin,
// q quits

#include "gfx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void square(int,int,int);
void triangle(int,int,int);

int main() {

	int size = 50;
	int pause = 10000;
	char input;
// set random seeds
	srand(time(0));

// size of window and open window
	int width = 700;
	int height = 700;
	gfx_open(width,height,"FUN ANIMATION");
// ints for coordinates of spinning shape
	int x;
	int y;
// position of user
	int xuser = 100;
	int yuser = 100;
// ints to move user shape
	int movespeed = 3;
	int dx = movespeed;
	int dy = movespeed;
// angle to control circular motion and radius of motion and turn speed of shape
	int angle1 = 0;
	int angleadd = 90;
	int radius1 = 70;
	int radiusadd = 100;
	int turn = 3;
// temp variable to hold the shape selection so that clicking doesn't change input
	char temp;
	char num = 1;
// wait for user input
	input = gfx_wait();
// while loop to animate
	while(1) {
// change shape to circle if c is hit
		if(input == 'c') {
			x = (width/2) + (radius1*cos(angle1*M_PI/180));
			y = (height/2) + (radius1*sin(angle1*M_PI/180));
			gfx_circle(x,y,size/2);
		// second circle
			x = (width/2) + (radius1*cos((angle1+angleadd)*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+angleadd)*M_PI/180));
			gfx_circle(x,y,size/2);
		// third circle
			x = (width/2) + (radius1*cos((angle1+(2*angleadd))*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+(2*angleadd))*M_PI/180));
			gfx_circle(x,y,size/2);
		// Fourth circle
			x = (width/2) + (radius1*cos((angle1+(3*angleadd))*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+(3*angleadd))*M_PI/180));
			gfx_circle(x,y,size/2);
		// increment angle to make move in circle
			angle1 = angle1 + turn;
// make user's triangle
			triangle(xuser,yuser,size/2);
			xuser += dx;
			yuser += dy;
		}
		else if(input == 's') {
			x = (width/2) + (radius1*cos(angle1*M_PI/180));
			y = (height/2) + (radius1*sin(angle1*M_PI/180));
			square(x,y,size);
		// second square
			x = (width/2) + (radius1*cos((angle1+angleadd)*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+angleadd)*M_PI/180));
			square(x,y,size);
		// third square
			x = (width/2) + (radius1*cos((angle1+(2*angleadd))*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+(2*angleadd))*M_PI/180));
			square(x,y,size);
		// Fourth squre
			x = (width/2) + (radius1*cos((angle1+(3*angleadd))*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+(3*angleadd))*M_PI/180));
			square(x,y,size);
		// increment angle to make move in circle
			angle1 = angle1 + turn;
// make user's triangle
			triangle(xuser,yuser,size/2);
			xuser += dx;
			yuser += dy;
		}
		else if(input == 't') {
			x = (width/2) + (radius1*cos(angle1*M_PI/180));
			y = (height/2) + (radius1*sin(angle1*M_PI/180));
			triangle(x,y,size);
		// second
			x = (width/2) + (radius1*cos((angle1+angleadd)*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+angleadd)*M_PI/180));
			triangle(x,y,size);
		// third
			x = (width/2) + (radius1*cos((angle1+(2*angleadd))*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+(2*angleadd))*M_PI/180));
			triangle(x,y,size);
		// Fourth
			x = (width/2) + (radius1*cos((angle1+(3*angleadd))*M_PI/180));
			y = (height/2) + (radius1*sin((angle1+(3*angleadd))*M_PI/180));
			triangle(x,y,size);
		// increment angle to make move in circle
			angle1 = angle1 + turn;
// make user's triangle
			triangle(xuser,yuser,size/2);
			xuser += dx;
			yuser += dy;
		}
// quit program with q
		else if(input == 'q') break;
		if(gfx_event_waiting()) {
			temp = gfx_wait();
// when left click set to random color
			if(temp == 1) {
				gfx_color(rand()%255,rand()%255,rand()%255);
			}
			else if((temp == 'c') || (temp == 's') || (temp == 'q') || (temp == 't')) {
				input = temp;
			}
// if space is hit change direction of rotation
			else if(temp == ' ') {
				turn = -turn;
			}
// hit p to pause spinning
			else if(temp == 'p') {
				turn = 0;
			}
// arrow keys hit, change direction of user
// go left
			else if((temp == 'j')) {
				dx = -movespeed;
				dy = 0;
			}
// go down
			else if((temp  == 'k')) {
				dy = movespeed;
				dx = 0;

			}
// go right
			else if((temp == 'l')) {
				dx = movespeed;
				dy = 0;

			}
// go up
			else if((temp == 'i')) {
				dy = -movespeed;
				dx = 0;

			}
		}
// stop user if they hit edge of window
		if((xuser + size/2) >= width) {
			dx = 0;
			//stop user from getting stuck on wall
			xuser = xuser - 1;
		}
		else if((xuser - size/2) <= 0) {
			dx = 0;
			xuser = xuser + 1;
		}
		else if((yuser + size/2) >= height){
			dy = 0;
			yuser = yuser - 1;
		}
		else if((yuser - size/2) <= 0) {
			dy = 0;
			yuser = yuser + 1;
		}
// if user and spinning circles touch
		if(((xuser) <= (x+size/2)) && ((xuser) >= (x-size/2)) && ((yuser) <= (y+size/2)) && ((yuser) >= (y-size/2))) {
			xuser = width/2;
			yuser = height/2;
			dx = 0;
			dy = 0;
		}

// set computer wait and clear window
	usleep(pause);
	gfx_clear();
	}



	return 0;
}

// func to make square
void square(int x,int y,int size) {
	gfx_line(x-(size/2),y-(size/2),x-(size/2),y+(size/2));
	gfx_line(x+(size/2),y-(size/2),x+(size/2),y+(size/2));
	gfx_line(x-(size/2),y-(size/2),x+(size/2),y-(size/2));
	gfx_line(x-(size/2),y+(size/2),x+(size/2),y+(size/2));
}

// makes a triangle
void triangle(int x,int y,int size) {
	gfx_line(x-(size/2),y-(size/2),x+(size/2),y-(size/2));
	gfx_line(x-(size/2),y-(size/2),x,y+(size/2));
	gfx_line(x+(size/2),y-(size/2),x,y+(size/2));
}
