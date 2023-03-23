#include <stdlib.h>
#include <stdio.h>

int main()  {
	char *myString = "myString"; 
 	int size = 3 * sizeof(myString);
	int i = 0;
	printf("Size of string x 3 = %d \n", size);
	char* newArray = malloc(size * sizeof(char));
	for(i =0; i < size; i++) {
	
	}
}
