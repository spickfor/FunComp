// for question 3 of the practice exam

#include <stdio.h>
#include <stdbool.h>

// prototype for the function the problem wants
bool incommon_p(char *p1, char *p2); 

int main() {

	char *p1;
	char *p2;
	p1 = "donkey";
	p2 = "monkey";

	incommon_p(p1,p2);


	return 0;
}


// actual function
bool incommon_p(char *p1, char *p2) {

// sets p2 to a holder so it can be set back to that later
	char *p2start = p2;

	while(*p1 != '\0') {
		p2 = p2start;
		while(*p2 != '\0') {
			if(*p1 == *p2) {
				return true;
			}
		p2++;
		}
	p1++;
	}
return false;

}
