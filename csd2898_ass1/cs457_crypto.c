#include "cs457_crypto.h"

int main()
{
    char buffer;
    char *cipher, *new_text;
    char plaintext[100];
    char key[100];
    int val = 0;
    int rail;
    int i;


    printf("CS 457 Crypto Machine: \n");
    printf("Give Encoding Type: \n");
    printf("1) One Time Pad \n");
    printf("2) Rail fence cipher \n");
    scanf("%d", &val);

    switch (val)
    {
    case 1:
        printf("One time Pad  \n");
        printf("Give us your text: \n");
        while (1)
        {
            printf("Give us the preshared key: \n");
            scanf("%s", key);
            if (strlen(plaintext) == strlen(key))
                break;
            /* key - size test */
        }
        memcpy(cipher, one_time_pad_encr(plaintext, key), strlen(one_time_pad_encr(plaintext, key)));
        printf("Your Cipher text is: %02x \n", cipher);
        new_text = malloc(strlen(cipher) * sizeof(char));
        new_text = one_time_pad_decr(&cipher, key);
        printf("Your Decrypted text is: %s \n", cipher);

        break;
    case 2:
        printf("Rail fence cipher \n");
        printf("Give us your text: \n");
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
        break;
    default:
        printf("Exiting \n");
        break;
    }
}