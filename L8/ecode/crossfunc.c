// crossfunc.c
// seth pickford
// fundamentals of computing - lab 8

#include "crossfunc.h"   

// initialize the whole board with null characters
void initboard(char board[][boardsize+2]) {
 
// fors loop through the board and set everthing to null
    for(int i = 0; i < boardsize+2; i++) {
        for(int j = 0; j < boardsize+2; j++) {
            board[i][j] = '\0';
        }
    }
}

//AtoZ returns true if every char in a string is a letter
bool AtoZ(char str[], int len) {
    
    bool alphabetic = true;
    for(int i = 0; i < len; i++) {
// isalpha detects if char is alphabetic
        if(!isalpha(str[i])) {
            alphabetic = false;
        }
    }
    return alphabetic;
}

// reads words from user, function returns how many words there are
int userinput(Word words[]) {
    
    int count = 0;
    char input[wordsize];
    

	 while(1) {
        BEGIN:
        printf("Enter at most 20 words or put period to stop inputting: ");
        fgets(input, wordsize, stdin);
// check if new line was read
        char *point = strchr(input, '\n');
// if new line make that null char
        if(point != NULL) 
            *point = '\0';
// else for word too long
        else {
// clear out stdin
            while(fgetc(stdin) != '\n') {}
            printf("Word is too long. Try again.");
// go to start of while to start again
            goto BEGIN;
        }
// if user inputs period stop
        if(strcmp(input, ".") == 0) break;
// if there are non letter inputs
        if(!AtoZ(input, strlen(input))) {
            printf("Word contains characters other than letters. Try again.\n");
// go to start and prompt again
            goto BEGIN;    
        }
// if input word is too small
        if(strlen(input) < 2) {
            printf("Word is too short. Try again.");
            goto BEGIN;
        }

//define all values in the struct for the current word
        strcpy(words[count].str, input);
        words[count].placed = false;
        words[count].x = -1;
        words[count].y = -1;
        words[count].horiz = true;
        count++;
// if user has entered the maximum number of words allowed
        if(count > maxwords - 1) {
            printf("Max number of words entered.");
            break;
        }
    }
    return count;
}



//Takes filename  and then reads the data in the file into words[]
int readfile(char filename[], Word words[]) {

    FILE *fp = fopen(filename,"r");
    if(!fp) return -1;

    int count = 0;
    while(1) {
         if(count > 20) break;
         fscanf(fp,"%s",words[count].str);
         if(strcmp(words[count].str,".") == 0) {
             strcpy(words[count].str,"\0");
             break;
         }
         if(feof(fp)) break;
         count++;
     }
     return count;
}





// converts words to uppercase
void uppercase(Word words[],int count) {
    for(int i=0;i<count;i++) {
       for(int k = 0;k<strlen(words[i].str);k++) {
           words[i].str[k] = toupper(words[i].str[k]);
       }
    }
}




// sort large to smallest word
void sort(Word words[], int count) {

    bool sorted = true;
// temp for holding while switching values aroung
    char temp[wordsize];
    while(1) {
        sorted = true;
// for loops through all the words but the last
        for(int i = 0; i < count-1; i++) {
// if current word is shorter then the next word
            if(strlen(words[i].str) < strlen(words[i+1].str)) {
                strcpy(temp, words[i+1].str);           
                strcpy(words[i+1].str, words[i].str);
                strcpy(words[i].str, temp);
// sorted is set to false so that it loops again
                sorted = false;        
            }
        }
        if(sorted) break;
    }
}





// puts word in starting at given cord with a certain orientation
void place(char board[][boardsize+2], Word words[], int x, int y, bool horiz, int curr) {

// if not horizontal meaning word needs to be vertical
    if(!horiz) {
// loop through all the characters in current word
        for(int i = 0; i < strlen(words[curr].str); i++) {
            board[i+y+1][x+1] = words[curr].str[i]; 
        }
    }
// else for if word should be horizontal
    else {
// loop through chars
        for(int i = 0; i < strlen(words[curr].str); i++) {
            board[y+1][i+x+1] = words[curr].str[i]; 
        }
    }
//update the values of the struct
    words[curr].placed = true;
    words[curr].x = x;
    words[curr].y = y;
    words[curr].horiz = horiz;
}




