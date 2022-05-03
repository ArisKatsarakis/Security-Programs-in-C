#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char* argv[]){
    int pol_degree = 1;
    int a = (rand() % (atoi(argv[2])-1) );
    int secret;
    int b ;
    int c;
    int f_1,f_2;
    int x;
    printf("Secret Sharing in C \n");
    if(argc != 3){
        printf("Not enough arguments \n");
    }
    if (strcmp("split",argv[1]))
    {
        printf("Wrong Second Argument \n");
        /* code */
    }else{
        printf("Split Option Enabled \n");
        printf("%d \n",a);
        secret = atoi(argv[2]);
        //construct the polynomial 
        //pol_degree =2 
        x = 1;
        a = 14;
        b = 72;
        f_1 = a*pow(x,pol_degree) + b;

        printf("1 ,%d \n", f_1);
        x = 2; 
        a = 14;
        b = 72;
        f_2 = a*pow(x,pol_degree) + b;
        printf("2 ,%d \n", f_2);
        //solving the polynomial
    }
    
}