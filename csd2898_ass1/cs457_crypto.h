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
     char fence[rail][100];
     char* cipher = malloc(strlen(plain) * sizeof(char)) ;
     int  i,j,k,l;
     //rail making 
     i=0;
     j=0;
     for(k = 0; k<rail;k++){
        memset(fence[k],'_',strlen(plain)+5);
     }
     printf("%d \n",strlen(plain));
     
     for ( i = 0; i < strlen(plain);i++)
     {
        
         if(i == 0){
             fence[0][0] = plain[i];
             j++;
             
         }else{
            while(j< rail){
                fence[j][i] = plain[i];
                j++;
                i++;
            }
            j = j-2;
            while(j>=0){
                fence[j][i] = plain[i];
                j--;
                i++;
            }
             j=1;
             i--;
         }
     }
     
     printf("\n");
     for(i = 0; i< rail; i++){
         printf("%s", fence[i]);
         printf("\n");
     }
     i=0;
     j=0;
     l=0;
     //making the cipher
     for ( i = 0; i < rail; i++)
     {
         for ( j = 0; j < strlen(plain) + 5; j++)
         {
             if(fence[i][j] != '_' && fence[i][j] != 0){
                 cipher[l] = fence[i][j];
                 l++;
             }
         }
         
     }
     
     return cipher;
 }

 char* rail_fence_decr(char* cihper, int rail){

 }