// put 2nd word in puzzle since its simpler than rest
bool second(char board[][boardsize+2], Word words[], int curr) {

// loop through middle row
    for(int i = 0; i < boardsize; i++) {
// if char is letter      
        if(board[boardsize/2+1][i+1] != '\0') {
// loop through chars in current word
            for(int j = 0; j < strlen(words[curr].str); j++) {
// if same letter
                if(board[boardsize/2+1][i+1] == words[curr].str[j]) {
// if makes sure that word fits
                    if((j <= boardsize/2-1) && (strlen(words[curr].str)-(j+1) <= boardsize - boardsize/2-1)) {
                        place(board, words, i, boardsize/2-j, false, curr); 
// if word is placed return true
                        return true;
                    }
                }
            }
        }
    }
// return false if not placed
    return false; 
}



// checks if a given placement is valid and will not overwrite any already placed words
bool check(char board[][boardsize+2], Word word, int x, int y, bool horiz, int intersect) {
    
// safe to be placed
    bool safe = true;
// if word should be horizontal
    if(!horiz) {
// loop chars
        for(int i = 0; i < strlen(word.str); i++) {
// if checks there are no adjacent letters and it's not going to overwrite another char
            if(((board[i+y+1][x+1] != '\0') && (board[i+y+1][x+1] != word.str[i])) || ((board[i+y+1][x] != '\0') && (i != intersect)) || ((board[i+y+1][x+2] != '\0') && (i != intersect)) || ((i == 0) && (board[i+y][x+1] != '\0')) || ((i == strlen(word.str)-1) && (board[i+y+2][x+1]))) {
                safe = false;
            }
        }
    }
// for vertical word
    else {
        for(int i = 0; i < strlen(word.str); i++) {
            if(((board[y+1][i+x+1] != '\0') && (board[y+1][i+x+1] != word.str[i])) || ((board[y][i+x+1] != '\0') && (i != intersect)) || ((board[y+2][i+x+1] != '\0') && (i != intersect)) || ((i == 0) && (board[y+1][i+x] != '\0')) || ((i == strlen(word.str)-1) && (board[y+1][i+x+2]))) {
                safe = false;
            }
        }
    }
// return if its valid
    return safe;
}




