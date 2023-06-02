// crossfunc.c
// Seth Pickford
// Fundamentals of Computing - Lab 8

#include "crossfunc.h"

void initanswerboard(char board[boardsize+2][boardsize+2]) {

	for (int i = 0; i<boardsize+2; i++) {
		for (int k = 0; k<boardsize+2;k++) {
			board[i][k] = '.';
		}
	}
}


void initpuzzleboard(char board[boardsize+2][boardsize+2]) {
	
	for (int i = 0; i<boardsize+2; i++) {
		for (int k = 0; k<boardsize+2;k++) {
			board[i][k] = '#';
		}
	}
}


void displayboard(char board[boardsize+2][boardsize+2]) {

	for (int i = 0; i<boardsize+2; i++) {
		for (int k = 0; k<boardsize+2;k++) {

			if((i==0) || (i == boardsize+1)) {
				printf("-");
			}
			else if ((k==0) || (k == boardsize+1)) {
				printf("|");
			}
			else {
				printf("%c",board[i][k]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

// figures out if all the parts of string are letters and returns true if they are
bool AtoZ(char word[wordsize],int size) {

	bool hold = false;
	for(int i = 0; i < size; i++) {
		if(isalpha(word[i])) {
			hold = true;
		}
		else {
			hold = false;
		}
	}
	return hold;
}

// for converting each word to uppercase
void uppercase(Word words[],int size) {
	
	int i = 0;
	for(int k = 0;k<size;k++) {
		for(int i = 0; i < strlen(words[k].string);i++) {
			words[k].string[i] = toupper(words[k].string[i]);
		}
	}
}


// for sorting words from largest to the smallest
void sort(Word words[],int size) {

//temporary variable for holding while switching
	char tmp[wordsize];
	int i;
	bool complete = true;
	while(1) {
		complete = true;
		for(i = 0;i < size-1;i++) {
			if(strlen(words[i].string) < strlen(words[i+1].string)) {
				strcpy(tmp,words[i+1].string);
				strcpy(words[i+1].string,words[i].string);
				strcpy(words[i].string,tmp);
				complete = false;
			}
		}
		if(complete) break;
	}
}


// for reading in the file and storing it as well as returns num words
int inputfile(char filename[],Word words[]) {
	FILE *fp = fopen(filename,"r");
	if (!fp) return -1;
	
	int count = 0;
	while(1) {
		if(count > 20) break;
		fscanf(fp,"%s",words[count].string);
		if(strcmp(words[count].string,".")==0) {
			strcpy(words[count].string,"\0");
			break;
		}
		if(feof(fp)) break;
		count++;
	}	
	return count;
}



// for placing the words on the board
// takes the struct, board, current number of word, bool for whether to put horizon
// ints for location
void place(Word words[],char board[][boardsize+2],int current, bool horizontal,int x, int y) {

	if(!horizontal) {
		for(int i = 0;i < strlen(words[current].string); i++) {
			board[i+y+1][x+1] = words[current].string[i];
		}
	}
	else {
		for(int i = 0;i < strlen(words[current].string); i++) {
			board[y+1][i+x+1] = words[current].string[i];
		}
	}
// update the struct
	words[current].placed = true;
}

// for placing second word since it isn't as complicated as the rest
bool placesecond(Word words[],char board[][boardsize+2],int current) {
	
	for(int i = 0; i < boardsize; i++) {
		if(board[boardsize/2+1][i+1] != '.') {
			for(int j = 0; j < strlen(words[current].string); j++) {
				if(board[boardsize/2+1][i+1] == words[current].string[j]) {
					if((j <= boardsize/2-1) && (strlen(words[current].string)-(j+1) <= boardsize - boardsize/2-1)) {
						place(words,board,current,false, i, boardsize/2-j);
						words[1].placed = true;
						return 1;
					}
				}
			}
		}
	}	
	words[1].placed = false;
	return false;
}

/*
// check if all the conditions are met
bool check(char board[][boardsize+2],Word word,int x,int y,bool horizontal, int intersect) {
	
// bool for holding whether it checks out or not
	bool checks = true;

	if(!horizontal) {
		for(int i = 0; i < strlen(word.string);i++) {
			if(((board[i+y+1][x+1] != '.') && (board[i+y+1][x+1] != word.string[i])) || ((board[i+y+1][x] != '.') && (i != intersect)) || ((board[i+y+1][x+2] != '.') && (i != intersect)) || ((i == 0) && (board[i+y][x+1] != '.')) || ((i == strlen(word.string)-1) && (board[i+y+2][x+1]))) {
				checks = false;
			}
		}
	}
	else {
		for(int i = 0; i < strlen(word.string);i++) {
			if(((board[y+1][i+x+1] != '.') && (board[y+1][i+x+1] != word.string[i])) || ((board[y][i+x+1] != '.') && (i != intersect)) || ((board[y+2][i+x+1] != '.') && (i != intersect)) || ((i == 0) && (board[y+1][i+x] != '.')) || ((i == strlen(word.string)-1) && (board[y+1][i+x+2]))) {
				checks = false;
			}
		}
	}
// returns whether it can be placed and not violoate rules
	return checks;
}




// for placing all the words after the first and second starting at position start and going through number of words
void placenext(char board[][boardsize+2],Word words[],int start, int wordcount) {

// boolean for if it should be placed horizontal or not
	bool horizontal = false;
// for to go through all the words
	for(int w = start; w < numwords; w++) {
// for to loop the rows
		for(int i = 0; i < boardsize; i++) {
// for to loop the columns
			for(int j = 0; j < boardsize; j++) {
// if current location isn't a period
				if(board[i+1][j+1] != '.') {
// if above and below are periods meaning the word the char is in is horizontal
					if((board[i][j+1] == '.') && (board[i+2][j+1] == '.')) {
						horizontal = false;
// for to loop through current word
						for(int c = 0; c < strlen(words[i].string); c++) {
// if to detect if char in current word matches char on board
							if(board[i+1][j+1] == words[w].string[c]) {
// if to figure out if there is room on the board
								if((c <= i) && (strlen(words[w].string)-(c+1) <= boardsize - (i+1))) {
									if(check(board,words[w], j, i-c, horizontal, c)) {
										place(words,board, w,horizontal,j-c,i);
// goto used to escape all the nested loops.  Takes me to ESCAPE
										goto ESCAPE;
									}
								}
							}
						}
					}
// if chars to either side are periods meaning vertical word
					if((board[i+1][j] == '.') && (board[i+1][j+2] == '.')) {
						horizontal = true;
// for to loop through current word
						for(int c = 0; c < strlen(words[w].string); c++) {
// if checks if the word char matches the char on the board
							if(board[i+1][j+1] == words[w].string[c]) {
// if makes sure there is room on the board
								if((c <= j) && (strlen(words[w].string)-(c+1) <= boardsize - (j+1))) {
// use check to check the rules
									if(check(board,words[w], j-c, i, horizontal, c)) {
										place(words,board, w,horizontal,j-c,i);
										goto ESCAPE;
									}
								}
							}
						}
					}
				}
			}
		}
			printf("Couldn't place %s\n",words[w].string);
// where goto escapes to
			ESCAPE:;
		
	}
}
*/





bool check(char board[][boardsize+2], Word word, int x, int y, bool horizontal, int intersect)
{
    //puts("checkplace");
    int i;
    bool safe = true;
    if(!horizontal)  //if the word is to be placed horizontally
    {
        for(i = 0; i < strlen(word.string); i++)   //loop through the word
        {
            //checks that it does not overwrite any characters unless it is a proper interection, and that there are no letters surrounding the word
            //as one word should not be placed directly adjacent to any characters of another word
            if(((board[i+y+1][x+1] != '\0') && (board[i+y+1][x+1] != word.string[i])) || ((board[i+y+1][x] != '\0') && (i != intersect)) || ((board[i+y+1][x+2] != '\0') && (i != intersect)) || ((i == 0) && (board[i+y][x+1] != '\0')) || ((i == strlen(word.string)-1) && (board[i+y+2][x+1])))
                safe = false;
        }
    }
    else    //if the word is to be place vertically, do the same as above but in the other orientation
    {
        for(i = 0; i < strlen(word.string); i++)
        {
            if(((board[y+1][i+x+1] != '\0') && (board[y+1][i+x+1] != word.string[i])) || ((board[y][i+x+1] != '\0') && (i != intersect)) || ((board[y+2][i+x+1] != '\0') && (i != intersect)) || ((i == 0) && (board[y+1][i+x] != '\0')) || ((i == strlen(word.string)-1) && (board[y+1][i+x+2])))
                safe = false;
        }
    }
    return safe;    //return whether or not it is a safe placement
}

//placerest will loop through the rest of the Words in words[] and attempt to place them all
void placenext(char board[][boardsize+2], Word words[], int start, int wordcount)
{
    //puts("placerest");
    int w, i, j, c;
    bool horiz = false;
    for(w = start; w < wordcount; w++)   //loop through every remaining word
    {        
        for(i = 0; i < boardsize; i++)  //loop through the rows of board
        {            
            for(j = 0; j < boardsize; j++)  //loop through the cols of board
            {                
                if(board[i+1][j+1] != '.') //if the current location in board is not a null character
                {
                    if((board[i][j+1] == '.') && (board[i+2][j+1] == '.'))    //and the chars above and below are null 
                    {                                                           //meaning the char is part of a horizontally placed word
                        horiz = false;  //the word should be placed vertically
                        for(c = 0; c < strlen(words[w].string); c++)   //loop through the chars in the current word
                        {                            
                            if(board[i+1][j+1] == words[w].string[c])  //if a character in the current word matches the current character on the board
                            {
                                if((c <= i) && (strlen(words[w].string)-(c+1) <= boardsize - (i+1)))   //check that there is room for the word
                                {
                                    if(check(board, words[w], j, i-c, horiz, c))   //checkplace() to check other conditions
                                    {
                                        place(words,board, w,horiz, j, i-c);  //if conditions are met, place the word

                                        goto NEXTWORD;  //and jump to NEXTWORD in order to break  out of all the loops
                                    }
                                }
                            }
                        }
                    }
                    if((board[i+1][j] == '.') && (board[i+1][j+2] == '.'))    //if the chars to the left and the right are null
                    {                                                           //meaning the char is part of a vertically placed word
                        horiz = true;   //the word should be place horizontally
                        for(c = 0; c < strlen(words[w].string); c++)   //same as in vertical case but in opposite orientation
                        {                            
                            if(board[i+1][j+1] == words[w].string[c])
                            {
                                if((c <= j) && (strlen(words[w].string)-(c+1) <= boardsize - (j+1)))
                                {
                                    if(check(board, words[w], j-c, i, horiz, c))
                                    {
                                        place(words,board,w,horiz, j-c, i);

                                        goto NEXTWORD;
                                    }
								}
                            }
                        }
                    }
                }
            }
        }

        printf("Could not place %s on first pass\n", words[w].string); //if a word could not be placed on the first pass, print so
        NEXTWORD:;
    }
}



bool tryagain(char board[][boardsize+2], Word words[], int numWords)
{
    bool wordsplaced = false;
    int w, i, j, c;
    bool horiz = false;
    for(w = 0; w < numWords; w++)   //for every Word in words[]
    {
        if(!words[w].placed)    //if the word has not been placed, do the same as in placerest()
        {        
            for(i = 0; i < boardsize; i++)
            {            
                for(j = 0; j < boardsize; j++)
                {                
                    if(board[i+1][j+1] != '.')
                    {
                        if((board[i][j+1] == '.') && (board[i+2][j+1] == '.'))
                        {
                            horiz = false;
                            for(c = 0; c < strlen(words[w].string); c++)
                            {                            if(board[i+1][j+1] == words[w].string[c])
                                {
                                    if((c <= i) && (strlen(words[w].string)-(c+1) <= boardsize - (i+1)))
                                    {
                                        if(check(board, words[w], j, i-c, horiz, c))
                                        {
                                            place(words,board,w,horiz, j, i-c);
                                            wordsplaced = true;
                                            goto NEXTWORD2;
                                        }
                                    }
                                }
                            }
                        }
                        if((board[i+1][j] == '\0') && (board[i+1][j+2] == '\0'))
                        {
                            horiz = true;
                            for(c = 0; c < strlen(words[w].string); c++)
                            {                            if(board[i+1][j+1] == words[w].string[c])
                                {
                                    if((c <= j) && (strlen(words[w].string)-(c+1) <= boardsize - (j+1)))
                                    {
                                        if(check(board, words[w], j-c, i, horiz, c))
                                        {
                                            place(words,board,w,horiz, j-c, i);
                                            wordsplaced = true;
                                            goto NEXTWORD2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            NEXTWORD2:;
        }
    }
    return wordsplaced; //return whether or not any new words were placed on this pass
}

