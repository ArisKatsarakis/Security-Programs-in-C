 i = 0;
//     j = 0;
//     for (k = 0; k < rail; k++)
//     {
//         memset(fence[k], '_', strlen(plain) + 5);
//     }
//     printf("%d \n", strlen(plain));

//     for (i = 0; i < strlen(plain); i++)
//     {

//         if (i == 0)
//         {
//             fence[0][0] = plain[i];
//             j++;
//         }
//         else
//         {
//             while (j < rail)
//             {
//                 fence[j][i] = plain[i];
//                 j++;
//                 i++;
//             }
//             j = j - 2;
//             while (j >= 0)
//             {
//                 fence[j][i] = plain[i];
//                 j--;
//                 i++;
//             }
//             j = 1;
//             i--;
//         }
//     }

//     printf("\n");
//     for (i = 0; i < rail; i++)
//     {
//         printf("%s", fence[i]);
//         printf("\n");
//     }
//     i = 0;
//     j = 0;
//     l = 0;
//     // making the cipher
//     for (i = 0; i < rail; i++)
//     {
//         for (j = 0; j < strlen(plain) + 5; j++)
//         {
//             if (fence[i][j] != '_' && fence[i][j] != 0)
//             {
//                 cipher[l] = fence[i][j];
//                 l++;
//             }
//         }
//     }

//     return cipher;
// }

// char *rail_fence_decr(char *cipher, int rail)
// {
//     char fence[rail][strlen(cipher)];
//     char *plain = malloc(strlen(cipher) * sizeof(char));
//     int i, j, k, l;
//     for (i = 0; i < rail; i++)
//     {
//         memset(fence[i], 0, strlen(cipher));
       
//     }
//     i = 0;
//     k = 0;
//     j = 0;
//     while(j <strlen(cipher)){
//         if(k == 0){
//             fence[0][j] = cipher[i];
//             i++;
//             k++;
//             j++;
//         }else{
//             while(k < rail){
//                 fence[k][j] = '-';
//                 k++;
//                 j++;
//             }
//             k = k-2;
//             while(k > 0){
//                 fence[k][j] = '-';
//                 k--;
//                 j++;
//             }
            
//         }
//     }
//     l=0;
//     for(i = 0; i < rail; i++){
//         for ( j = 0; j < strlen(cipher); j++)
//         {
//             if(fence[i][j]== cipher[l] && i == 0){
//                 l++;
//             }else if(fence[i][j] == '-'){
//                 fence[i][j] = cipher[l];
//                 l++;
//             }
//         }
        
//     }
//     i = 0;
//     k = 0;
//     j = 0;
    
//     while (i < strlen(plain))
//     {
//         if(i== 0){
//             plain[i] = fence[0][0];
//             k++;
//             j++;
//             i++;
//         }else{
//             while(k<rail){
//                 plain[i] = fence[k][j];
//                 k++;
//                 j++;
//                 i++;
//             }
//             k--;
//             while(k<=0){
//                 plain[i] = fence[k][j];
//                 k--;
//                 j++;
//                 i++;
//             }
//             k=1;
//         }
        
//     }