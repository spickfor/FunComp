// project.c
// Seth Pickford
// Fundamentals of Computing - Lab 11
// click to change to random color,hit s,c to change the shape,space changes direction of spin
// q quits, i,j,k,l control user direction. p & o are used for testing so that you can actually
// get to goal block without difficulty

#include "gfx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

void square(int,int,int);
void triangle(int,int,int);
bool squaretouch(int userx,int usery,int x,int y,int usersize,int shapesize);
bool circletouch(int userx,int usery,int x,int y,int usersize,int shapesize);
void level(int points,int width,int height,int xstart,int ystart,int yend);

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
// position of user at start
	user.x = width/2;
	user.y = height/2;
// position of goal and how it initially moves around if that is wanted
	goal.x = 675;
	goal.y = 675;
	goal.dx = 0;
	goal.dy = 0;
	goal.size = size/2;
// int pointer for num of points/level
	int points = 0;
// variables for where to make talis and how large
	int xstart = 20;
	int ystart = 30;
	int yend = 50;
// ints to move user shape and initial user speed to 0 so it remains centered until key press
	int movespeed = 2;
	user.dx = 0;
	user.dy = 0;
// variable for user size and shape sizes
	user.size = size/4;
	shape.size = size/2;
// angle to control circular motion and radius of motion and turn speed of shapes
	float angle = 0;
	int angleadd = 90;
	int radius = 100;
	int radius2 = 300;
	float turn = .5;
// temp variable to hold the shape selection so that clicking doesn't change input
	char temp;
	char num = 1;
// make it so that the game starts as circles spinning
	input = 'c';
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
				points = 0;
				turn = .5;
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
				points = 0;
				turn = .5;
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
				points = 0;
				turn = .5;
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
				points = 0;
				turn = .5;
			}
	// repeat spinning shapes at larger radius to make two layers
			shape.x = (width/2) + (radius2*cos(angle*M_PI/180));
			shape.y = (height/2) + (radius2*sin(angle*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touches 
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
			}
		// second circle
			shape.x = (width/2) + (radius2*cos((angle+angleadd)*M_PI/180));
			shape.y = (height/2) + (radius2*sin((angle+angleadd)*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touches
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
			}
		// third circle
			shape.x = (width/2) + (radius2*cos((angle+(2*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius2*sin((angle+(2*angleadd))*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touchs
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
			}
		// Fourth circle
			shape.x = (width/2) + (radius2*cos((angle+(3*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius2*sin((angle+(3*angleadd))*M_PI/180));
			gfx_circle(shape.x,shape.y,shape.size);
			// if user touches
			if(circletouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
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
				points = points +1;	
			// if so if it is spinning other way from space, it doesn't switch direction
				if(turn > 0) {
					turn = turn + .3;
				}
				else if(turn < 0) {
					turn = turn - .3;
				}
			}
			level(points,width,height,xstart,ystart,yend);
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
				points = 0;
				turn = .5;
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
				points = 0;
				turn = .5;
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
				points = 0;
				turn = .5;
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
				points = 0;
				turn = .5;
			}
	// repeat spinning shape at larger radius
			shape.x = (width/2) + (radius2*cos(angle*M_PI/180));
			shape.y = (height/2) + (radius2*sin(angle*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			// if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
			}
		// second square
			shape.x = (width/2) + (radius2*cos((angle+angleadd)*M_PI/180));
			shape.y = (height/2) + (radius2*sin((angle+angleadd)*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
			}
		// third square
			shape.x = (width/2) + (radius2*cos((angle+(2*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius2*sin((angle+(2*angleadd))*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
			}
		// Fourth squre
			shape.x = (width/2) + (radius2*cos((angle+(3*angleadd))*M_PI/180));
			shape.y = (height/2) + (radius2*sin((angle+(3*angleadd))*M_PI/180));
			square(shape.x,shape.y,shape.size*2);
			//if they touch
			if(squaretouch(user.x,user.y,shape.x,shape.y,user.size,shape.size)) {
				user.x = width/2;
				user.y = height/2;
				user.dx = 0;
				user.dy = 0;
				points = 0;
				turn = .5;
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
				points = points + 1;
			// this if is so if the space switched direction and its spinning other way
				if(turn > 0) {
					turn = turn + .3;
				}
				else if(turn < 0) {
					turn = turn - .03;
				}
			}

// quit program with q
		else if(input == 'q') break;
	// make level counter
	level(points,width,height,xstart,ystart,yend);
// waits for a user input to follow if
		if(gfx_event_waiting()) {
			temp = gfx_wait();
// when left click set to random color
			if(temp == 1) {
				gfx_color(rand()%255,rand()%255,rand()%255);
			}
			else if((temp == 'c') || (temp == 's') || (temp == 'q')) {
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
				turn = .5;
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


// function prints talimarks at the top to count the points/level
void level(int points,int width,int height,int xstart,int  ystart,int yend) {
	int move = 8;
	int count = 1;

	// draw vertical lines
	for(int i = 0; i < points; i++) {
		gfx_line(xstart, ystart,xstart, yend);
		xstart = xstart + move;
	}
}

