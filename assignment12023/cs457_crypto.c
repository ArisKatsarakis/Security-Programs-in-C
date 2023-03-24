#define cs457_crypto_c
#include "cs457_crypto.h"

int main ( ) {
    printf("Encryption One Time Pad 1 \n");
    char* substitutionPlaintext = malloc(100*sizeof(char));
    char* substitutionCiphertext = malloc(100*sizeof(char));
    char*   cipherAlphabet  = malloc(100*sizeof(char));
    const char* substitutionEncryption, substitutionDecryption;
    const char* encryption = one_time_pad_encr("Testing", sizeof("Testing"), &encryptionKey);
    const char* decryption = one_time_pad_decr(encryption, sizeof("Testing"),&encryptionKey);
    const char* encryption2 = one_time_pad_encr_five("Testing", sizeof("Testing"), &encryptionKey);
    const char* decryption2 = one_time_pad_dencr_five(encryption2, sizeof("Testing"),&encryptionKey);
    printf("%s \n",encryption );
    printf("%s \n",decryption );
    printf("Encryption of a 5 charachter one time pad \n");
    printf("%s \n",encryption2 );
    printf("%s \n",decryption2 );
    printf("Substitution Encryption ! \n");
    scanf("%[^\n]%*c", substitutionPlaintext);
    printf("Substitution Encryption plaintext: %s \n", substitutionPlaintext);
    printf("Please provide the according cipher alphabet in order from a-z \n");
    scanf("%[^\n]%*c", cipherAlphabet);
    printf("Alphebet provided is %s \n", cipherAlphabet);

    substitutionEncryption = substitution_encr(substitutionPlaintext, cipherAlphabet);
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



/**
 * In order for us to have always the right created key, 
 * we need to first learn how many time the string fits in the Plaintext length and then add the remaining text by finding modulo between plainSize and 5 
*/

const char* one_time_pad_encr_five(char *plaintext, int plainSize, char** secretKey ) {
    int i =0;
    char* ciphertext;
    int sizeFitsFive = plainSize / 5;
    int sizeModFive = plainSize % 5; 
    ciphertext = malloc(plainSize * sizeof( char));
    *secretKey = malloc( 5  * sizeof(char));
    /**
     * We read the five random chars
    */
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd,  *secretKey, 5);
    //buffer now contains the random data
    close(fd);

    for(i =0; i < plainSize; i++)
       ciphertext[i] = (char) (plaintext[i])  ^ (char) (*(*secretKey +(i%5)));
    return ciphertext;
}

const char*  one_time_pad_dencr_five(char *ciphertext, int plainSize, char** secretKey) {

    int i =0;
    char* plaintext = malloc(plainSize * sizeof(char));
    for(i =0; i < plainSize; i++)
           plaintext[i] = (char) (ciphertext[i])  ^ (*(*secretKey +(i%5)));
    return plaintext;
}

const char* substitution_encr(char *plaintext, char *cipherAlphabet) {

}

const char* substitution_decr(char *cipherText, char *cipherAlphabet) {

}