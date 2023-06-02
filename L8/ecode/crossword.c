// crossword.c
// seth pickford
// Fundamentals of Computing lab 8


#include "crossfunc.h" 

int main(int argc, char *argv[]) {

// create array of structs
    Word words[maxwords];
// int for number of words input
    int count = 0; 
// our board
    char board[boardsize+2][boardsize+2];
// initilize board
    initboard(board);
// no files in command line
    if(argc == 1) {
        count = userinput(words);
    }
    else if(argc > 1) {
        count = readfile(argv[1], words);
    }
// -1 means file couldn't be found
    if((count == -1) && (argc==2 || argc ==3)) {
        printf("File not found");
        return 1;
    }
// too many inputs in command line
	if(argc > 3) {
        printf("Too many arguments\n");
        return 1;
    }

// convert the words to uppercase
    uppercase(words, count);
// sort the words by size
    sort(words, count);
//place the first word
    place(board, words, (boardsize-strlen(words[0].str))/2, boardsize/2, true, 0);
// bool is for second word has been placed or not
    bool placed2nd = false; 
    int i;
// loops to try other words if 2nd doesn't work
    for(int i = 1; i < count; i++) {
        if(second(board, words, i)) break;
    }
    i++;
// place rest of words
    placerest(board, words, i, count);

// loop and try to place words until can't. Stops once function is called and no more words can be placed but if a word was place then continue
    while(placeremaining(board, words, count)) {}
// if user didn't enter output file

    if(argc < 3) {
        printBoardsFile(stdout, board);
        printCluesFile(stdout, words, count);
    }

// if user did put output file
    else if(argc == 3) {
// connects file in write mode
        FILE *point = fopen(argv[2], "w");
// print data to outputfile
        printBoardsFile(point, board);
        printCluesFile(point, words, count);
    }
    return 0;
} 
