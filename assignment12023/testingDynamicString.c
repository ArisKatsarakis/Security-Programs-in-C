#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()  {
	int i = 0;
	int plainSize = 15;
	
	for(i =0; i< plainSize ; i++) {
	
		printf("%d - ",i%5);
	}
	printf("\n");
}
