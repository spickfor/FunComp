//lifefunc.h
// Seth Pickord
// Fundamentals of Computing - Lab 6

const int size;

void init(char board[][size]);
void boarddisplay(char board[][size]);
void addcell(char board[][size],int x,int y);
void removecell(char board[][size],int x, int y);
_Bool inbounds(char board[][size],int x, int y);
void run(char board[][size],int xcord,int ycord);
