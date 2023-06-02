//lifefunc.c
// Seth Pickford
// Fundamentals of Computing- lab 6

#include <stdio.h>
#include <stdbool.h>
#include "lifefunc.h"

// creation of variables for readability
const int size;
const char BLANK = ' ';
const char Alive = 'x';


// creating blankboard
void init(char board [][size]) {
	for (int i = 0; i<size;i++) {
		for (int t = 0; t<size; t++) {
			board[i][t] = BLANK;
		}
	}
}

// function to create board
void boarddisplay(char board[][size]) 
{
// top line
	printf("+");
	for(int i = 0; i < size;i++) {
		printf("-");
	}
	printf("+\n");

// grid
	for(int k = 0;k < size;k++){
		printf("|");
		for(int t = 0;t < size;t++) {
			printf("%c",board[k][t]);
		}
	printf("|");
	printf("\n");
	}

// bottom line
	printf("+");
	for(int h=0;h<size;h++) {
		printf("-");
	}
	printf("+");
	printf("\n");

}

// add cell into the board
void addcell(char board[][size],int x, int y) {
	
	board[x][y] = 'x';
	boarddisplay(board);
}

// remove cell from board
void removecell(char board[][size],int x, int y) {
	board[x][y] = ' ';
	boarddisplay(board);

}

// for checking bounds of the board
_Bool inbounds(char board[][size],int x, int y) {
	if ((board[x][y]==' ') || (board[x][y]=='x'))
		return true;
	else 
		return false;
}




// for making game go to the next iteration using the rules
void run(char board[][size],int xcord, int ycord) {
	char temp[size][size]; // used for holding
	for (int i=0;i<size;i++) {
		for (int j = 0;j<size;j++) {
			temp[i][j] = board[i][j]; // temp stores the board
		}
	}
	int count = 0;
	for (int i=0;i<size;i++) {
		for (int j = 0;j<size;j++) {
			count = 0; // set count to 0 for every cell
			if(inbounds(board,xcord,ycord)) {
				if(temp[i-1][j-1] == 'x')
					count++;
				if(temp[i-1][j] == 'x')
					count++;
				if(temp[i-1][j+1] == 'x')
					count++;
				if(temp[i][j-1] == 'x')
					count++;
				if(temp[i][j+1] == 'x')
					count++;
				if(temp[i+1][j-1] == 'x')
					count++;
				if(temp[i+1][j] == 'x')
					count++;
				if(temp[i+1][j+1] == 'x')
					count++;

			}
// now use above count to apply rules for if cell lives or dies

			if (count<2 || count>3)
				board[i][j] = ' ';//cell dies
			if (count==2)
				board[i][j] = temp[i][j]; // stays alive
			if (count==3)
				board[i][j] = 'x'; //cells come to life

		}
	}
}




