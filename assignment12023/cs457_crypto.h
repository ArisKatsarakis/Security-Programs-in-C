#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifdef cs457_crypto_c
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN int encryptionKey;
/**
 * printing hello world
*/

void printHelloWorld(void);
/**
Obe time pad Encryption uses a plaintext and its size as a number in order to create the cipher text by parsing the whole plain text and XOR-ing its letter of it with the plainSize
*/

const char*  one_time_pad_encr(char *plaintext, int plainSize, int *secretKey);

const char*  one_time_pad_denr(char *ciphertext, int plainSize, int *secretKey);