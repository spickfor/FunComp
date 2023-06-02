// statesfunc.h
// Seth Pickford
// Fundamentals of Computing - lab 7

// defining contants


// creation of a struct called State
typedef struct {
	char abbreviation[4];
	char name[20];
	char capital[20];
	int year;
} State;

// function prototypes
int table_input();
