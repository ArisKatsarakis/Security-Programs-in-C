#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printExampleMessageS() {
    printf("Example for saving passwords. \n ");
    printf("pm save -f <path to password file> <website> <username> <password>\n ");
    printf("Example for getting passwords. \n ");
    printf(" pm get -f <path to password file> <website>\n" );
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("No arguments given\n");
        printExampleMessageS();
    }
    return 1;
}
