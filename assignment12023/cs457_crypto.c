#include "cs457_crypto.h"
int main ( ) {
    printHelloWorld();
    char  *encryption = one_time_pad_encr("Testing", sizeof("Testing"));
    printf("%s \n",encryption );
    return 0;
    
}

void printHelloWorld( ) {
       printf("Hello World \n ");

}
const char* one_time_pad_encr(char *plaintext, int plainSize ) {
    return *plaintext;
}