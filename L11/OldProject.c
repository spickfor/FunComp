// project.c
// Seth Pickford
// Fundamentals of Computing - Lab 11
// click to change to random color,hit s,c,t to change the shape,space changes direction of spin
// q quits

#include "gfx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void square(int,int,int);
void triangle(int,int,int);
bool squaretouch(int userx,int usery,int x,int y,int usersize,int shapesize);
bool circletouch(int userx,int usery,int x,int y,int usersize,int shapesize);

// create struct type
typedef struct {
	int x;
	int y;
	int dx;
	int dy;
	int size;
} Variables;


int main() {
	
// create struct to hold user variables and changing variables for user
	Variables user;
// create struct to hold shape points
	Variables shape;
// create struct to hold points for goal
	Variables goal;
// make repeatable variables
	int size = 50;
	int pause = 10000;
	char input;
// set random seeds
	srand(time(0));

// size of window and open window
	int width = 700;
	int height = 700;
	gfx_open(width,height,"FUN ANIMATION");
// position of user
	user.x = 100;
	user.y = 100;
// position of goal and how it moves around
	goal.x = 675;
	goal.y = 675;
	goal.dx = 0;
	goal.dy = 0;
	goal.size = size/2;
// ints to move user shape
	int movespeed = 2;
	user.dx = movespeed;
	user.dy = movespeed;
// variable for user size and shape sizes
	user.size = size/4;
	shape.size = size/2;
// angle to control circular motion and radius of motion and turn speed of shape
	int angle = 0;
	int angleadd = 90;
	int radius = 100;
	int radiusadd = 100;
	int turn = 1;
// temp variable to hold the shape selection so that clicking doesn't change input
	char temp;
	char num = 1;
// wait for user input
	input = gfx_wait();
// while loop to animate
	while(1) {
// change shape to circle if c is hit
		if(input == 'c') {
			shape.x = (width/2) + (radius*cos(angle*M_PI/180));
			shape.y = (height/2) + (radius*sin(angle*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touches 
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// second circle
			shape.x = (width/2) + (radius*cos((angle+angleadd)*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+angleadd)*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touches
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// third circle
			shape.x = (width/2) + (radius*cos((angle+(2*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+(2*angleadd))*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touchs
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// Fourth circle
			shape.x = (width/2) + (radius*cos((angle+(3*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+(3*angleadd))*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touches
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// increment angle to make move in circle
			angle = angle + turn;
		// make user's square
			square(user.x,user.y,user.size);
			user.x += user.dx;
			user.y += user.dy;
		// creation of square that is the goal to reach
			square(goal.x,goal.y,goal.size);
			if(squaretouch(user.x,user.y,goal.x,goal.y,user.size,goal.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		}
		else if(input == 's') {
			shape.x = (width/2) + (radius*cos(angle*M_PI/180));
			shape.y = (height/2) + (radius*sin(angle*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			// if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// second square
			shape.x = (width/2) + (radius*cos((angle+angleadd)*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+angleadd)*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// third square
			shape.x = (width/2) + (radius*cos((angle+(2*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+(2*angleadd))*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// Fourth squre
			shape.x = (width/2) + (radius*cos((angle+(3*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+(3*angleadd))*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// increment angle to make move in circle
			angle = angle + turn;
		// make user's square
			square(user.x,user.y,user.size);
			user.x += user.dx;
			user.y += user.dy;
		}
		// creation of square that is the goal to reach
			square(goal.x,goal.y,goal.size);
			if(squaretouch(user.x,user.y,goal.x,goal.y,user.size,goal.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}

		else if(input == 't') {
			shape.x = (width/2) + (radius*cos(angle*M_PI/180));
			shape.y = (height/2) + (radius*sin(angle*M_PI/180));
			triangle(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// second
			shape.x = (width/2) + (radius*cos((angle+angleadd)*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+angleadd)*M_PI/180));
			triangle(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// third
			shape.x = (width/2) + (radius*cos((angle+(2*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+(2*angleadd))*M_PI/180));
			triangle(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// Fourth
			shape.x = (width/2) + (radius*cos((angle+(3*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius*sin((angle+(3*angleadd))*M_PI/180));
			triangle(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
			}
		// increment angle to make move in circle
			angle = angle + turn;
		// make user's square
			square(user.x,user.y,user.size);
			user.x += user.dx;
			user.y += user.dy;
		}

// quit program with q
		else if(input == 'q') break;
// waits for a user input to follow if
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
// hit o to make spin again
			else if (temp == 'o') {
				turn = 1;
			}
// equivialent of arrow keys, change direction of user
// go left
			else if((temp == 'j')) {
				user.dx = -movespeed;
				user.dy = 0;
			}
// go down
			else if((temp  == 'k')) {
				user.dy = movespeed;
				user.dx = 0;

			}
// go right
			else if((temp == 'l')) {
				user.dx = movespeed;
				user.dy = 0;

			}
// go up
			else if((temp == 'i')) {
				user.dy = -movespeed;
				user.dx = 0;

			}
		}
// stop user if they hit edge of window
		if((user.x + user.size) >= width) {
			user.dx = 0;
			//stop user from getting stuck on wall
			user.x = user.x - 1;
		}
		else if((user.x - user.size) <= 0) {
			user.dx = 0;
			user.x = user.x + 1;
		}
		else if((user.y + user.size) >= height){
			user.dy = 0;
			user.y = user.y - 1;
		}
		else if((user.y - user.size) <= 0) {
			user.dy = 0;
			user.y = user.y + 1;
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

// returns true if the two shapes touch and false otherwise fo a square shape
bool squaretouch(int userx,int usery,int x,int y,int usersize,int shapesize) {
	if((((userx +usersize) <= (x+shapesize)) && ((userx +usersize) >= (x-shapesize)) && ((usery+usersize) <= (y+shapesize)) && ((usery+usersize) >= (y-shapesize))) || (((userx-usersize) <= (x+shapesize)) && ((userx-usersize) >= (x-shapesize)) && ((usery-usersize) <= (y+shapesize)) && ((usery-usersize) >= (y-shapesize))) || (((userx+usersize) <= (x+shapesize)) && ((userx+usersize) >= (x-shapesize)) && ((usery-usersize) <= (y+shapesize)) && ((usery-usersize) >= (y-shapesize))) || (((userx-usersize) <= (x+shapesize)) && ((userx-usersize) >= (x-shapesize)) && ((usery+usersize) <= (y+shapesize)) && ((usery+usersize) >= (y-shapesize)))) {
		return true;
	}
	return false;
}

// for if user touches circle, returns true if they touch
bool circletouch(int userx,int usery,int x,int y,int usersize,int radius) {
	// if to determine if the user is inside circle with distance formula
	if(sqrt(pow(((userx+usersize)-x),2)+pow(((usery+usersize)-y),2)) <= radius) return true;
	if(sqrt(pow(((userx+usersize)-x),2)+pow(((usery-usersize)-y),2)) <= radius)	return true;
	if(sqrt(pow(((userx-usersize)-x),2)+pow(((usery-usersize)-y),2)) <= radius) return true;
	if(sqrt(pow(((userx-usersize)-x),2)+pow(((usery+usersize)-y),2)) <= radius) return true;
	
	return false;
}

