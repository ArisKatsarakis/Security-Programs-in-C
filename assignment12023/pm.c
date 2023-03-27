#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h> /* BasicInput/Output streams */

#include <openssl/err.h> /* errors */

#include <openssl/ssl.h> /* core library */

#define BUFFSIZE 1024
#define KEYLENGTH 32
#define IVLENGTH 16
void printExampleMessageS() {
    printf("Example for saving passwords. \n ");
    printf("pm save -f <path to password file> <website> <username> <password>\n");
    printf("Example for getting passwords. \n ");
    printf("pm get -f <path to password file> <website>\n" );
}



int main(int argc, char *argv[]) {
    char* masterPassword= "password";
    char* buffer= malloc( 100 * sizeof(char));
    FILE* destination;
    char* website;
    char* username;
    char* password;
    int iterations = 10;
    int len, ciphertext_len;
    unsigned char 
    if (argc == 1) {
        printf("No arguments given\n");
        printExampleMessageS();
    }
    if ( !strcmp(argv[1], "save") ) {
        printf("Saving procedure \n");
        printf("Give Password: ");
        scanf("%[^\n]*c", buffer);
        if ( !strcmp(masterPassword, buffer) ) {
            /**
             * Write in file
            */
           printf("Authentication Successful \n");
            if(!strcmp("-f", argv[2])) {
                 /**
                 * if file does not exist
                */
                destination = fopen(argv[3], "r");
                if (destination == NULL) {
                    fclose(destination);
                    destination = fopen(argv[3], "a+");
                    fprintf(destination,"website,username,password\n");
                }else{
                    fclose(destination);
                    destination = fopen(argv[3], "a+");
                }   
               
                if (destination == NULL) {
                    printf("An error happened while open the file %s \n", argv[3]);
                    return 0;
                }
               username = argv[5];
               website = argv[4];
               password = argv[6];
                
                fprintf(destination, "%s,%s,%s", website, username, password);
            }else{
                printf("Command %s does not exist \n",  argv[2]);
                return 0;
            }

        }else{
            /**
             * Authentication failed
            */
           printf("Authentication Failed \n Wrong password given \n");
        }
    }
    return 1;
}
