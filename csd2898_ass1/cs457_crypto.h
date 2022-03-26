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
        cipher[i] = text[i]  ^  3;
    }
    
    return cipher;
}

char* one_time_pad_decr(char  *cipher, char *key){
    int i;
    char *text;
    text = malloc(strlen(key) * sizeof(char));
    printf("%s\n", key);
    for ( i = 0; i < strlen(text); i++)
    {
        cipher[i] = 3 ^  cipher[i] ;
    }
            printf("Your Decrypted text is: %02x \n",cipher);   

    return cipher;
}
 
 char* rail_fence_encr(char plain[100] , int rail ){
     char fence[rail][1000];
     int  i,j;
     //rail making 
     i =0;
     while(1){
        if(i == 0){
            fence[0][0] = plain[i];
            j++;
        }else{
            fence[j][i] = plain[i];
        }
        if(j == rail){
            j=0;
        }
         i++;
     }
     for(int test = 0; test<rail; test++){
         printf("%s",fence[test]);
     }
     
 }

 char* rail_fence_decr(char* cihper, int rail){

 }