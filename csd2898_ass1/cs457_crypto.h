#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char* one_time_pad_encr(char *text, char *key){
    int i;
    char *cipher;
    cipher = malloc(strlen(text) * sizeof(char));
    printf("Encoding.......... \n");
    for ( i = 0; i < strlen(text); i++)
    {
        cipher[i] = (char)(text[i] ^ key[i]);
    }
    return cipher;
}

char* one_time_pad_decr(char *cipher, char *key){
    int i;
    char *text;
    text = malloc(strlen(key) * sizeof(char));
    for ( i = 0; i < strlen(text); i++)
    {
        text[i] = (char)(cipher[i] ^ key[i]);
    }
    return text;
}