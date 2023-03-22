#define cs457_crypto_c
#include "cs457_crypto.h"
void createRandomData() {
            int i;
            unsigned int buffer[8];
            int fd = open("/dev/urandom", O_RDONLY);
            read(fd, buffer, 8);
            //buffer now contains the random data
            close(fd);
            for(i = 0; i < 1; ++i)
                    printf("%02X", buffer[i]);
            printf("\n");
            printf("%d \n",buffer[0]);
}
int main ( ) {
    printHelloWorld();
    const char* encryption = one_time_pad_encr("Testing", sizeof("Testing"), &encryptionKey);
    const char* decryption = one_time_pad_denr(&encryption, sizeof("Testing"),&encryptionKey);
    printf("%s \n",encryption );
    printf("%s \n",decryption );
    return 0;
    
}

void printHelloWorld( ) {
       printf("Hello World \n ");
}



const char* one_time_pad_encr(char *plaintext, int plainSize, int *secretKey ) {
    int i =0;
    char* ciphertext;
    ciphertext = malloc(plainSize * sizeof( char));
    *secretKey = rand();
    for(i =0; i < plainSize; i++)
       ciphertext[i] = (char) (plaintext[i] ^ 'x');
    return ciphertext;
}

const char*  one_time_pad_denr(char *ciphertext, int plainSize, int *secretKey) {

    int i =0;
    char* plaintext = malloc(plainSize * sizeof(char));
    for(i =0; i < plainSize; i++)
           plaintext[i] = (char) (ciphertext[i] ^ 'x');
    return plaintext;
}
