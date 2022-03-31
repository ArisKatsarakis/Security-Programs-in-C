#include "cs457_crypto.h"

int main(int argc, char* argv[])
{
    char* buffer;
    char *cipher, *new_text;
    char* plaintext;
    char* key;
    int val = 0;
    int rail;
    int i;

    if(argc != 2){
      printf("Give Arguments \n");
      return 0;
    }else{
        plaintext = malloc(strlen(argv[1]) * sizeof(char));
        plaintext = argv[1];
        printf("Message for Encryption:  %s \n",plaintext);
    }
    printf("CS 457 Crypto Machine: \n");
    printf("Give Encoding Type: \n");
    printf("1) One Time Pad \n");
    printf("2) Rail fence cipher \n");
    printf("3) Beaufort cipher \n");
    printf("4) Affine cipher \n");
    printf("other) Exit cipher \n");
    scanf("%d", &val);

    switch (val)
    {
    case 1:
        printf("One time Pad  \n");
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
        printf("Give rail number: \n");
        scanf("%d",&rail);
        cipher = rail_fence_encr(plaintext, rail);
        buffer = rail_fence_decr(cipher,rail);
        printf("Encrypt: %s\n Decrypt: %s\n",cipher,buffer);
        break;
    case 3:
        printf("Beaufort_encryption: \n");
        printf("Give key same size as plain: \n");
        key = malloc(strlen(plaintext) * sizeof(char));
            printf("Give key: \n");
            scanf("%s",key);
        
        cipher = beaufort_encr(plaintext,key);
        buffer = beaufort_decr(cipher,key);
        printf("Encrypt: %s\n Decrypt: %s\n",cipher,buffer);
        break;
    case 4:
        printf("Affine Encryption: \n");
        cipher = affine_encr(plaintext);
        buffer = affine_decr(cipher);
        printf("Encrypt: %s\n Decrypt: %s\n",cipher,buffer);
        break;
    default:
        printf("Exiting \n");
        break;
    }
}