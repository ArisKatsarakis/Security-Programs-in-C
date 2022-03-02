#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *read, *write;
    int i , k,len;
    char buffer[1000];

    read = fopen("dbb4fdbba0f4bb8b441c1d610260bbc8.VBR","r");
    if(read == NULL){
        printf("Failed to read the VBR \n");
        return 0;
    }
    fseek(read, 0, SEEK_END);
    len = ftell(read);
    printf("Size of VBR %d \n", len);
    
}