#include "cs457_crypto.h"

int main(){
    char buffer[100] = "hello world";
    char* cipher;
    printf("Testing\n");
    printf("Plaintext : %s \n",buffer);
    cipher = rail_fence_encr(buffer,3);
    printf("Cipher Text: %s \n", cipher);

}