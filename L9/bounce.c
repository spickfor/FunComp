// bounce.c
// Seth Pickford
// Fundamentals of Computing - lab 9

#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
// ints for size of window
	int width = 700;
	int height= 700;
// open window
	gfx_open(width,height,"Bounce Around");
// floats to control the speed of movement
	float dx = 5;
	float dy = 5;
// ints to control position of circle and its radius
	int xpos = 350;
	int ypos = 25;
	int radius = 25;
// int to control time that program waits
	int pause = 10000;
// char used for the user input keys/click
	char input;
// set up seed for random generation and ints for min and max speeds and direction int
	srand(time(0));
	int min = 5;
	int max = 15;
	int dir1;
	int dir2;
// set color to white
	gfx_color(255,255,255);
// while loop to create animation
	while(1) {
		gfx_circle(xpos,ypos,radius);
		gfx_flush();
// move the circle
		xpos += dx;
		ypos += dy;
// detecting wall collisions
		if((xpos+radius) >= width) {
			dx = -dx;
			xpos = width - radius;
		}
		else if((xpos-radius) <= 0) {
			dx = -dx;
			xpos = 0 + radius;
		}
		else if((ypos+radius) >= height) {
			dy = -dy;
			ypos = height - radius;
		}
		else if((ypos-radius) <= 0) {
			dy = -dy;
			ypos = 0 + radius;
		}
// wait for a user input
		if(gfx_event_waiting()) {
			input = gfx_wait();
			if(input == 'q') break;
			if(input == 1) {
				xpos = gfx_xpos();
				ypos = gfx_ypos();
// control speed ball moves
				dx = min + rand()%(max-min);
				dy = min + rand()%(max-min);
// control direction the ball moves randomly
				dir1 = rand()%2;
				dir2 = rand()%2;
				if(dir1 == 1) {
					dx = -dx;
				}
				else if(dir2 == 1) {
					dy = -dy;
				}
			}
		}

	usleep(pause);
	gfx_clear();
	}



	return 0;
}
