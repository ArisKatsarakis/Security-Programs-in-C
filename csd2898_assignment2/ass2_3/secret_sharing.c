#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// make a and b to be randoms
// show how to find C in any 3 given points
void get_num(char *buffer);
int f_1, f_2, f_3;
int main(int argc, char *argv[])
{
    int pol_degree = 1;
    int a = 5;
    int secret = atoi(argv[2]);
    int b = 2;
    int c;
    int i;
    int points[3];
    int x;
    printf("Secret Sharing in C \n");
    if (argc != 3)
    {
        printf("Not enough arguments \n");
    }
    if (!strcmp("split", argv[1]))
    {

        printf("Split Option Enabled \n");
        printf("%d \n", a);
        f_1 = a * pow(1, 2) + b + secret;
        f_2 = a * pow(2, 2) + 2 * b + secret;
        f_3 = a * pow(3, 2) + 3 * b + secret;
        printf("(1,%d,2,%d,3,%d)\n", f_1, f_2, f_3);
    }
    else if (!strcmp("join", argv[1]))
    {
        char *buffer[100];
        printf("Join Option Enabled \n");
        printf("%s \n", argv[2]);
        // parse argv[2]
        get_num(argv[2]);
        // parse the command of ./secret_sharing
         c = f_3 + 3* f_1 - 3  * f_2;
         printf("Secret is %d \n",c);
    }
    else
    {
        printf("Wrong Second Argument \n");
        return 1;
    }
    return 0;
}
void get_num(char *buffer)
{
    char temp[10];
    int i, k, j;
    int f[6];
    printf("getting nums \n");
    k = 0;
    j = 0;

    for (i = 0; i < 3 * sizeof(buffer); i++)
    {
        if (buffer[i] == ',' || buffer[i] == 0)
        {
            f[j] = atoi(temp);
            memset(temp, 0, 10);
            j++;
            k = 0;
        }else{
            temp[k] = buffer[i];
            k++;
        }
        if(j == 6 ) break;
    }
    // for (j = 0; j < 6; j++)
    // {
    //     printf("f[%d] = %d\n", j, f[j]);
    // }
    f_1 = f[1];
    f_2 = f[3];
    f_3 = f[5];
 }