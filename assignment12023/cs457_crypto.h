#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifdef cs457_crypto_c
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN char* encryptionKey;

/**
Obe time pad Encryption uses a plaintext and its size as a number in order to create the cipher text by parsing the whole plain text and XOR-ing its letter of it with the plainSize
*/

const char*  one_time_pad_encr(char *plaintext, int plainSize, char **secretKey);
const char*  one_time_pad_decr(char *ciphertext, int plainSize, char **secretKey);
const char*  one_time_pad_encr_five(char *ciphertext, int plainSize, char **secretKey);
const char*  one_time_pad_dencr_five(char *ciphertext, int plainSize, char **secretKey);
const char* substitution_encr(char *plaintext, char *cipherAlphabet);
const char* substitution_decr(char *cipherText, char *cipherAlphabet);