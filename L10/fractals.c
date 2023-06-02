// fractals.c
// Seth Pickford
// Fundamentals of Computing - Lab 10

#include "gfx.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3);
void drawtTriangle( int x1, int y1, int x2, int y2, int x3, int y3);
void shrinkingsquares(int x1,int y1,int size);
void square(int x1,int y1,int size);
void spiralsquares(int x,int y, float size,float radius,float maxradius,float angle);
void circularlace(int x,int y,float radius);
void snowflake(int x,int y,float len);
void tree(int x1, int y1, float angle, int len);
void fern(int x1, int y1, float angle, int len);
void spiralofspirals(int x, int y, float radius, float angle);


int main() {

	// variables for window size
	int width = 700;
	int height = 700;
	// variable for margin size
	int mrgn = 20;
	// open the window
	gfx_open(width,height,"FRACTALS");

	// bool to loop the while
	bool loop = true;
	// hold user input
	char input;
	while(loop) {
		input = gfx_wait();
		gfx_clear();
		// if controls what is run off of user input
		switch(input) {
			case '1': {
				sierpinski(mrgn, mrgn, width-mrgn, mrgn, width/2, height-mrgn);
				break;
			}
			case '2': {
				shrinkingsquares(width/2,height/2,350);
				break;
			}
			case '3': {
				spiralsquares(width/2,height/2,1,1,width/2,0);
				break;
			}
			case '4': {
				circularlace(width/2,height/2,width/3);
				break;
			}
			case '5': {
				snowflake(width/2,height/2,width/3);
				break;
			}
			case '6': {
				tree(width/2,height-10,270,width/4);
				break;
			}
			case '7': {
				fern(width/2,height-10,270,width/2);
				break;
			}
			case '8': {
				spiralofspirals(width/2,height/2,width,0);
				break;
			}

			case 'q': {
				loop = false;
			}
			default: {
				break;
			}
		}
	}


	return 0;
}

// func to draw triangle
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 ) {
	gfx_line(x1,y1,x2,y2);
	gfx_line(x2,y2,x3,y3);
	gfx_line(x3,y3,x1,y1);
}

// func to make sierpinski triangle
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 ) {
	// Base case. 
	if( abs(x2-x1) < 5 ) return;

	// Draw the triangle
	drawTriangle( x1, y1, x2, y2, x3, y3 );

	// Recursive calls
	sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
	sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
	sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}


// Shrinking Squares
void shrinkingsquares(int x1,int y1,int size) {
	if(size < 5) return;
	// draw square
	square(x1,y1,size);
	// recursion
	shrinkingsquares(x1-size/2.1,y1-size/2.1,size/2.1);
	shrinkingsquares(x1+size/2.1,y1+size/2.1,size/2.1);
	shrinkingsquares(x1-size/2.1,y1+size/2.1,size/2.1);
	shrinkingsquares(x1+size/2.1,y1-size/2.1,size/2.1);
}

// square making function give center point and size
void square(int x1,int y1,int size) {
	gfx_line(x1-size/2,y1-size/2,x1+size/2,y1-size/2);
	gfx_line(x1-size/2,y1-size/2,x1-size/2,y1+size/2);
	gfx_line(x1+size/2,y1-size/2,x1+size/2,y1+size/2);
	gfx_line(x1-size/2,y1+size/2,x1+size/2,y1+size/2);

}


// spiraling squares function
void spiralsquares(int x,int y, float size,float radius,float maxradius,float angle){
	if(radius > maxradius) return;
	
	// center of the current square
	int x1 = x+radius*cos(angle*(M_PI/180));
	int y1 = y+radius*sin(angle*(M_PI/180));

	//draw square centered x1,y1
	square(x1,y1,size);

	//recursion
	spiralsquares(x,y,size*(1.14),radius*(1.2),maxradius,angle+45);
}


// function to draw lace
void circularlace(int x,int y,float radius) {
	if(radius <= .5) return;
	int num = 6;
	// draw circle
	gfx_circle(x,y,radius);
	// loop through for each circle on circle
	for(int i = 0; i < num;i++) {
		circularlace(x+radius*cos(2*M_PI/num*i),y+radius*sin(2*M_PI/num*i),radius/3);
	}
}


// function to make snowflake given start point and initial length of lines
void snowflake(int x,int y,float len) {
	if(len < .5) return;

	int num = 5;
	// loop for each line
	for(int i = 0; i < num;i++) {
		gfx_line(x,y,x+len*cos(2*M_PI/num*i),y+len*sin(2*M_PI/num*i));
		//recursion
		snowflake(x+len*cos(2*M_PI/num*i),y+len*sin(2*M_PI/num*i),len/3);
	}
}


// makes tree of life recursion
void tree(int x1, int y1, float angle, int len) {
	if(len < 0.5) return;
	//calculate the end points
	int x2 = x1 + len*cos(angle*M_PI/180);
	int y2 = y1 + len*sin(angle*M_PI/180);
	//draw branch
	gfx_line(x1, y1, x2, y2);

	tree(x2, y2, angle + 35, len*.70);
	tree(x2, y2, angle - 35, len*.70);
}


// fern fractal
void fern(int x1, int y1, float angle, int len) {
	if(len < 2) return;

	//calculate the end point of the current branch
	int x2 = x1 + len*cos(angle*M_PI/180);
	int y2 = y1 + len*sin(angle*M_PI/180);
	//draw the branch
	gfx_line(x1, y1, x2, y2);

	int leaves = 4;
	// loop for each pair of leaves
	for(int i = 1; i <= leaves; i++) {
        //draw new pairs of lines at evenly separated angles
		fern(x1 + len*i/leaves*cos(angle*M_PI/180), y1 + len*i/leaves*sin(angle*M_PI/180), angle - 35, len/3);
		fern(x1 + len*i/leaves*cos(angle*M_PI/180), y1 + len*i/leaves*sin(angle*M_PI/180), angle + 35, len/3);
    }
}


// make spiral of spirals
void spiralofspirals(int x, int y, float radius, float angle) {
	if(radius < 1) return;

	//calculate the next point
	int x1 = x + radius*cos(angle*M_PI/180);
	int y1 = y + radius*sin(angle*M_PI/180);

	gfx_point(x1, y1);  //draw the point
	//then start a new spiral centered at that point with a smaller radius but the same angle
	spiralofspirals(x1, y1, radius*0.3, angle);
	//and continue the spiral centered at the current point with a slightly smaller radius and an incremented angle
	spiralofspirals(x, y, radius*.92, angle+35);
}
