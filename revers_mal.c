#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *read, *write;
    int i , k,len;
    char *buffer;
    char *decode;

    read = fopen("dbb4fdbba0f4bb8b441c1d610260bbc8.VBR","r");
    if(read == NULL){
        printf("Failed to read the VBR \n");
        return 0;
    }
    fseek(read, 0, SEEK_END);
    len = ftell(read);
    printf("Size of VBR %d \n", len);
    buffer = malloc(len * sizeof(char));
    fseek(read,0,SEEK_SET);
    fread(buffer, len , 1 , read);
    printf("The encrypted content is: \n %s \n",buffer);
    for (int i = 0; i < len; i++)
    {
        buffer[i] = buffer[i] ^ 0x24;
        buffer[i] = buffer[i] + 4;
        if(buffer[i] == '\n'){
            if (buffer[i+1] == '\n')
            {
                decode = malloc(i * sizeof(char));
                memcpy(decode,buffer,i);
                break;
            }
            
        }
    }
    printf("\nThe  content  after decryption is: \n %s \n",decode);
    
}