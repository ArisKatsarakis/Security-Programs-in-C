#include "cs457_crypto.h"

int main(){
    char buffer[100] = "AFFINECIPHER";
    char* cipher;
    char* plain;
    char key[100] = "LEMONLEMONLE";
    printf("Testing\n");
    printf("Plaintext : %s \n",buffer);
    cipher = affine_encr(buffer);
    printf("Cipher Text: %s \n", cipher);
    memset(buffer,0,100);
    plain = affine_decr(cipher  );
    printf("Decrypted: %s\n",plain);
}