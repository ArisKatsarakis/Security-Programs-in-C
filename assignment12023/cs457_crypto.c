#include "cs457_crypto.h"
int main ( ) {
    printHelloWorld();
    printf("%s \n", one_time_pad_encr("Testing", sizeof("Testing")));
    return 0;
    
}

void printHelloWorld( ) {
       printf("Hello World \n ");

}

char*  one_time_pad_encr(char *plaintext, int plainSize ) {
    return *plaintext;
}