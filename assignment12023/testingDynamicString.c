#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()  {
	char* theString = "This";
	char* placeInString = strchr(theString,'T');
	printf("The place of the char is %d \n",(int){placeInString - theString});
	return 0;

}
