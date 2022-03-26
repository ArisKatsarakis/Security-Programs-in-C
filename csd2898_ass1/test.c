#include "cs457_crypto.h"

int main(){
    char buffer;
    char plaintext[100], *cipher;
    int rail =0;
    int i=0 ;
     printf("Rail fence cipher \n");
        while(buffer == '\n'){
            buffer = getchar();
            if (buffer == '\n')
            {
                break;
                /* code */
            }else{
                plaintext[i] = buffer;
            }
            i++;
            
        }
        printf("Give rail number: \n");
        cipher = rail_fence_encr(plaintext, rail);
}