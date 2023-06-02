//playlife.c
// Seth Pickford
// FunComp-Lab 6

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "lifefunc.h"


// Global variable for board size
const int size = 40;

int main(int argc,char *argv[]) {

// create board double array
	char board[size][size];

// intitial creating of board
		init(board);
		boarddisplay(board);
	
// if to tell which mode to impliment
	if (argc == 1) {
		printf("Interactive Mode Activated\n");
	
//while loop to repeat program
		while(1) {	
// options for interactive mode	
			printf("'a': add cell   \n'r': remove cell    \n'n': advance simulation to next iteration   \n'q': quit program   \n'p': play continuously\n");
	
// take user input
			printf("Input:  ");
			char input1;
			int xcord;
			int ycord;
			scanf("%c",&input1);

// switch for controlling what happens based on user input
			switch(input1) {
				case 'a':
					printf("Add new cell. Enter coordinates separated by a space:  ");
					scanf("%d %d",&xcord,&ycord);
					if((xcord-1>=0 && xcord-1<size) && (ycord-1>=0 && ycord-1<size)) {
						addcell(board,xcord-1,ycord-1);
					} // if makes sure user input is inbounds
					else 
						printf("error: not inbounds\n\n");
					break;
				case 'r':
					printf("Remove cell. Enter coordinates separated by a space:  ");
					scanf("%d %d",&xcord,&ycord);
					if ((xcord-1>=0 && xcord-1<size) && (ycord-1>=0 && ycord-1<size)) {
						removecell(board,xcord-1,ycord-1);
					}//if makes sure in bounds
					else 
						printf("error: out of bounds\n\n");
					break;
				case 'n':
					run(board,xcord,ycord);
					boarddisplay(board);
					break;
				case 'q':
					printf("Program quit\n\n");
					return 0;
					break;
				case 'p':
					while(true) {
						run(board,xcord,ycord);
						boarddisplay(board);
						usleep(100000);
						system("clear");
					}
					break;
				default:
					printf("error: inproper input\n\n");		

			}
		}
	}

	else if (argc==2) {
//read in file
	FILE *fp;
	char inputfile;
	int a,b;
	
	fp = fopen(argv[1],"r");
		while(true) {
			fscanf(fp,"%c %d %d",&inputfile, &a,&b);

			if(feof(fp)) break;
			
			if(inputfile =='a') {
				addcell(board,a,b);
			}
		}
// running it		
		while(true) {
			boarddisplay(board);
			run(board,a,b);
			usleep(100000);
			system("clear");
		}



	}
	
	else if (argc > 2) printf("error: Too many arguments\n");


	return 0;
}