// loop through rest of words and try to place
void placerest(char board[][boardsize+2], Word words[], int start, int count) {
    
    bool horiz = false;
// loop through however many words you have left
    for(int w = start; w < count; w++) {
// loop through rows        
        for(int i = 0; i < boardsize; i++) {
// loop through columns            
            for(int j = 0; j < boardsize; j++) {
// if location is letter                
                if(board[i+1][j+1] != '\0') {
// if chars above/below null meaning word is horizontal
                    if((board[i][j+1] == '\0') && (board[i+2][j+1] == '\0')) {
// set horiz to false since word shouuld be put veritcally
                        horiz = false;
// loop through chars in word
                        for(int c = 0; c < strlen(words[w].str); c++) {
// if chars match between word and board                            
                            if(board[i+1][j+1] == words[w].str[c]) {
// make sure there is room to put word
                                if((c <= i) && (strlen(words[w].str)-(c+1) <= boardsize - (i+1))) {
// if to verify conditions 
                                    if(check(board, words[w], j, i-c, horiz, c)) {
                                        place(board, words, j, i-c, horiz, w);
// goto used to get out of all the loops since break only breaks one loop
                                        goto ESCAPE;
                                    }
                                }
                            }
                        }
                    }
// if chars to the sides are null meaning its a vertical word
                    if((board[i+1][j] == '\0') && (board[i+1][j+2] == '\0')){        
// place word horizontal
                        horiz = true;
// loop the chars
                        for(int c = 0; c < strlen(words[w].str); c++) {   
// if chars match                         
                            if(board[i+1][j+1] == words[w].str[c]) {
// if room to place word
                                if((c <= j) && (strlen(words[w].str)-(c+1) <= boardsize - (j+1))) {
// verify conditions
                                    if(check(board, words[w], j-c, i, horiz, c)) {
                                        place(board, words, j-c, i, horiz, w);
// goto to escape the loops
                                        goto ESCAPE;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("Couldn't place %s on first pass\n", words[w].str);
// where the goto escapes to
        ESCAPE:;
    }
}



// same as above, but only checks the words who haven't been placed. Returns if any words were placed
bool placeremaining(char board[][boardsize+2], Word words[], int count) {
    bool wordsplaced = false;
    bool horiz = false;
// loop words in array of structs
    for(int w = 0; w < count; w++) {
// if the word hasn't been placed
        if(!words[w].placed) {        
            for(int i = 0; i < boardsize; i++) {            
                for(int j = 0; j < boardsize; j++) {                
                    if(board[i+1][j+1] != '\0') {
                        if((board[i][j+1] == '\0') && (board[i+2][j+1] == '\0')) {
                            horiz = false;
                            for(int c = 0; c < strlen(words[w].str); c++) { 
                                if(board[i+1][j+1] == words[w].str[c]) {
                                    if((c <= i) && (strlen(words[w].str)-(c+1) <= boardsize - (i+1))) {
                                        if(check(board, words[w], j, i-c, horiz, c)) {
                                            place(board, words, j, i-c, horiz, w);
                                            wordsplaced = true;
                                            goto EXIT;
                                        }
                                    }
                                }
                            }
                        }
                        if((board[i+1][j] == '\0') && (board[i+1][j+2] == '\0')) {
                            horiz = true;
                            for(int c = 0; c < strlen(words[w].str); c++) {
                                if(board[i+1][j+1] == words[w].str[c]) {
                                    if((c <= j) && (strlen(words[w].str)-(c+1) <= boardsize - (j+1))) {
                                        if(check(board, words[w], j-c, i, horiz, c)) {
                                            place(board, words, j-c, i, horiz, w);
                                            wordsplaced = true;
                                            goto EXIT;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            EXIT:;
        }
    }
// return if any new words were placed
    return wordsplaced; 
}




// prints the boards for user or to outputfile
void printBoardsFile(FILE *point, char board[][boardsize+2]) {

//Solution Board
    fprintf(point, "\nSolution:\n");  
// loop through board
    for(int irow = 0; irow < boardsize+2; irow++) {
        for(int jcol = 0; jcol < boardsize+2; jcol++) {
// if top or bottom edge of board
            if((irow == 0) ||  (irow == boardsize+1)) {
                fprintf(point, "- ");
            }
// if on sides
            else if((jcol == 0) || (jcol == boardsize+1)) {
                fprintf(point, "|");
            }
// if spot isn't boarder spot or letter
            else if(board[irow][jcol] == '\0') {
                fprintf(point, ". ");
            }
// spot is letter
            else   {
                fprintf(point, "%c ", board[irow][jcol]); 
            }
// if end of row, new row
            if(jcol == boardsize+1) {
                fprintf(point, "\n");
            }
        }
    }

//Puzzle Board
    fprintf(point, "\nCrossword Puzzle:\n");
    for(int irow = 0; irow < boardsize+2; irow++) {
        for(int jcol = 0; jcol < boardsize+2; jcol++) {
            if((irow == 0) ||  (irow == boardsize+1)) {
                fprintf(point, "- ");
            }
            else if((jcol == 0) || (jcol == boardsize+1)) {
                fprintf(point, "|");
            }
// if not letter
            else if(board[irow][jcol] == '\0') {
                fprintf(point, "# ");
            }
// is letter
            else {
                fprintf(point, "  ");
            }
            if(jcol == boardsize+1) {
                fprintf(point, "\n");
            }
        }
    }
}




// print the clue table with start cords, direction,scrambled word, words that couldnt be placed
void printCluesFile(FILE *point, Word words[], int count) {
    fprintf(point, "\nClues:\n");
    fprintf(point, " Location | Orientation | Scramble\n");
    fprintf(point, "----------------------------------\n");
    char temp[15];
// loop the words
    for(int i = 0; i < count; i++) {
// if word has been placed
        if(words[i].placed) {
            strcpy(temp, words[i].str); 
// strfry scambles
            strfry(temp);
            fprintf(point, "%5d, %2d |", words[i].x, words[i].y); 
// if to print if word is horizontal or vertical
            if(words[i].horiz) {
                fprintf(point, "    Across | ");
            }
            else {
                fprintf(point, "      Down | ");
            }
// prints scrambled word as clue
            fprintf(point, "%s\n", temp);
        }
    }
    fprintf(point, "\nThese words weren't able to be placed:\n");
// loops words
    for(int i = 0; i < count; i++) {
// if word wasn't placed
        if(!words[i].placed) {
            fprintf(point, "%s\n", words[i].str);
        }
    }
}




