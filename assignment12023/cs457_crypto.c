#define cs457_crypto_c
#include "cs457_crypto.h"
void createRandomData() {
            int i;
            char buffer[8];
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
    printf("Encryption One Time Pad 1 \n");
    const char* encryption = one_time_pad_encr("Testing", sizeof("Testing"), &encryptionKey);
    const char* decryption = one_time_pad_decr(encryption, sizeof("Testing"),&encryptionKey);
    const char* encryption2 = one_time_pad_encr2("Testing", sizeof("Testing"), &encryptionKey);
    const char* decryption2 = one_time_pad_decr2(encryption, sizeof("Testing"),&encryptionKey);
    printf("%s \n",encryption );
    printf("%s \n",decryption );
    printf("Encryption of a 5 charachter one time pad \n");
    printf("%s \n",encryption2 );
    printf("%s \n",decryption2 );
    return 0;
    
}





const char* one_time_pad_encr(char *plaintext, int plainSize, char** secretKey ) {
    int i =0;
    char* ciphertext;
    ciphertext = malloc(plainSize * sizeof( char));
    *secretKey = malloc( plainSize  * sizeof(char));
    // *secretKey = "CloneMe";
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd,  *secretKey, plainSize);
    //buffer now contains the random data
    close(fd);
    for(i =0; i < plainSize; i++)
       ciphertext[i] = (char) (plaintext[i])  ^ (char) (*(*secretKey +i));
    return ciphertext;
}

const char*  one_time_pad_decr(char *ciphertext, int plainSize, char** secretKey) {

    int i =0;
    char* plaintext = malloc(plainSize * sizeof(char));
    for(i =0; i < plainSize; i++)
           plaintext[i] = (char) (ciphertext[i])  ^ (*(*secretKey +i));
    return plaintext;
}





const char* one_time_pad_encr2(char *plaintext, int plainSize, char** secretKey ) {
    int i =0;
    char* ciphertext;
    ciphertext = malloc(plainSize * sizeof( char));
    *secretKey = malloc( plainSize  * sizeof(char));
    // *secretKey = "CloneMe";
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd,  *secretKey, 5);
    //buffer now contains the random data
    close(fd);
    for( i = 5; i < plainSize; i++ ) {
        
    }
    for(i =0; i < plainSize; i++)
       ciphertext[i] = (char) (plaintext[i])  ^ (char) (*(*secretKey +i));
    return ciphertext;
}

const char*  one_time_pad_decr2(char *ciphertext, int plainSize, char** secretKey) {

    int i =0;
    char* plaintext = malloc(plainSize * sizeof(char));
    for(i =0; i < plainSize; i++)
           plaintext[i] = (char) (ciphertext[i])  ^ (*(*secretKey +i));
    return plaintext;
}